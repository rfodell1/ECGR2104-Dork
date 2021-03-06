/*********************************************************************
* File: game.h
* Description:  header file for game.cpp, class declaration
* Author: Robert Fodell (rfodell1@uncc.edu)
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

#ifndef GAME_H
#define GAME_H

class Player
{
    private:
        string name;
        string level;
        int energy;
        int steps;
        vector<int> location;
	int xLoc;
	int yLoc;
    public:
        Player();
        string getName();
        string getLevel();
        int getEnergy();
        int getSteps();
        vector<int> getLoc();
	int getXLoc();
	int getYLoc();
        void setName(string in_name);
        void setLevel(string in_level);
        void setEnergy(int in_energy);
        void setSteps(int in_steps);
        void setLoc(vector<int> in_loc);
	void setXLoc(int in_xloc);
	void setYLoc(int in_yloc);
	void newGame();
	void setParam();
	void fileProcess(ifstream &fileName);	

};

//banner.cpp
void gameBanner(Player &p1);
void start(Player &p1);
void updateBanner(Player &p1);

//play.cpp
void roll(Player &p1);
void turn(Player &p1);
void levelCheck(Player &p1);
void evtLoad();
void posCheck(Player &p1);
int conversion(string line);

//loadsave
void load(Player &p1);
void save(Player &p1);
int intConvert(string &line);

//checkpoint
void checkpoint(Player &p1);

//event
int check(int eLocX, int eLocY, Player &p1);
void handle(string des, int resp, int ener, int x, int y, int ques, Player &p1);

#endif
