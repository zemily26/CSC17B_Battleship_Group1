
#ifndef GRID_H
#define GRID_H

#include "Cell.h"

class Grid {
public:
    Grid();
    Grid(const Grid& orig);
    virtual ~Grid();
    
    // X , Y Format
    Cell& GetCell(int col,int row);
    
    void Destroy();
private:
    Cell** board;
    void CreateBoard();
};

#endif /* GRID_H */

