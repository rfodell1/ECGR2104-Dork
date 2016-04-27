//class declaration
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

};

//banner.cpp
void gameBanner(Player &p1);
void start(Player &p1);
void updateBanner(Player &p1);

//play.cpp
void roll(Player &p1);
void turn(Player &p1);
void eventData();

//loadsave
//void load(Player &p1);
//void save(Player &p1);

//checkpoint
void checkpoint(Player &p1);

#endif
