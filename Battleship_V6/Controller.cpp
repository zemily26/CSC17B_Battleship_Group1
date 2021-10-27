#include "Controller.h"
using namespace std;

Controller::Controller() {
  //Return data from PlayerData.cpp into controller for use
  //display.drawGrids(pdata.returnPlayerData(0));
  //display.drawGrids(pdata.returnPlayerData(1));
}

void Controller::setUp(){
  for(int i=0; i<2; i++){ //Loop for two players
    //Changed back to dynamic
    int intSize = 2;
    int *coords = new int[intSize];
    int orientation;
    //display.playerNamePrompt();
    in.inputPlayerData();
    pdata.player[i].setPlayerName(in.inputPlayerData());
    int like = false;
    //Player ship orientation
    while(!like) { //Ask for player 1's ship positions  
      for(int u=0; u<5; u++){
        //bool for ship fits
        bool fits = false;
        //Checks if ship fits in grid
        while(!fits) {
          display.coordinatePrompt();
          coords = in.inputCoordinates();
          display.directionPrompt();
          orientation = in.inputUserSetUp();    
          //functions that put ships in grid 
          fits = pdata.shipFits(coords, orientation, u, i);
          //if shipFits = true run placeShips()
          if(fits) {
            pdata.placeShips(coords, orientation, u, i);
            //Prompt saying it fits choose another ship to place
          }
          else {
            //prompt saying it does not fit, do it again
          }
        }
      }
      //Output player's grid to show if its good
      display.drawGrids(pdata.returnPlayerData(i));
      //Ask if ship position is good
      //display.verifyShipPos();
      char again;
      cin >> again;
      if(again=='y') like=true;
      else like=false;
    }
  }
}

void Controller::mainMenu(){
  bool startMenu=true;
  while(startMenu) {
        //Output Menu
        display.menu();
        int choice;
        //Menu options
        switch(in.inputMenu(choice);) {
            case 0:
                //display.endMessage();
                startMenu = false;
                break;
            case 1:
                //playPromt();
                setUp();
                break; 
            case 2:
                //Output rules from view
                display.rules();
                break;
            case 3:
                //Output Stats from view and stuff
                //Has not been made yet, need stats from model
                break;
            case 4:
                //Output Leaderboard
                //Has not been made yet, need binary file to input leader board
                break; 
            default:
                //display.endMessage();
                startMenu = false;
                break;
        }
    }
}