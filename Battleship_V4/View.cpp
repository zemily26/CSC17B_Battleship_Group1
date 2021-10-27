#include "View.h"
#include "Constants.h"
#include <iostream>
#include <iomanip>

View::View() {
}

//Call this function with the int 0 or 1, 0=player1 and 1=player2
void View::drawGrids(Data *playerdata, int player){
    //Output Player number n's name
    cout << playerdata[player].playerName << "'s Display:" << endl;      
    //Draw current player's Grid        
    cout<<"     X   1   2   3   4   5   6   7   8"<<endl;
    cout<<"   Y +-----------------------------------+"<<endl;
    //Loop for grid output
    for(int row = 0; row < BOARD_HEIGHT; row++){          
        //Output Y value letters    
        cout << "   " << static_cast<char> ('A' + row) << " |   ";
        //loop for contents of the row
        for(int col = 0; col<BOARD_WIDTH; col++){
          //Character for outputing specific symbol needed
          char cellsymbol;
          //Check if cell "Shot" is true
          if(playerdata[player].targetBoard.board[row][col].returnShot()) { //Changed some variables into public for access
              if(playerdata[player].targetBoard.board[row][col].returnShip()){ //If the cell has a ship
                  cellsymbol = Hit;          
              }
              else{  //If the cell doesn't have a ship
                  cellsymbol = Miss;          
              }
          }
          else{ //If the cell hasn't been shot
              if(playerdata[player].targetBoard.board[row][col].returnShip()){ //If the cell has a ship
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
    cout<<"\nTarget Display:"<<endl;                 
    cout<<"     X   1   2   3   4   5   6   7   8"<<endl;
    cout<<"   Y +-----------------------------------+"<<endl;
    for(int row=0; row<BOARD_HEIGHT; row++){      
        //Output Y value letters            
        cout<<"   "<<static_cast<char>('A' + row)<<" |   ";
        //Loop for contents
        for(int col=0; col<BOARD_WIDTH; col++){
          char cellsymbol; //Hold the symbol to print
          //See if target board has ship by returning bool value
          if(playerdata[player].targetBoard.board[row][col].returnShot()){ //If the cell has been shot
              if(playerdata[player].targetBoard.board[row][col].returnShip()){ //If the cell has a ship
                  cellsymbol = Hit;          
              }
              else{ //If the cell doesn't have a ship
                  cellsymbol = Miss;          
              }
          }
          else{ //If the cell hasn't been shot              
                  cellsymbol = Empty;           
          }
          cout<< cellsymbol <<"   ";
        }
        cout<<"|"<<endl;
        if(row == BOARD_WIDTH - 1){
            cout<<"     +-----------------------------------+"<<endl;
        }
    }
}

void View::drawSymbolsKey(){
  for(int i=0; i<27; i++) cout<<"*";
    cout<<endl;
    cout<<"*"<<"\tSymbol Key:"<<right<<setw(8)<<"*"<<endl;
    cout<<"*"<<right<<setw(10)<<"Empty: "<<static_cast<char>(Empty)
        <<right<<setw(10)<<"Hit: "<<static_cast<char>(Hit)<<setw(4)<<"*"<<"\n"
        <<left<<"*"<<right<<setw(10)<<"Ship: "<<static_cast<char>(Ship)
        <<right<<setw(10)<<"Miss: "<<static_cast<char>(Miss)<<setw(4)<<"*"<<endl;
    for(int i=0; i<27; i++) cout<<"*";
    cout<<endl;
}

void View::menu() {
  cout << "1 - Play" << endl << "2 - Rules" << endl << "3 - Stats" << endl << "4 - Leaderboards";
}
  
void View::userInputError(){
  cout << "User input is invalid! Try Again: ";
}