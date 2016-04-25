#include "game.cpp"

void roll(){

  //random # generator between 1&6 to simulate a dice roll
  int dice = rand() % 6 + 1;
  //update player position based on roll
  
  //if theyre in x plane
  if (p1.getLevel() == "Terestrial" || p1.getLevel() == "Cloud")
  p1.setXLoc() = p1.getXLoc() + dice;
  
  //if theyre in y plane
  if (p1.getLevel() = "Aboretal")
  p1.setYLoc() = p1.setYLoc() + dice;
  
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
