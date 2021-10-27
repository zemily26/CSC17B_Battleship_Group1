/* 
 * File:   Grid.h
 * Purpose: Grid Class Specification
 */

#ifndef GRID_H
#define GRID_H
#include "Cell.h" //Cell Class header file

class Grid {
    const int gridSize=8;             //Height and Width of board
    Cell **board;             //Game board
public:
    Grid();                         //Constructor
    ~Grid();                        //Destructor
    void CreateBoard();             //Allocate Memory and Fill Board
    void ResetBoard();              //Reset Board
    void Update(int *);             //Update a cell
    bool returnCellShot(int, int);  //Return shot on a cell
    int returnCellShip(int, int);   //Return ship on a cell
    void addCellShip(int, int, int);//Set ship on a cell
};

#endif /* GRID_H */

