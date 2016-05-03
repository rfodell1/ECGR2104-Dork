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
	
	///////////////////////Tate's event logic
	/*
	//Level change questions
	if(questResp == 1 && engResp == 0 && isQuesti == 0)
	{
		if(playerinput == yes)
		{
			p1.setXLoc = p1.getXLoc + xResp);
		}
		
	}
	
	//Questions that store user input
	if(questResp == 1 && engResp == 0 && isQuesti == 1)
	{
		userIn = playerinput
		//write player input to save file
		//needs a way to distinguish questions that ask for user input and questions that ask for saved response
	}

	//Questions that ask to eat or store energy items
	//Questions that store user input
	/*if(questResp == 1 && engResp == 0 && isQuesti == 1)
	{
		cin >> userIn
		if(questionID == 1)
		{
			//stores job
			p1.job = userIn;
		}
		else if(questionID == 2)
		{
			//stores music
			p1.music = userIn;
		}
		else if(questionID == 3)
		{
			//stores sport
			p1.sport = userIn
		}
		else if(questionID == 4)
		{	
			//stores phrase
			p1.phrase = userIn
		}
		else if(questionID == 5)
		{
			//stores color
			p1.color = userIn
		}
		else if(questionID == 6)
		{
			//compares phrase
			if(userIn == p1.job)
			{
				cout << "Correct" << endl;
			}
			else if(userIn != p1.job)
			{
				cout << "Incorrect. Try again" << endl;
				int g = 0;
				while(g == 0)
				{
					cin >> userIn;
					if(userIn == p1.job)
					{
						cout << "Correct" << endl;
						g = 1;
					}
				}
			}
			
		}
		else if(questionID == 7)
		{
			compares color
			if(userIn == p1.job)
			{
				cout << "Correct" << endl;
			}
			else if(userIn != p1.job)
			{
				cout << "Incorrect. Try again" << endl;
				int g = 0;
				while(g == 0)
				{
					cin >> userIn;
					if(userIn == p1.job)
					{
						cout << "Correct" << endl;
						g = 1;
					}
				}
			}
		}
		else if(questionID == 8)
		{
			compares job
			if(userIn == p1.job)
			{
				cout << "Correct" << endl;
			}
			else if(userIn != p1.job)
			{
				cout << "Incorrect. Try again" << endl;
				int g = 0;
				while(g == 0)
				{
					cin >> userIn;
					if(userIn == p1.job)
					{
						cout << "Correct" << endl;
						g = 1;
					}
				}
			}
		}
		else if(questionID == 9)
		{
			compares sport
			if(userIn == p1.job)
			{
				cout << "Correct" << endl;
			}
			else if(userIn != p1.job)
			{
				cout << "Incorrect. Try again" << endl;
				int g = 0;
				while(g == 0)
				{
					cin >> userIn;
					if(userIn == p1.job)
					{
						cout << "Correct" << endl;
						g = 1;
					}
				}
			}
		}
		else if(questionID == 10)
		{
			compares music
			if(userIn == p1.job)
			{
				cout << "Correct" << endl;
			}
			else if(userIn != p1.job)
			{
				cout << "Incorrect. Try again" << endl;
				int g = 0;
				while(g == 0)
				{
					cin >> userIn;
					if(userIn == p1.job)
					{
						cout << "Correct" << endl;
						g = 1;
					}
				}
			}
		}
		
	}*/


}

