#include "game.cpp"
#include "banner.cpp"
#include "display.cpp"
#include "checkpoint.cpp"

void setParam(){
  //setname - to user input
  p1.setName(name);
  //setloc - default to x = 0 y = 0
  p1.setX(xLoc);
  p1.setY(yLoc);
  //setenergy - default to 10
  p1.setEnergy(energy);
  //setlevel - default to terrestrial
  p1.setLevel(level);
  //setsteps- default to 0
  p1.setSteps(steps);
}

void load(String fileName){
  //read in data from file name
  String fileN = p1.getName() + ".dat";
  ifstream fileName;
  int count = 1;
  //loading saved values from previous game
  for(String line; getLine(fileName, line)){
    if(count == 1){
      p1.setName(getLine(fileName, line));
      count++;
    }
    if(count == 2){
      p1.setLevel(getLine(fileName, line));
      count++;
    }
    if(count == 3){
      p1.setyEnergy(getLine(fileName, line));
      count ++;
    }
    if(count == 4){
      p1.setSteps(getLine(fileName, line));
      count ++;
    }
    if(count == 5){
      p1.setLoc(getLine(fileName, line));
    }
  }
}

void save(){
  //write data to players file if it exists
  String fileN = p1.getName() + ".dat";
  ofstream fileName;
  if (!fileName){
    //file doesn't exist, create
    ofstream fileName(fileN + ".dat")
    //write to file
    fileName << p1.getName();
    fileName << p1.getLevel();
    fileName << p1.getEnergy();
    fileName << p1.getSteps();
    fileName << p1.getLoc();
    
  }
  else{
    //file exists, write to
    fileName << p1.getName();
    fileName << p1.getLevel();
    fileName << p1.getEnergy();
    fileName << p1.getSteps();
    fileName << p1.getLoc();
  }
}
