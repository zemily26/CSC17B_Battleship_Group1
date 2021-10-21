
#include "Grid.h"
#include "Cell.h"

#include "Constants.h"

//Public::

Grid::Grid() {
    CreateBoard();
}

Grid::~Grid(){
    Destroy();
}

// X Y FORMAT 
Cell& Grid::GetCell(int col,int row){
    return board[col][row];
}

void Grid::Destroy() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        delete[] board[i];
    }
    delete[] board;
}

//Private::

void Grid::CreateBoard() {
    board=new Cell*[BOARD_WIDTH];
    for (int i = 0; i < BOARD_WIDTH; i++) {
        board[i] = new Cell[BOARD_HEIGHT];
    }
}
