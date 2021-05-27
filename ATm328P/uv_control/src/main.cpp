#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <TimerOne.h>
//Pines digitales
#define btn 3
#define door 4
#define uv_lamp 5
//Pines analogos
//SCL --> A5
//SDA --> A4
//Control variables
enum Machine {main, uvcycle, retrieve, cdoor, indfmode, cconfirm, none};
Machine state = main;
Machine old_state = none;

//Time Variables
int dis_duration = 60*30;
int seconds = dis_duration;
int minutes = 0;
int sleept = 0;
//Globlan Int Vars
int cdown = 2000;
bool tflag = true;
//flags
int oled_sleep = false;
//OLED encapsulation
#include <oled_utils.h>
#include <utils.h>
//Interrupts
void onesecond();
void btn_int();

void setup(){
  //Pin initialization
  pinMode(btn,INPUT);
  pinMode(door,INPUT);
  pinMode(uv_lamp,OUTPUT);
  pinMode(btn, INPUT);
  uv_lamp_off();
  Serial.begin(115200);
  //Timer
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(onesecond);
  //Oled
  oled_init();
  //Button interrput
  attachInterrupt(digitalPinToInterrupt(btn), btn_int, RISING);
}

void loop() {
  switch (state){
    case cdoor:
      if (!digitalRead(door)){
        uv_lamp_off();
        oled_clear();
        oled_text("CUIDADO\nCIERRE\nLA\nPUERTA", 0, 0, 2);
        oled_update();
        //delay(50);
      }
      else{
        state = old_state;
      }
      break;
    case main:
      seconds = dis_duration;
      uv_lamp_off();
      if(utils_check_door()){
        break;
      }
      oled_clear();
      if(!oled_sleep){
      oled_text("PRESIONE\nEL BOTON\nPARA\nCOMENZAR", 10, 0, 2);
      }
      oled_update();
      //delay(50);
      break;
    case uvcycle:
      if(utils_check_door()){
        break;
      }
      sleept = 0;
      oled_sleep = false;
      uv_lamp_on();
      oled_clear();
      oled_text(String(minutes) + ":" + String((seconds) % 60), 0, SCREEN_HEIGHT / 4, 4);
      oled_update();
      //delay(50);
      break;
    case indfmode:
      if(utils_check_door()){
        break;
      }
      sleept = 0;
      oled_sleep = false;
      uv_lamp_on();
      oled_clear();
      oled_text("MODO\nINDEFINIDO\nACTIVADO", 0, 0, 2);
      oled_update();
      //delay(50);
      break;
    case cconfirm:
      if(utils_check_door()){
        break;
      }
      uv_lamp_off();
      oled_clear();
      oled_text("CANCELADO", 0, 0, 2);
      oled_update();
      delay(3500);
      state = main;
      break;
    case retrieve:
      if(utils_check_door()){
        break;
      }
      while(digitalRead(door)){
        uv_lamp_off();
        oled_clear();
        if(!oled_sleep){
          oled_text("RERTIRE\nSU\nOBJETO", 0, 0, 2);
        }
        oled_update();
        //delay(50);
      }
      oled_clear();
      oled_text("GRACIAS", 0, 0, 2);
      oled_update();
      delay(5000);
      state = main;
    default:
      break;
    }
}

void onesecond(){
  switch (state){
    case cdoor:
      uv_lamp_off();
      break;
    case main:
      if(sleept > 60*5){
        oled_sleep = true;
      }
      else{
      sleept++;
      }
      break;
    case uvcycle:
      seconds--;
      minutes = ((seconds) / 60);
      if(seconds == 0){
        seconds = dis_duration;
        state = retrieve;
      }
      break;
    case retrieve:
      if(sleept > 60*5){
        oled_sleep = true;
      }
      else{
      sleept++;
      }
      break;
    default:
      break;
  }
}

void btn_int(){
  switch (state){
  case uvcycle:
    uv_lamp_off();
    break;
  case indfmode:
    uv_lamp_off();
    break;
  default:
    break;
  }
  sleept = 0;
  oled_sleep = false;
  switch(state){
    case main:
      cdown = 20000;
      tflag = true;
      while (digitalRead(btn) && tflag){
        cdown--;
        delayMicroseconds(100);
        if(cdown == 0){
          state = indfmode;
          tflag = false;
        }
      }
      if(tflag){
        state = uvcycle;
      }
      break;
    case uvcycle:
      cdown = 20000;
      tflag = true;
      while (digitalRead(btn) && tflag){
        cdown--;
        delayMicroseconds(100);
        if(cdown == 0){
          state = cconfirm;
          tflag = false;
        }
      }
      break;
    case indfmode:
      cdown = 20000;
      tflag = true;
      while (digitalRead(btn) && tflag){
        cdown--;
        delayMicroseconds(100);
        if(cdown == 0){
          state = cconfirm;
          tflag = false;
        }
      }
      break;
    case cconfirm:
      break;
    case retrieve:
      break;
    case none:
      break;
    default:
      break;
  }
  delayMicroseconds(200);
}
