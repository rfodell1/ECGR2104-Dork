//function definitions
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
	setParam();
		
}

