/* 
 * File:   Controller.cpp
 * Purpose: Controller Class Function Definitions
 */

#include "Controller.h" //Controller Class header file

Controller::Controller() { //Constructor
    userInput = 'X';
    //Allocate memory
    players = new PlayerData[numPlayers];
}

//Setup game
void Controller::setUp(){
    for(int i=0; i<2; i++){ //Loop for two players
        int intSize = 2; //Size of input coordinates array
        int *coords = new int[intSize]; //Hold input coordinates
        int orientation; //Hold ship orientation choice
        //Ask Player for their name
        display.playerNamePrompt(i);
        //Set Player name
        players[i].setPlayerName(in.inputPlayerData());
        //Bool for loops
        bool like = false; //User likes ship placement = true
        bool fits = false; //Ships fit = true
        //Place Ships
        while(!like) { //Loop until user likes placement
            players[i].resetGrid(); //Reset grid
            for(int u=0; u<5; u++){ //Loop on number of ships in fleet
                fits = false;
                while(!fits) {//Checks if ship fits in grid
                    //Output Grid for reference
                    display.drawPlayerGrid(players[i]);
                    //Output prompt for coordinates
                    display.coordinatePrompt();
                    coords = in.inputCoordinates();
                    //Output prompt for ship orientation
                    display.directionPrompt();
                    orientation = in.inputUserSetUp();    
                    //Place ships in grid 
                    fits = pdata.shipFits(players[i].returnGrid(), coords, orientation, u);
                    if(fits) {//if shipFits = true run placeShips()
                        players[i].updateGrid(pdata.placeShips(players[i].returnGrid(), coords, orientation, u));
                        //Prompt saying it fits choose another ship to place
                        display.shipFitMessage(true);
                    }
                    else {//prompt saying it does not fit, do it again
                        display.shipFitMessage(false);
                    }
                }
            }
            //Ask if ship position is good
            display.drawPlayerGrid(players[i]);
            //Check if the player likes the positions
            display.shipPosCheckMessage();
            char again; //Hold choice to re-start ship placement
            again=in.inputLikePlacement();
            if(again=='y' || again=='Y') {  //player can enter either "y" or "Y"
                like=true;
            }
            else{
                like = false;
            }
        } 
    }
}

//Main menu
void Controller::mainMenu(){
    bool startMenu=true; //Bool for menu loop
    while(startMenu) {
        //Output Menu
        display.menu();
        int choice = 4;
        //Menu options
        switch(in.inputMenu(choice)) {
            case 0:
                display.quitMessage();
                startMenu = false;
                break;
            case 1:
                display.startTwoPlayerMessage();
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
