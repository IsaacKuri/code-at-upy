#include <Arduino.h>
#include<DHTesp.h>
#include <WiFi.h>
#include <Wire.h>
#include <PubSubClient.h>
#include <oled_utils.h>
// Network Data
const char* ssid = "MENDOZA_NTW_INV";
const char* password = "s1rv4s3ust3d";
//HiveMQ Free Broker
const char* mqtt_server = "broker.hivemq.com";
#define mqtt_port 1883

//Topics
//Topic for data "/iot-kuri/data"
#define MQTT_SERIAL_RECEIVER_CH "/iot-kuri/control"

//Object Declarations
WiFiClient wifiClient;
PubSubClient client(wifiClient);

//Global
long lastMsg = 0;
float dht11_temp = 0;
float dht11_humi = 0;
float dht11_temp_txt = 0;
float dht11_humi_txt = 0;
float ground_humi = 0;
float ground_humi_txt = 0;
float tank_state = false;
String tank_state_txt = "EMPTY";

//Pin definitions for the shield
#define DHT_PIN 4
#define RELAY_1 19
#define RELAY_2 18
#define ADC_1 32
#define ADC_2 35
#define DIGP_1 5
#define DIGP_2 17
#define DIGP_3 16

//Sensor Initializations
DHTesp dht;
//Constructors
void setup_wifi();
void reconnect();
void callback(char* topic, byte *payload, unsigned int length);
void publishSerialData(String topic,char *serialData);
void publishFloat(String topic,float data_);
void updateStats();
void watering();

// Main
void setup() {
  oled_init();
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2,OUTPUT);
  Serial.begin(115200);
  Serial.setTimeout(500);// Set time out for 
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  reconnect();
  dht.setup(DHT_PIN,DHTesp::DHT11);
}

void loop() {
  
  client.loop();  //Maintain the loop alive

  //Act as a periodic timer, to publish
  long now = millis();
  if (now - lastMsg > 2000){
      lastMsg = now;
      //Read send ground humi
      ground_humi = map(analogRead(ADC_2),4095,100,0,100);
      ground_humi_txt = ground_humi;
      publishFloat("/iot-kuri/data/g_humi", ground_humi);
      //Check tank, send state
      tank_state = map(analogRead(ADC_1),700,100,100,0);
      if(tank_state > 100){
        tank_state = 100;
      }
      if(tank_state > 10){
        tank_state_txt = String(int(tank_state)) + "%";
        publishFloat("/iot-kuri/data/tank", tank_state);
      }
      else{
        tank_state_txt = "Empty";
        publishFloat("/iot-kuri/data/tank", 0);
      }
      TempAndHumidity lastValues = dht.getTempAndHumidity();
      dht11_temp = lastValues.temperature;
      dht11_humi = lastValues.humidity;
      dht11_temp_txt = dht11_temp;
      publishFloat("/iot-kuri/data/a_temp", dht11_temp);
      dht11_humi_txt = dht11_humi;
      publishFloat("/iot-kuri/data/a_humi", dht11_humi);
      updateStats();
    }
  }

//Callbacks and functions
//Function to connect to WiFi
void setup_wifi() {
    delay(10);
    // We start by connecting to a WiFi network
    Serial.println();
    oled_clear();
    oled_text("Connecting to:",0,0,1);
    oled_text(ssid,0,15,1);
    oled_update();
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    randomSeed(micros());
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

//Attempting to reconnect
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      //Once connected, publish an announcement...
      client.publish("/icircuit/presence/ESP32/", "hello world");
      // ... and resubscribe
      client.subscribe(MQTT_SERIAL_RECEIVER_CH);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

//MQTT Callback
void callback(char* topic, byte *payload, unsigned int length) {
    String t_data;
    for(int i = 0; i < length; i++){
      t_data += char(payload[i]);
    }
    Serial.println("-------new message from broker-----");
    Serial.print("channel:");
    Serial.println(topic);
    Serial.print("data:");  
    Serial.write(payload, length);
    Serial.println();
    //Command Parser
    switch (t_data.charAt(0)){
      case 'R':
          //Checks which relay to turn on
          switch(t_data.charAt(1)){
            case '1': 
                if(t_data.charAt(2) == 'E'){
                  digitalWrite(RELAY_1,HIGH);
                  Serial.println("Turning On Relay_1");
                }
                else if(t_data.charAt(2) == 'D'){
                  digitalWrite(RELAY_1,LOW);
                  Serial.println("Turning OFF Relay_1");
                }
                else{
                  Serial.println("Invalid Command");
                }
              break;
            case '2':
                if(t_data.charAt(2) == 'E'){
                  digitalWrite(RELAY_2,HIGH);
                  Serial.println("Turning On Relay_2");
                }
                else if(t_data.charAt(2) == 'D'){
                  digitalWrite(RELAY_2,LOW);
                  Serial.println("Turning OFF Relay_2");
                }
                else{
                  Serial.println("Invalid Command");
                }
              break;
            default:
              Serial.println("Invalid Command");
              break;
          }
        break;
      case 'F':
        Serial.println("F");
        switch(t_data.charAt(1)){
          case 'O':
            Serial.println("Watering");
            watering();
            break;
          default:
            Serial.println("Invalid Command");
            break;
        }
        break;
      default:
        Serial.println("Invalid Command");
        break;
    }
}
//Display and Publish
void updateStats(){
  oled_clear();
  oled_text("Air Temp: " + String(dht11_temp_txt) + "C",0,0,1);
  oled_text("Air Humi: " + String(dht11_humi_txt) + "%",0,15,1);
  oled_text("Gnd Humi: " + String(ground_humi_txt) + "%",0,30,1);
  oled_text("Water: " + tank_state_txt,0,45,1);
  oled_update();
}
//Generic Publish Function
void publishSerialData(String topic,char *serialData){
  if (!client.connected()) {
    reconnect();
  }
  client.publish(topic.c_str(), serialData);
}
//Publish float function
void publishFloat(String topic,float data_){
  if (!client.connected()) {
    reconnect();
  }
  client.publish(topic.c_str(), String(data_).c_str(),true);
}

void watering(){
  if(tank_state > 10){
    digitalWrite(RELAY_2,HIGH);
    delay(1000);
    digitalWrite(RELAY_2,LOW);
  }
}
