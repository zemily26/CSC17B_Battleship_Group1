#ifndef GRID_H
#define GRID_H

#include "Cell.h"

class Grid {
public:
    Cell **board;
    void CreateBoard();
    Grid();
    ~Grid();
    void ResetBoard();
    void Update(int *);
};

#endif /* GRID_H */
