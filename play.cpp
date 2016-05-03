/*********************************************************************
 * File: play.cpp
 * Description:  Event data struct
 * 		load data from file to struct
 * 		Roll function
 * 		Turn function, which calls necessary functions for the user to take each turn
 * 		function to check users position
 * 		int convert function to replace stoi
 * Author: Tate Clark (uncc.edu)
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
 *********************************************************************/

#include "dork.h"
#include "game.h"


int roll(){	
	//random # generator between 1&6 to simulate a dice roll
	srand(time(NULL));	
	int dice = rand() % 6 + 1;

	return dice;
}

void turn(Player &p1)
{
	evtLoad();

	posCheck(p1);	

	char r[4];
	
	while(1)
	{
				
		int d1;	
		
		printw("Type 'roll' to roll or type 'quit' to quit.\n");
		scanw("%s", r);
		if (strcmp(r,"roll")==0)
		{	
			d1 = roll();
		}
		else if(strcmp(r, "quit")==0)
		{
			exit(0);
		}
		else
		{
			while(strcmp(r,"roll")!=0 && strcmp(r,"quit")!=0)
			{
				printw("Invalid input. Type 'roll' to roll.\n");
				scanw("%s", r);
				d1 = roll();
			}
		}

		//check if won, lost, or quit
		p1.setSteps(p1.getSteps() + d1);
		p1.setEnergy(p1.getEnergy() - 1);

		//if theyre in x plane
		if (p1.getLevel() == "Terrestrial" || p1.getLevel() == "Aerial")
		p1.setXLoc(p1.getXLoc() + d1);
  
		//if theyre in y plane
		if (p1.getLevel() == "Arboreal")
		p1.setYLoc(p1.getYLoc() + d1);

		levelCheck(p1);
	
		checkpoint(p1);

		updateBanner(p1);
		//loop unless won, lost, or quit
	
		posCheck(p1);

		if (p1.getEnergy() <= 0)
		{
			break;
		}

	}
	
	if (p1.getEnergy() <= 0)
	{
		printw("You ran out of energy. Game over.\n");
		char q[15];
		printw("Type anything to quit:\n");
		scanw("%s", q);
		if (strcmp(q,"quit"))
		{
			exit(0);
		}
	}
	
}

void levelCheck(Player &p1)
{
	
	
	
}


//Struct that holds the data from events.txt
struct event{
	
	int elX;
	int elY;
	string descrip;
	int response;
	int energy;
	int elrX;
	int elrY;
	int questi;
	int questionID;
	
} evt[200];

void evtLoad()
{
	
	//Loading of data into struct array
	ifstream fin;	
	fin.open("events.txt");
	
	for(int i = 0; i < 200; i++)
	{
		//Strings to hold numeric values that will be converted to integers
		string respHold;	
		string engHold;
		string questHold;
		string evtlHold;
		string evtlrHold;
		
		//Reading of text file, stores string values
		getline(fin, evtlHold, '^');
		getline(fin, evt[i].descrip, '^');
		getline(fin, respHold, '^');
		getline(fin, engHold, '^');
		getline(fin, evtlrHold, '^');
		getline(fin, questHold, '^');

		//strings to hold coordinate substrings
		string xHold;
		string yHold;
		string xrHold;
		string yrHold;

		//Conversion of event coordinates to x and y integers
		int leng = evtlHold.length();
		int comP = evtlHold.find(',');
		xHold = evtlHold.substr(0, comP - 1);
		evt[i].elX = intConvert(xHold);
		yHold = evtlHold.substr(comP + 1, leng);
		evt[i].elY = intConvert(yHold);

		//Conversion of response coordinates to x and y integers
		int lengt = evtlrHold.length();
		int commaP = evtlrHold.find(',');
		xrHold = evtlrHold.substr(0, commaP);
		evt[i].elrX = intConvert(xrHold);
		yrHold = evtlrHold.substr(commaP + 1, lengt - 1);
		evt[i].elrY = intConvert(yrHold);

		//Converts read string values to integers where needed
		evt[i].response = intConvert(respHold);		
		evt[i].energy = intConvert(engHold);
		evt[i].questi =	intConvert(questHold);
		
		//Identifies type of question, if a question at all
		int id = 0;			
		if(evt[i].questi == 1)
		{		
			string descHold = evt[i].descrip;
			id = idQuestion(descHold);
		}
		evt[i].questionID = id;

	}	
	
	fin.close();
	
}

void posCheck(Player &p1)
{
	int checkVar;

	for(int c = 0; c < 200; c++)
	{
		checkVar = check(evt[c].elX, evt[c].elY, p1);	
		if(checkVar == 1)
		{
			handle(evt[c].descrip, evt[c].response, evt[c].energy, evt[c].elrX, evt[c].elrY, evt[c].questi, p1);		
		break;				
		}
		
	}
		
}

int conversion(string line)
{
	string buffer = line;
	int a = 0;
	int needN = 0;

	int negative = buffer.find('-');
	if(negative >= 0)
	{
		int leng = buffer.length();
		buffer = buffer.substr(negative + 1, leng);
		needN = 1;
	}
	
	for(string::iterator it = buffer.begin() ; it!= buffer.end() ; ++it)
	{
	a = (a*10) + (*it-48);
	}
	
	if(needN == 1)
	{
		a = -a;
	}
	return a;
}

int idQuestion(string questid)
{
	//Identifiers used to ID keywords in questions and subjects
	int QID = 0;
	int questWhat = -1;
	int questwhat = -1;
	int questlike = -1;
	int questprovide = -1;
	int questParadise = -1;
	int questwants = -1;
	int questneeds = -1;
	int questreply = -1;
	int keyjob = -1;
	int keymusic = -1;
	int keysport = -1;
	int keyphraseQ = -1;
	int keycolorQ = -1;
	int keyphrase = -1;
	int keycolor = -1;
	int keyjobQ = -1;
	int keymusicP = -1;

	//Searching the subject for the specified keywords
	questWhat = questid.find("What");
	questwhat = questid.find("what");
	questlike = questid.find("like");
	questprovide = questid.find("provide");
	questParadise = questid.find("Paradise");
	questwants = questid.find("wants");
	questneeds = questid.find("needs");
	questreply = questid.find("reply");
	keyjob = questid.find("job");
	keymusic = questid.find("music");
	keysport = questid.find("sport");
	keyphraseQ = questid.find("phrase?");
	keycolorQ = questid.find("color?");
	keyphrase = questid.find("phrase");
	keycolor = questid.find("color");
	keyjobQ = questid.find("job?");
	keymusicP = questid.find("music.");

	//Assigning the correct questions to ID numbers
	if(questWhat >= 0 && keyjob >= 0)
	{
			QID = 1;
	}
	if(questwhat >= 0 && keymusic >= 0)
	{
			QID = 2;
	}
	if(questlike >= 0 && keysport >= 0)
	{
			QID = 3;
	}
	if(questprovide >= 0 && keyphraseQ >= 0)
	{
			QID = 4;
	}
	if(questWhat >= 0 && keycolorQ >= 0)
	{
			QID = 5;
	}
	if(questParadise >= 0 && keyphrase >= 0)
	{
			QID = 6;
	}
	if(questwants >= 0 && keycolor >= 0)
	{
			QID = 7;
	}
	if(questwants >= 0 && keyjobQ >= 0)
	{
			QID = 8;
	}
	if(questneeds >= 0 && keysport >= 0)
	{
			QID = 9;
	}
	if(questreply >= 0 && keymusicP >= 0)
	{
			QID = 10;
	}
	
	return QID;

}
