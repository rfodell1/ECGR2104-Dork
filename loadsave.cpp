//include player information so that you can access name/ level/ etc.

void load(String fileName){
  //read in data from file name
  String fileN = player.getName() + ".dat";
  ifstream fileName;
  int count = 1;
  for(String line; getLine(fileName, line)){
    if(count = 1){
      player.setName(getLine(fileName, line));
      count++;
    }
    if(count = 2){
      player.setLevel(getLine(fileName, line));
      count++;
    }
    if(count = 3){
      player.setyEnergy(getLine(fileName, line));
      count ++;
    }
    if(count == 4){
      player.setSteps(getLine(fileName, line));
      count ++;
    }
    if(count = 5){
      player.setLoc(getLine(fileName, line));
    }
  }
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
