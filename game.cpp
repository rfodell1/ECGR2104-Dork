//function definitions
#include "dork.h"
#include "game.h"

void gameBanner(Player data);

Player::Player(): name(" "), level("Terrestrial"), energy(0), steps(0), location(0,0)
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

void Player::setName(const string in_name)
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

void gameBanner(Player data)
{
	clearDisplay(1);
	printw("Hello");    
}
