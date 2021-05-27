//Serial Com Helper
import processing.serial.*;
Serial myPort;
int lf = 10;    // Linefeed in ASCII
String myString;
//Control String
  //BST,g,d,1,3,3,3,0,F
//Functional States
char state = 'n';
char game_state = 'x';
int player_turn = 1;
int player_name_turn = 1;
String p1_name = "";
String p2_name = "";
//String names = "JKL,00000,00000,F";
String names = "";
PVector cur_pos = new PVector();
//Names have to be inputed due to processing limitations
Player p1;
Player p2;

void setup(){
  size(800,800);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
}
void draw(){
  background(0);
  DataGather();
  switch(state){
    case 'n':
      switch(player_name_turn){
          case 1:
          textSize(40);
          text("Input Player 1 Name: \n 5 Char max",200,1*height/4);
          text(p1_name,200,height/2);
          break;
          case 2:
          textSize(40);
          text("Input Player 2 Name: \n 5 Char max",200,1*height/4);
          text(p2_name,200,height/2);
          break;
        }
        break;
    case 'e':
      textSize(80);
      text("Check Winner \n On LCD!",200,height/2);
      break;
    case 't':
      textSize(80);
      text("Press Enter \n To Start",200,height/2);
      break;
    case 'g':
      p1.render();
      p2.render();
      switch(game_state){
      case 'p':
        switch(player_turn){
          case 1:
          textSize(40);
          text("Turn: " + p1.Name,200,1*height/4);
          text("Use Arrow Keys \n To Move",200,height/2);
          break;
          case 2:
          textSize(40);
          text("Turn: " + p2.Name,200,1*height/4);
          text("Use Arrow Keys \n To Move",200,height/2);
          break;
        }
        break;
      case 'd':
        switch(player_turn){
          case 1:
          textSize(40);
          text("Turn: " + p1.Name,200,1*height/4);
          text("Use Arrow Keys \n To Place, Enter To Confirm",200,height/2);
          text("X: " + int(cur_pos.x) + "Y: " + int(cur_pos.y),200,3*height/4);
          break;
          case 2:
          textSize(40);
          text("Turn: " + p2.Name,200,1*height/4);
          text("Use Arrow Keys \n To Place, Enter To Confirm",200,height/2);
          text("X: " + int(cur_pos.x) + "Y: " + int(cur_pos.y),200,3*height/4);
          break;
        }
        break;
      }
      break;
    }
}
void keyPressed(){
  switch(state){
  case 'n':
    if(p1_name.length() < 5){
      p1_name += key;
      if(p1_name.length() == 5){
        player_name_turn = 2;
      }
    }
    else if(p2_name.length() < 5){
      p2_name += key;
    }
    else{
      p1 = new Player(p1_name,0,32);
      p2 = new Player(p2_name,500,32);
      names = "JKL," + p1_name + "," + p2_name + ",F";
      println(names);
      state = 't';
    }
  case 't':
    if (keyCode == ENTER){
      println(names);
      myPort.write(names);
    }
    break;
  case 'g':
    switch(game_state){
      case 'p':
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
      case 'd':
        if (keyCode == UP) {
        println("UP");
        if(cur_pos.y == 1){
        cur_pos.y = 0;}
      } 
      else if(keyCode == DOWN) {
        println("DOWN");
        if(cur_pos.y == 0){
        cur_pos.y = 1;}
      }
      else if(keyCode == LEFT){
        println("LEFT");
        if(cur_pos.x != 0){
          cur_pos.x--;
        }
      }
      else if(keyCode == RIGHT){
        println("RIGHT");
        if(cur_pos.x != 15){
          cur_pos.x++;
        }
      }
      else if(keyCode == ENTER){
        println("ENTER");
        SendCoords(int(cur_pos.x),int(cur_pos.y));
        cur_pos.x = 0;
        cur_pos.y = 0;
        }
        break;
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
      game_state = myString.charAt(6);
      println(game_state);
      player_turn = CharToInt(myString.charAt(8));
      println(game_state);
      UpdatePlayers(CharToInt(myString.charAt(10)),CharToInt(myString.charAt(12)),CharToInt(myString.charAt(14)),CharToInt(myString.charAt(16)));
    }
}
void UpdatePlayers(int p1_ships, int p1_ammo, int p2_ships, int p2_ammo){
  p1.update(p1_ships,p1_ammo);
  p2.update(p2_ships,p2_ammo);
}
void SendCoords(int posx, int posy){
  myPort.write("CON,"+IntToHex(posx)+","+IntToHex(posy)+",F");
  println("CON,"+IntToHex(posx)+","+IntToHex(posy)+",F");
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
