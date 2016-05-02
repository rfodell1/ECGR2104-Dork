/*********************************************************************
* File: loadsave.cpp
* Description:  load a user profile from a .dat file
* 		save a user profile to a .dat file
* 		get line function
* 		int convertt function to replace stoi
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



