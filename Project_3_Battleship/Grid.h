
#ifndef GRID_H
#define GRID_H

#include "Cell.h"

class Grid {
private:
    Cell** board;
    void CreateBoard();
public:
    Grid();
    ~Grid();
    Cell& GetCell(int col,int row); // X , Y Format
    void Destroy(); 
};

#endif /* GRID_H */

