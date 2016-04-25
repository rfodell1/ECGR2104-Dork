#include "game.cpp"

void checkpoint(){

  //if checkpoint is a multiple of 25
  if (p1.getLevel == "Terrestrial" || p1.getLevel == "Cloud")
  int check = player.getXLoc() % 25;
  else if (p1.getLevel == "Arboretal")
  int check = player.getYLoc() % 25;
  if(check == 0){
    //call the save function with the players current information as the argument'
    save(p1);
  }
}
