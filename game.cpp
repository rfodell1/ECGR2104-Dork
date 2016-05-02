/*********************************************************************
* File: game.cpp
* Description:  setParam, to initialize each player variable
* 		constructor to give each variable a default value
* 		get/set functions
* 		new game function to initialize the variables when the game starts
* Author: Robert Fodell (rfodell1@uncc.edu)
* Edits: Wesley Harrison (wharri41@uncc.edu)
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

void Player::setParam()
{
	//setname - to user input
	setName(name);
  	//setloc - default to x = 0 y = 0
  	setXLoc(xLoc);
  	setYLoc(yLoc);
  	//setenergy - default to 10
  	setEnergy(energy);
  	//setlevel - default to terrestrial
  	setLevel(level);
  	//setsteps- default to 0
	setSteps(steps);
}	
	
	

Player::Player(): name(" "), level("Terrestrial"), energy(10), steps(0), location(0,0), xLoc(0), yLoc(0)
{

}

string Player::getName()
{
    	return name;
}

string Player::getLevel()
{
    	return level;
}

int Player::getEnergy()
{
	return energy;
}

int Player::getSteps()
{
    	return steps;
}

vector<int> Player::getLoc()
{
    	return location;
}

int Player::getXLoc()
{
	return xLoc;
}

int Player::getYLoc()
{
	return yLoc;
}

void Player::setName(string in_name)
{
    	name = in_name;
}

void Player::setLevel(string in_level)
{
    	level = in_level;
}

void Player::setEnergy(int in_energy)
{
    	energy = in_energy;
}

void Player::setSteps(int in_steps)
{
    	steps = in_steps;
}

void Player::setLoc(vector<int> in_loc)
{
	location = in_loc;
}

void Player::setXLoc(int in_xloc)
{
	xLoc = in_xloc;
}

void Player::setYLoc(int in_yloc)
{
	yLoc = in_yloc;
}

void Player::newGame()
{
	printw("Enter your name:\n");
	scanw("%s", name.c_str());
	while (strlen(name.c_str()) > 15)
	{
		printw("Please keep name under 15 characters.\n");
		printw("Enter your name:\n");
		scanw("%s", name.c_str());
	}

	setParam();
		
}

void Player::fileProcess(ifstream &fileName)
{
	string temp[6];
	string line;
	int i = 0;	
	
	if(fileName.good())
	{
		while(getline(fileName, line)){	
		cout<<line<<endl;		
		temp[i] = line;
		i++;
			if(i==7){
				break;
			}
		}
		setName(temp[0]);
		setLevel(temp[1]);
		setEnergy(intConvert(temp[2]));
		setSteps(intConvert(temp[3]));
		setXLoc(intConvert(temp[4]));
		setYLoc(intConvert(temp[5]));
	}
		
	fileName.close();

}


