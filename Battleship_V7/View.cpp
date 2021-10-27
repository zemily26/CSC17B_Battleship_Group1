/* 
 * File:   View.cpp
 * Purpose: View Class Function Definitions
 */

#include <iostream> //I/O Stream library
using namespace std;//Standard namespace
#include "View.h"   //View Class header file

View::View(){}

//Output one player's grid
void View::drawPlayerGrid(PlayerData playerdata){
    //Output Player number n's name
    cout << playerdata.returnPlayerName() << "'s Grid:" << endl;      
    //Draw current player's Grid        
    cout <<"     X   1   2   3   4   5   6   7   8"<< endl;
    cout <<"   Y +-----------------------------------+"<< endl;
    //Loop for grid output
    for(int row = 0; row < 8; row++){          
        //Output Y value letters    
        cout << "   " << static_cast<char> ('A' + row) << " |   ";
        //Loop for contents of the row
        for(int col = 0; col < 8; col++){
            //Character for outputting specific symbol needed
            char cellsymbol;
            //Check if cell "Shot" is true
            if(playerdata.returnGrid()->returnCellShot(col, row)) { //Changed some variables into public for access
                if(playerdata.returnGrid()->returnCellShip(col, row) != 0){ //If the cell has a ship
                    cellsymbol = '!';          
                }
                else{  //If the cell doesn't have a ship
                    cellsymbol = '0';          
                }
            }
            else{ //If the cell hasn't been shot
                if(playerdata.returnGrid()->returnCellShip(col, row) != 0){ //If the cell has a ship
                    switch(playerdata.returnGrid()->returnCellShip(col, row)){
                        case 1 : cellsymbol = '1'; break;
                        case 2 : cellsymbol = '2'; break;
                        case 3 : cellsymbol = '3'; break;
                        case 4 : cellsymbol = '4'; break;
                        case 5 : cellsymbol = '5'; break; 
                    };
                }
                else{ //If the cell doesn't have a ship
                    cellsymbol = '-';           
                }
            }
            cout << cellsymbol << "   ";
        }
        cout<<"|"<<endl;
        if(row == 8 - 1){
            cout<<"     +-----------------------------------+"<<endl;
        }
    }
}

//Output menu message
void View::menu() {
    cout << "0 - Exit" << endl;
    cout << "1 - Play" << endl;
    cout << "2 - Rules" << endl;
    cout << "3 - Stats" << endl;
    cout << "4 - Leaderboards"<< endl;
    cout << "Input: ";
}
  
//Output input error message
void View::userInputError(){
  cout << "User input is invalid! Try Again: " << endl;
}

//Prompt for coordinates
void View::coordinatePrompt(){
  cout<< "Format is \"A1\"" << endl
      << "Assume \"A\" is on the Y Axis. \"1\" is on the X Axis." << endl
      << "Input the coordinates of your choice..." << endl
      << "Enter Input: ";
}

//Prompt for orientation direction
void View::directionPrompt(){
  cout << "Which direction would you like to put your ship?" << endl;
  cout << "U = Up" << endl;
  cout << "D = Down" << endl;
  cout << "L = Left" << endl;
  cout << "R = Right" << endl;
  cout << "Input (U/D/L/R): ";
}

//Prompt for player name
void View::playerNamePrompt(int playerNum){
    cout<<"Enter Player "<<playerNum+1<<" Name: ";
}

//Output ship fit message
void View::shipFitMessage(bool fits){
    if(fits)
        cout << "The Ship Fits, choose another coordinate..." << endl;
    else
        cout << "The Ship does NOT Fit, choose another coordinate..." << endl;
}

//Prompt for Ship Position Check 
void View::shipPosCheckMessage(){
    cout << "Do you like how your ships are set up? (y/n): ";
}

//Quit Menu Message
void View::quitMessage(){
    cout<<"Exiting..."<<endl;
}

//Output Two Player Start Message
void View::startTwoPlayerMessage(){
    cout<<"\tTWO PLAYER BATTLESHIP!"<<endl;
}

//Output Rules Message
void View::rules() {
    cout << "The Rules are simple..." << endl;
    cout << "1. Both players secretly place their 5 ships on the ocean grid." << endl;
    cout << "   a. Ships must be horizontal or vertical, NO DIAGONAL!" << endl;
    cout << "   b. Ships must be in coordinates given, not past them." << endl;
    cout << "   c. Ships' position can NOT be changed when the game starts." << endl;
    cout << "2. Player No.1 shoots first then PLayer No.2." << endl;
    cout << "   a. Player will keep shooting, if they HIT a ship." << endl;
    cout << "   b. Players will alternate turns, if they MISS a ship." << endl;
    cout << "3. To call a shot, Players must input the coordinates on the ocean grid." << endl;
    cout << "   a. Example: A1, B2, or (Letter)(Number)." << endl;
    cout << "4. Coordinates with ships on them will be marked on the map." << endl;
    cout << "   a. 'S' if it is occupied and has not been shot yet" << endl;
    cout << "   b. '0' if it is occupied and has been shot at." << endl;
    cout << "5. Coordinates without a ship on them will be marked on the map." << endl;
    cout << "   a. '-' if it is empty and has not been shot yet." << endl;
    cout << "   b. '0' if it is empty and has been shot at." << endl;
    cout << "6. Win by being the first person to sink all 5 of the opponent's ships." << endl;
}