#include "Controller.h"    

Controller::Controller() {
  //Return data from PlayerData.cpp into controller for use
  //display.drawGrids(pdata.returnPlayerData(0));
  //display.drawGrids(pdata.returnPlayerData(1));
}

void Controller::setup(){
  for(int i=0; i<2; i++){ //Loop for two players
    //Changed back to dynamic
    int intSize = 2;
    int *coords = new int[intSize];
    int orientation;
    out.playerNamePrompt();
    players[i].playerName  = in.inputPlayerData();
    like = false;
    //Player ship orientation
    while(!like) { //Ask for player 1's ship positions  
      for(int u=0; u<5; u++){
        //bool for ship fits
        bool fits = false;
        //Checks if ship fits in grid
        while(!fits) {
          out.coordinatePrompt();
          coords = in.inputCoordinates();
          out.directionPrompt();
          orientation = in.inputUserSetUp();    
          //functions that put ships in grid 
          fits = pdata.shipFits(coords, orientation, u, i)
          //if shipFits = true run placeShips()
          if(fits) {
            pdata.placeShips(coords, orientation, u, i);
          }
        }
      }
      //Output player's grid to show if its good
      out.drawGrids(players.data, i);
      //Ask if ship position is good
      out.verifyShipPos();
      char again;
      cin>>again;
      if(again=='y') like=true;
      else like=false;
    }
  }
}

void Controller:mainMenu(){
  bool startMenu=true;
  while(startMenu) {
        //Output Menu
        out.menu();
        choice = in.inputMenu();
        //Menu options
        switch(choice) {
            case 0:
                out.endMessage();
                startMenu = false;
                break;
            case 1:
                play();
                break; 
            case 2:
                //Output rules from view
                out.rules();
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
                out.endMessage();
                startMenu = false;
                break;
        }
    }
}

void Controller::play(){
  setup();
  //a function for playing the game
}

void Controller::write(){ //calls the file write function

}

void Controller::leaderboard(){//Calls a view function that displays the leaderboard

}

void Controller::stats(){ //Calls a view funtion that displays current player stats????

}





if(cellnumber]hit = true) {
  switch(ship) {
    case
  }
}
