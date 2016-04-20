#include "game.cpp"

void roll(){

  //random # generator between 1&6 to simulate a dice roll
  int dice = rand() % 6 + 1;
  //update player position based on roll
  player.setLoc() = player.getLoc() + dice;
}

void eventData(){

  //check current position
  int playLoc = player.getLoc();
  //check if theres an event at that position
  for(read event file)
    //get the location even number
    if (playLoc = eventNum){
      //if there is call the event handler function
    }
}
