#include "View.h"
#include "Constants.h"
#include <iomanip>
#include <iostream>
using namespace std;

//Call this function with the int 0 or 1, 0=player1 and 1=player2
void View::drawGrids(PlayerData playerdata){
    //Output Player number n's name
    cout << playerdata.returnPlayerName() << "'s Display:" << endl;      
    //Draw current player's Grid        
    cout <<"     X   1   2   3   4   5   6   7   8"<< endl;
    cout <<"   Y +-----------------------------------+"<< endl;
    //Loop for grid output
    for(int row = 0; row < BOARD_HEIGHT; row++){          
        //Output Y value letters    
        cout << "   " << static_cast<char> ('A' + row) << " |   ";
        //loop for contents of the row
        for(int col = 0; col<BOARD_WIDTH; col++){
          //Character for outputing specific symbol needed
          char cellsymbol;
          //Check if cell "Shot" is true
          if(playerdata.returnGridData()->board[row][col].returnShot()) { //Changed some variables into public for access
              if(playerdata.returnGridData()->board[row][col].returnShip()){ //If the cell has a ship
                  cellsymbol = Hit;          
              }
              else{  //If the cell doesn't have a ship
                  cellsymbol = Miss;          
              }
          }
          else{ //If the cell hasn't been shot
              if(playerdata.returnGridData()->board[row][col].returnShip()){ //If the cell has a ship
                  cellsymbol = Ship;          
              }
              else{ //If the cell doesn't have a ship
                  cellsymbol = Empty;           
              }
          }
          cout << cellsymbol << "   ";
        }
        cout<<"|"<<endl;
        if(row == BOARD_WIDTH - 1){
            cout<<"     +-----------------------------------+"<<endl;
        }
    }

    //Draw target's grid
    cout <<"\nTarget Display:"<< endl;                 
    cout <<"     X   1   2   3   4   5   6   7   8"<< endl;
    cout <<"   Y +-----------------------------------+"<< endl;
    for(int row=0; row<BOARD_HEIGHT; row++){      
        //Output Y value letters            
        cout <<"   "<<static_cast<char>('A' + row)<<" |   ";
        //Loop for contents
        for(int col=0; col<BOARD_WIDTH; col++){
          char cellsymbol; //Hold the symbol to print
          //See if target board has ship by returning bool value
          if(playerdata.returnGridData()->board[row][col].returnShot()){ //If the cell has been shot
              if(playerdata.returnGridData()->board[row][col].returnShip()){ //If the cell has a ship
                  cellsymbol = Hit;          
              }
              else{ //If the cell doesn't have a ship
                  cellsymbol = Miss;          
              }
          }
          else{ //If the cell hasn't been shot              
                  cellsymbol = Empty;           
          }
          cout << cellsymbol <<"   ";
        }
        cout << "|" << endl;
        if(row == BOARD_WIDTH - 1){
            cout <<"     +-----------------------------------+"<<endl;
        }
    }
}

void View::drawSymbolsKey(){
  for(int i=0; i<27; i++) cout<<"*";
    cout<<endl;
    cout<<"*"<<"\tSymbol Key:"<<right<<setw(8)<<"*"<<endl;
    cout<<"*"<<right<<setw(10)<<"Empty: "<<static_cast<char>(Empty);
    cout<<right<<setw(10)<<"Hit: "<<static_cast<char>(Hit);
    cout<<setw(4)<<"*"<<endl;
    cout<<left<<"*";
    cout<<right<<setw(10)<<"Ship: "<<static_cast<char>(Ship);
    cout<<right<<setw(10)<<"Miss: "<<static_cast<char>(Miss);
    cout<<setw(4)<<"*"<<endl;
    for(int i=0; i<27; i++) 
        cout<<"*";
    cout<<endl;
}

void View::menu() {
  cout << "1 - Play" << endl;
  cout << "2 - Rules" << endl;
  cout << "3 - Stats" << endl;
  cout << "4 - Leaderboards"<< endl;
}
  
void View::userInputError(){
  cout << "User input is invalid! Try Again: " << endl;
}

void View::coordinatePrompt(){
  cout<< "Format is \"A1\"" << endl
      << "Assume \"A\" is on the Y Axis. \"1\" is on the X Axis." << endl
      << "Input the coordinates of your choice..." << endl
      << "Enter Input: ";
}

void View::directionPrompt(){
  cout << "Which direction would you like to put your ship?" << endl;
  cout << "U = Up" << endl;
  cout << "D = Down" << endl;
  cout << "L = Left" << endl;
  cout << "R = Right" << endl;
  cout << "Input (U/D/L/R): ";
}

void View::playerNamePrompt(){
  cout << "Input Player name: ";
}

void View::verifyShipPos(){
  cout<<"Are you happy with the Ship position? (y or n): ";
}

void View::shipMessage(){
  cout<<"Ships are placed in order:"<<endl;
  cout<<"Aircraft Carrier (4 cells),";
  cout<<"Battleship (3 cells), ";
  cout<<"Battlecruiser (2 cells), ";
  cout<<"Submarine, Destroyer (1 cell)"<<endl;
}

void View::endMessage(){
  cout << "Thank you for playing!" << endl;
}

void View::leaderboard(){

}

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