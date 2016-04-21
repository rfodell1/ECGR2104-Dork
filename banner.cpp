//Display and update functions
#include "dork.h"
#include "game.h"


void gameBanner(Player data)
{
	
	clearDisplay(1);
	
			    
}
	
void Player::newGame()
{
	printw("Type 'NEW' to start a new game.\nType 'LOAD' to load a game.\n");	
	char str[4];	
	
	scanw("%c",str);	
	while(strcmp(str,"NEW") != 0)
	{	
			printw("Command not recognized. Please enter 'NEW' or 'LOAD'.\n");
			scanw("%c",str);
		
	}
	if (strcmp(str,"NEW")==0)
	{
		printw("Enter your name:\n");
		scanw("%s", name.c_str());
		printw("%s",name.c_str());
	}	
}
