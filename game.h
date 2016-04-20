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
    public:
        Player();
        string getName();
        string getLevel();
        int getEnergy();
        int getSteps();
        vector<int> getLoc();
        void setName(string in_name);
        void setLevel(string in_level);
        void setEnergy(int in_energy);
        void setSteps(int in_steps);
        void setLoc(vector<int> in_loc);	

};

void gameBanner(Player data);
void newGame();

#endif

