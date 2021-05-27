class Player{
  String Name;
  int ships = 0;
  int ammo = 0;
  PVector pos = new PVector();
  Player(String Name_, int posx_, int posy_){
     Name = Name_;
     pos.x = posx_;
     pos.y = posy_;
  }
  void update(int ships_,int ammo_){
    ships = ships_;
    ammo = ammo_;
  }
  void render(){
    textSize(32);
    text("Player: " + Name,pos.x,pos.y);
    text("Ships: " + ships,pos.x,pos.y + 32);
    text("Ammo: " + ammo,pos.x,pos.y + 64);
  }

}
