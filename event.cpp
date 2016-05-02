/*********************************************************************
* File: event.cpp
* Description: Check if there is an event in the database at the users location
* 		Handle the event at that location in the database
* 			-questions (store and not store)
* 			-events
* 			- and changing level, energy, and steps
* Author: Tate Clark (@uncc.edu)
* Edits: Wesley Harrison (wharri41@uncc.edu)
* Edits: Robert Fodell (rfodell1@uncc.edu)
* University: UNC Charlotte
*
* This program is part of UNC Charlotte course project
* and is distributed for education purpose only.
* All commercial rights are reserved by the author on
* distibution of the game database, custom function , header, ascii art
* and other related to this game pack
* must be properly acknowledge.
* /
*******************************************************************/

#include"dork.h"
#include"game.h"

int check(int eLocX, int eLocY, Player &p1)
{		
	int evtCheck = 0;	

	if(eLocX == p1.getXLoc() && eLocY == p1.getYLoc())
	{
		evtCheck = 1;
	}

	return evtCheck;
}

void handle(string des, int resp, int ener, int x, int y, int ques, Player &p1){
  
	//print description
	printw("%s\n", des.c_str());
	
	
  	//if not a question
	/*if (ques == 0)
	{	//change x&y
		p1.setXLoc(p1.getXLoc() + x);
		p1.setYLoc(p1.getYLoc() + y);
		//change energy
		p1.setEnergy(p1.getEnergy() + ener);
	}
  	//if question
	if (ques == 1)
	{	//getresponse
		char str[20];		
		scanw("%s", str);	
		//if store response
		if (resp == 1)
		{	//store
			
			//change x&y
			p1.setXLoc(p1.getXLoc() + x);
			p1.setYLoc(p1.getYLoc() + y);
			//change energy
			p1.setEnergy(p1.getEnergy() + ener);
		}	
		else{
			//change x&y
			p1.setXLoc(p1.getXLoc() + x);
			p1.setYLoc(p1.getYLoc() + y);
			//change energy
			p1.setEnergy(p1.getEnergy() + ener);
		}
	}*/

}

