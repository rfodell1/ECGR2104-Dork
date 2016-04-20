//Display and update functions
#include "dork.h"
#include "game.h"


void gameBanner(Player data)
{
	
	clearDisplay(1);
	
			    
}
	
void newGame()
{
	printw("Type 'NEW' to start a new game.\nType 'LOAD' to load a game.\n");
	string n;
	getstr(n);	
	while(n != "NEW")
	{	
			printw("Command not recognized. Please enter 'NEW' or 'LOAD'.\n");
			getstr(n);
		
	}
	if (n == "NEW")
		printw("Enter your name:\n");
}
