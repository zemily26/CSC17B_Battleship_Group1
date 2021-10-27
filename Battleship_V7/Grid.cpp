/* 
 * File:   Grid.cpp
 * Purpose: Grid Class Function Definitions
 */

#include "Grid.h"

Grid::Grid() {//Constructor
  //Allocate dynamic array for board
  CreateBoard();
  //Sets values of board to 0
  ResetBoard();
}

//Destructor
Grid::~Grid(){
//Delete allocated memory
    /*
    for(int i=0; i<gridSize; i++){
        for(int j=0; j<gridSize; j++){
            delete board[i*j];
        }
    }
    delete board;*/
}
   

//Allocate Memory and Fill Board
void Grid::CreateBoard() {
    board = new Cell*[gridSize];
    for (int i = 0; i < gridSize; i++) {
        board[i] = new Cell[gridSize];
    }
}

//Reset Board
void Grid::ResetBoard(){
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            //Board uses functions to manipulate data types
            board[i][j].resetCell();
        }
    }
}

//Update a cell
void Grid::Update(int *cords) {
    board[cords[0]][cords[1]].HasBeenShot(true);
    board[cords[0]][cords[1]].HasHit();
}

//Return shot on a cell
bool Grid::returnCellShot(int x, int y) {
    return board[x][y].returnShot();
}

//Return ship on a cell
int Grid::returnCellShip(int x, int y) {
    return board[x][y].returnShip();
}

//Set ship on a cell
void Grid::addCellShip(int x, int y, int ship) {
    board[x][y].HasShip(ship);
}
