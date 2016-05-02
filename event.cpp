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
int check(int eLocX, int eLocY, Player &p1)
{
	int evtCheck = 0;	

	if(eLocX == p1.getXLoc() && eLocY == p1.getYLoc())
	{
		evtCheck = 1;
	}

	return evtCheck;
}

void handle(){

  //if there is an event at players location
  //output event/question
  //if event change user info
  //if question, change user info based on answer

}
