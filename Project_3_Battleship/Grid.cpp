
#include "Grid.h"
#include "Cell.h"
#include "Constants.h"

//Public::

Grid::Grid() {
    CreateBoard();
}

Grid::Grid(const Grid& orig) {
}

Grid::~Grid() {
}

void Grid::Destroy() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        delete[] board[i];
    }
    delete[] board;
}

//Private::

void Grid::CreateBoard() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        board[i] = new Cell[BOARD_HEIGHT];
    }
}