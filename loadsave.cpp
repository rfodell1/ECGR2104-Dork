//include player information so that you can access name/ level/ etc.

void load(String fileName){
  //read in data from file name
  //set each player variable based on file info
}

void save(){
  //write data to players file if it exists
  String fileN = player.getName() + ".dat";
  ofstream fileName;
  if (!fileName){
    //file doesn't exist, create
    ofstream fileName(fileN + ".dat")
    //write to file
    fileName << player.getName();
    fileName << player.getLevel();
    fileName << player.getEnergy();
    fileName << player.getSteps();
    fileName << player.getLoc();
    
  }
  else{
    //file exists, write to
    fileName << player.getName();
    fileName << player.getLevel();
    fileName << player.getEnergy();
    fileName << player.getSteps();
    fileName << player.getLoc();
  }
}
