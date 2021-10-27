#include <iostream>
#include "Controller.h"
using namespace std;

Controller::Controller() {
  //Allocate memory for data in controller
  Data *players = new Data[2];
  //Return data from PlayerData.cpp into controller for use
  players = stats.returnPlayerData();

  display.drawGrids(players,0);
  display.drawGrids(players,1);

/*userInput = '1';
while(userInput != '0') {
  display.menu();
  cin >> userInput;
  user.inputMenu(userInput, 4);
  
}
display.askQuit;
*/
}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
}

//int MainLoop(){}

//int MenuLoop(){}

//int GameLoop(){}

void InitializeGame(bool AI){
    
}