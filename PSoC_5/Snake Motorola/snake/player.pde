class Player{
  String Name;
  PVector pos = new PVector();
  Player(String Name_, int posx_, int posy_){
     Name = Name_;
     pos.x = posx_;
     pos.y = posy_;
  }
  void render(){
    textSize(32);
    text("Player: " + Name,pos.x,pos.y);
  }

}
