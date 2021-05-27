//Serial Com Helper
import processing.serial.*;
Serial myPort;
int lf = 10;    // Linefeed in ASCII
String myString;
//Control String
  //BST,s,F
//Functional States
char state = 's';
String p1_name = "";
//String names = "JKL,00000,00000,F";
String names = "";
//Names have to be inputed due to processing limitations
Player p1;

void setup(){
  size(800,800);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
}
void draw(){
  background(0);
  DataGather();
  switch(state){
    case 's':
      textSize(40);
      if(p1_name == null){
        p1_name = new String();
      }
      text("Input Player 1 Name: \n 5 Char max",200,1*height/4);
      text(p1_name,200,height/2);    
      break;
    case 'c':
      p1_name = null;
      break;
    case 'e':
      textSize(80);
      text("Check Score \n On LCD!",200,height/2);
      break;
    case 'm':
      textSize(80);
      text("Congrats on Achieving \n Max Score!",200,height/2);
      break;
    case 't':
      textSize(80);
      text("Press Enter \n To Start",200,height/2);
      break;
    case 'g':
      textSize(40);
      text("Use Arrow Keys \n To Move",200,height/2);    
      break;
    case 'p':
      textSize(40);
      text("Game Paused",200,height/2);    
      break;
    }
}
void keyPressed(){
  switch(state){
  case 's':
    if(p1_name.length() < 5){
      p1_name += key;
      }
    if(p1_name.length() == 5){
      p1 = new Player(p1_name,0,32);
      names = "JKL," + p1_name + "," + "00000" + ",F";
      println(names);
      state = 't';
    }
    break;
  case 't':
    if (keyCode == ENTER){
      println(names);
      myPort.write(names);
    }
    break;
  case 'g':
      if (keyCode == UP) {
        println("UP");
        myPort.write("MVT,U,F");
      } 
      else if(keyCode == DOWN) {
        println("DOWN");  
        myPort.write("MVT,D,F");
      }
      else if(keyCode == LEFT){
        println("LEFT");
        myPort.write("MVT,L,F");
      }
      else if(keyCode == RIGHT){
        println("RIGHT");
        myPort.write("MVT,R,F");
      }
      break;
  }
}
void DataGather(){
    myString = myPort.readStringUntil(lf);
    if (myString != null) {
      println(myString);
      state = myString.charAt(4);
      println(state);
    }
}

int CharToInt(char a){
  if(a == '0'){
    return 0;
  }
  else if(a == '1'){
    return 1;
  }
  else if(a == '2'){
    return 2;
  }
  else if(a == '3'){
    return 3;
  }
  else {
    return 9;
  }
}
char IntToHex(int hex){
  if(hex == 0){
    return '0';
  }
  else if(hex == 1){
    return '1';
  }
  else if(hex == 2){
    return '2';
  }
  else if(hex == 3){
    return '3';
  }
  else if(hex == 4){
    return '4';
  }
  else if(hex == 5){
    return '5';
  }
  else if(hex == 6){
    return '6';
  }
  else if(hex == 7){
    return '7';
  }
  else if(hex == 8){
    return '8';
  }
  else if(hex == 9){
    return '9';
  }
  else if(hex == 10){
    return 'A';
  }
  else if(hex == 11){
    return 'B';
  }
  else if(hex == 12){
    return 'U';
  }
  else if(hex == 13){
    return 'D';
  }
  else if(hex == 14){
    return 'E';
  }
  else if(hex == 15){
    return 'G';
  }
  else{
    return 'x';
  }
}
