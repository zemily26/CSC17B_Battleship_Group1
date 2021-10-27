#include "Grid.h"
#include "Constants.h"

Grid::Grid() {
  //Allocate dyanamic array for board
  CreateBoard();
  //Sets values of board to 0
  ResetBoard();
}

Grid::~Grid(){
  for (int i = 0; i < BOARD_WIDTH; i++) {
      delete[] board[i];
  }
  delete[] board;
}

//Declare and allocate memeroy for board
void Grid::CreateBoard() {
    board = new Cell*[BOARD_WIDTH];
    for (int i = 0; i < BOARD_WIDTH; i++) {
        board[i] = new Cell[BOARD_HEIGHT];
    }
}

void Grid::ResetBoard(){
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      //Board uses functions to manipulate data types
      board[i][j].SetCell(false,false,false);
    }
  }
}

void Grid::Update(int *cords) {
  board[cords[0]][cords[1]].HasBeenShot(true);
  board[cords[0]][cords[1]].HasHit();
}