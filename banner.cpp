//Display and update functions
#include "dork.h"
#include "game.h"


void gameBanner(Player &p1)
{
	
	clearDisplay(1);
	printw("--------------------------------------------------------------------\n");
	printw("Name: ");
	printw("%s", ((p1.getName()).c_str()));
	printw("       ");
	printw("Level: ");
	printw("%s", ((p1.getLevel()).c_str()));
	printw("       ");	
	printw("Energy: ");
	printw("%i", p1.getEnergy());
	printw("       ");
	printw("Steps: ");
	printw("%i", p1.getSteps());
	printw("       \n");
	printw("--------------------------------------------------------------------\n");
	printw("\n");
			    
}

void updateBanner(Player &p1)
{
	//name remains same
	//if (check == 0) energy - 1
	p1.setEnergy(p1.getEnergy() - 1);
	//steps + dice value
	//check level
	//if (check == 1) handle();
	//change energy, steps, level accordingly	

	clearDisplay(1);
		
	p1.setParam();
	printw("--------------------------------------------------------------------\n");
	printw("Name: ");
	printw("%s", ((p1.getName()).c_str()));
	printw("       ");
	printw("Level: ");
	printw("%s", ((p1.getLevel()).c_str()));
	printw("       ");	
	printw("Energy: ");
	printw("%i", p1.getEnergy());
	printw("       ");
	printw("Steps: ");
	printw("%i", p1.getSteps());
	printw("       \n");
	printw("--------------------------------------------------------------------\n");
	printw("\n");
}
	
void start(Player &p1)
{

	printw("Type 'NEW' to start a new game.\nType 'LOAD' to load a game.\n");	
	char str[4];	
	
	scanw("%s",str);	

	if(strcmp(str,"NEW")!=0 && strcmp(str,"new")!=0 && strcmp(str,"New")!=0 && strcmp(str,"LOAD")!=0 && strcmp(str,"load")!=0 && strcmp(str,"Load")!=0)
	{	
		while(strcmp(str,"NEW")!=0 && strcmp(str,"new")!=0 && strcmp(str,"New")!=0 && strcmp(str,"LOAD")!=0 && strcmp(str,"load")!=0 && strcmp(str,"Load")!=0)
		{	
				printw("Command not recognized. Please enter 'NEW' or 'LOAD'.\n");
				scanw("%s",str);
			
		}
	}
	if (strcmp(str,"NEW")==0 || strcmp(str,"new")==0 || strcmp(str,"New")==0)
	{
		p1.newGame();
	}
	else if (strcmp(str,"LOAD")==0 || strcmp(str,"LOAD")==0 || strcmp(str,"LOAD")==0)
	{
		//load(p1);
	}		

		
}
