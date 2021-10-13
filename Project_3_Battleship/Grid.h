
#ifndef GRID_H
#define GRID_H

#include "Cell.h"

class Grid {
public:
    Grid();
    Grid(const Grid& orig);
    virtual ~Grid();
    Cell& getCell(int row,int col);
    void Destroy();
private:
    Cell** board;
    void CreateBoard();
};

#endif /* GRID_H */

