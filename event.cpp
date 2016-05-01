//include player information
//include roll information

int check(int eLocX, int eLocY, Player &p1)
{
	int evtCheck = 0;	

	if(eLocX == p1.getXLoc() && eLocY == p1.getYLoc())
	{
		evtCheck = 1;
	}

	return evtCheck;
}

void handle(){

  //if there is an event at players location
  //output event/question
  //if event change user info
  //if question, change user info based on answer

}
