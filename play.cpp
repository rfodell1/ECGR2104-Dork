#include "dork.h"
#include "game.h"


int roll(){	
	//random # generator between 1&6 to simulate a dice roll
	srand(time(NULL));	
	int dice = rand() % 6 + 1;

	return dice;
}

void turn(Player &p1)
{
	char r[4];
	
	while(1)
	{
				
		int d1;	
		
		printw("Type 'roll' to roll or type 'quit' to quit.\n");
		scanw("%s", r);
		if (strcmp(r,"roll")==0)
		{	
			d1 = roll();
		}
		else if(strcmp(r, "quit")==0)
		{
			exit(0);
		}
		else
		{
			while(strcmp(r,"roll")!=0 && strcmp(r,"quit")!=0)
			{
				printw("Invalid input. Type 'roll' to roll.\n");
				scanw("%s", r);
				d1 = roll();
			}
		}

		//check if won, lost, or quit
		p1.setSteps(p1.getSteps() + d1);
		updateBanner(p1);

		//if theyre in x plane
		if (p1.getLevel() == "Terrestrial" || p1.getLevel() == "Aerial")
		p1.setXLoc(p1.getXLoc() + d1);
  
		//if theyre in y plane
		if (p1.getLevel() == "Arboreal")
		p1.setYLoc(p1.getYLoc() + d1);
	
		checkpoint(p1);

		updateBanner(p1);
		//loop unless won, lost, or quit

	}
}

/*void eventData(){

  //check current position
  int playLoc = p1.getLoc();
  //check if theres an event at that position
  for(read event file)
    //get the location even number
    if (playLoc = eventNum){
      //if there is call the event handler function
    }
}
*/
