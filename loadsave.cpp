//include player information so that you can access name/ level/ etc.
#include "dork.h"
#include "game.h"

/*
void load(Player &p1){
  
	char l[15];
	printw("Type the name of your saved game:\n");
	scanw("%s", l);
	p1.setParam();
	string str(l);
	string fileN = str + ".dat";
	
	//read in data from file name
  	ifstream fileName(fileN);
		if(!fileName)
		{
			cerr << "File does not exist." << endl;
			exit(0);
		}
  	int count = 1;
  	for(string line; getline(fileName, line);){
    	if(count == 1){
      		p1.setName(getline(fileName, line));
      		count++;
    	}
    	if(count == 2){
      		p1.setLevel(getline(fileName, line));
      		count++;
    	}
  	if(count == 3){
      		p1.setEnergy(getline(fileName, line));
      		count ++;
    	}
    	if(count == 4){
      		p1.setSteps(getline(fileName, line));
      		count ++;
    	}
    	if(count == 5){
      		p1.setLoc(getline(fileName, line));
    	}
  }
}

void save(Player &p1){
  //write data to players file if it exists
  string fileN = p1.getName() + ".dat";
  ofstream fileName;
  if (!fileName){
    //file doesn't exist, create
    ofstream fileName(fileN)
    //write to file
    fileName << p1.getName() << endl;
    fileName << p1.getLevel() << endl;
    fileName << p1.getEnergy() << endl;
    fileName << p1.getSteps() << endl;
    fileName << p1.getLoc() << endl;
    
  }
  else{
    //file exists, write to
    fileName << p1.getName() << endl;
    fileName << p1.getLevel() << endl;
    fileName << p1.getEnergy() << endl;
    fileName << p1.getSteps() << endl;
    fileName << p1.getLoc() endl;
  }
}
*/
