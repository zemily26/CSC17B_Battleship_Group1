
#include "View.h"
#include "Constants.h"
#include <iostream>
#include <iomanip>

View::View() {
}

void View::drawGrids(PlayerData *playerdata){
  //Draw current player's Grid
    cout<<playerdata->getPlayerName()<<"'s Display:"<<endl;              
    cout<<"     X   1   2   3   4   5   6   7   8"<<endl;
    cout<<"   Y +-----------------------------------+"<<endl;
    for(int row=0; row<BOARD_HEIGHT; row++){              
        cout<<"   "<<static_cast<char>('A' + row)<<" |   ";
        for(int col=0; col<BOARD_WIDTH; col++){
          char cellsymbol; //Hold the symbol to print
          //Create a pointer to the cell at targetBoard(col,row)
          Cell *cell = &playerdata->playerBoard.GetCell(col,row);
          if(cell->HasBeenShot()){ //If the cell has been shot
              if(cell->HasShip()){//If the cell has a ship
                  cellsymbol=Hit;          
              }
              else{//If the cell doesn't have a ship
                  cellsymbol=Miss;          
              }
          }
          else{//If the cell hasn't been shot
              if(cell->HasShip()){//If the cell has a ship
                  cellsymbol=Ship;          
              }
              else{//If the cell doesn't have a ship
                  cellsymbol=Empty;           
              }
          }
          cout<< cellsymbol <<"   ";
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
        cout<<"   "<<static_cast<char>('A' + row)<<" |   ";
        for(int col=0; col<BOARD_WIDTH; col++){
          char cellsymbol; //Hold the symbol to print
          //Create a pointer to the cell at targetBoard(col,row)
          Cell *cell = &playerdata->targetBoard.GetCell(col,row);
          if(cell->HasBeenShot()){ //If the cell has been shot
              if(cell->HasShip()){//If the cell has a ship
                  cellsymbol=Hit;          
              }
              else{//If the cell doesn't have a ship
                  cellsymbol=Miss;          
              }
          }
          else{//If the cell hasn't been shot              
                  cellsymbol=Empty;           
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
  



