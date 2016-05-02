/*********************************************************************
* File: play.cpp
* Description:  Event data struct
* 		load data from file to struct
* 		Roll function
* 		Turn function, which calls necessary functions for the user to take each turn
* 		function to check users position
* 		int convert function to replace stoi
* Author: Tate Clark (uncc.edu)
* Author: Wesley Harrison (wharri41@uncc.edu)
* Edits: Robert Fodell (rfodell1@uncc.edu)
* University: UNC Charlotte
*
* This program is part of UNC Charlotte course project
* and is distributed for education purpose only.
* All commercial rights are reserved by the author on
* distibution of the game database, custom function , header, ascii art
* and other related to this game pack.
* must be properly acknowledge.
* /
* *******************************************************************/

#include "dork.h"
#include "game.h"

//Struct that holds the data from events.txt
struct event{
	
	int elX;
	int elY;
	string descrip;
	int response;
	int energy;
	int elrX;
	int elrY;
	int questi;
	
} evt[200];

void evtLoad()
{
	
	//Loading of data into struct array
	ifstream fin;	
	fin.open("events.txt");
	
	for(int i = 0; i < 200; i++)
	{
		//Strings to hold numeric values that will be converted to integers
		string respHold;	
		string engHold;
		string questHold;
		string evtlHold;
		string evtlrHold;
		
		//Reading of text file, stores string values
		getline(fin, evtlHold, '^');
		getline(fin, evt[i].descrip, '^');
		getline(fin, respHold, '^');
		getline(fin, engHold, '^');
		getline(fin, evtlrHold, '^');
		getline(fin, questHold, '^');

		//strings to hold coordinate substrings
		string xHold;
		string yHold;
		string xrHold;
		string yrHold;

		//Conversion of event coordinates to x and y integers
		int leng = evtlHold.length();
		int comP = evtlHold.find(',');
		xHold = evtlHold.substr(1, comP - 1);
		evt[i].elX = intConvert(xHold);
		yHold = evtlHold.substr(comP + 1, leng);
		evt[i].elY = intConvert(yHold);

		//Conversion of response coordinates to x and y integers
		int lengt = evtlrHold.length();
		int commaP = evtlrHold.find(',');
		xrHold = evtlrHold.substr(0, commaP);
		evt[i].elrX = intConvert(xrHold);
		yrHold = evtlrHold.substr(commaP + 1, lengt - 1);
		evt[i].elrY = intConvert(yrHold);

		//Converts read string values to integers where needed
		evt[i].response = intConvert(respHold);		
		evt[i].energy = intConvert(engHold);
		evt[i].questi =	intConvert(questHold);

	}	
	
	fin.close();
	
}



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

void posCheck(player& p1)
{
	
	for(int c = 0; c < 200; c++)
	{
		int checkVar = check(pl.getXLoc(), p1.getYLoc(), evt[c].elX, evt[c].elY);	
		if(checkVar == 1)
		{
			//handle(p1.getXLoc(), p1.getYLoc, p1.getEnergy, evt[c].descrip, evt[c].response, evt[c].energy, evt[c].elrX, evt[c].elrY, evt[c].questi);			
		}
		
	}
		
}



int intConvert(string line)
{
	string buffer = line;
	int a = 0;
	int needN = 0;

	int negative = buffer.find('-');
	if(negative >= 0)
	{
		int leng = buffer.length();
		buffer = buffer.substr(negative + 1, leng);
		needN = 1;
	}
	
	for(string::iterator it = buffer.begin() ; it!= buffer.end() ; ++it)
	{
	a = (a*10) + (*it-48);
	}
	
	if(needN == 1)
	{
		a = -a;
	}
	return a;
}

