/*********************************************************************
 * File: checkpoint.cpp
 * Description: Check the level of the player, to check the players axis (x,y) then figure out if they have taken 25
 * 		(or more depending on the last roll value, if the last roll went from under 25 to above 25) steps on that axis
 * 		and call a function to save the user data after each multiple of 25 is reached.
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
   		save(p1);
			
  	}
}

