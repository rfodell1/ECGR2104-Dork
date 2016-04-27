#include "dork.h"
#include "game.h"

void checkpoint(Player &p1){
	
	int check = 0;
  	//if checkpoint is a multiple of 25
  	if (p1.getLevel() == "Terrestrial" || p1.getLevel() == "Aerial")
  		check = p1.getXLoc() % 25;
  	else if (p1.getLevel() == "Arboreal")
  		check = p1.getYLoc() % 25;
  	if(check < 6 && check >= 0 && p1.getSteps() > 5)
	{
    		//call the save function with the players current information as the argument'
   		//save(p1);
		printw("Game saved.");
		char test[1];		
		scanw("%s", test);
			
  	}
}
