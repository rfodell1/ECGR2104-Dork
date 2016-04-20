#include "game.cpp"

void checkpoint(){

  //if checkpoint is a multiple of 25
  int check = player.getLoc() % 25
  if(check = 0){
    //call the save function with the players current information as the argument'
    save(player);
  }
}
