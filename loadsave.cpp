//include player information so that you can access name/ level/ etc.
#include "dork.h"
#include "game.h"


void load(Player &p1){
  
	char l[15];
	printw("Type the name of your saved game:\n");
	scanw("%s", l);
	string str(l);
	string fileN = str + ".dat";
	
	//read in data from file name
  	ifstream fileName(fileN);
		if(!fileName)
		{
			cerr << "File does not exist." << endl;
			exit(0);
		}
		else
		{
			fileName.open(fileN);
			fileProcess(fileName, p1);
		}				
		
	
}

void save(Player &p1){
  	//write data to players file if it exists
  	string fileN = p1.getName() + "dat";  	
	ofstream fileName(fileN);
  	//if (!fileName){
    		//file doesn't exist, create
		fileName.open(fileN,ios::app);
    		//write to file
    		fileName << (p1.getName()).c_str() << endl;
    		fileName << p1.getLevel() << endl;
    		fileName << p1.getEnergy() << endl;
		fileName << p1.getSteps() << endl;
    		fileName << p1.getXLoc() << endl;
		fileName << p1.getYLoc() << endl;
    
 // 	}
  //	else{
    		//file exists, write to
    //		fileName << (p1.getName()).c_str() << endl;
    	//	fileName << p1.getLevel() << endl;
    	//	fileName << p1.getEnergy() << endl;
    	//	fileName << p1.getSteps() << endl;
    	//	fileName << p1.getXLoc() << endl;
	//	fileName << p1.getYLoc() << endl;
  	//}
	
	fileName.close();

}

void fileProcess(ifstream &fileName, Player &p1)
{
	string temp[6];
	int i = 0;
	
	for (string line; getline(fileName, line);){
		temp[i] = line;
		i++;
    		
  	}
	fileName.close();

}

int intConvert(string &line) //stoi() gave thrown exception errors
{
    	string buffer = line;
    	int a = 0;

    	for(string::iterator it = buffer.begin(); it != buffer.end(); ++it)
    	{
    	a=(a*10) + (*it-48);
	}
	return a;
}



