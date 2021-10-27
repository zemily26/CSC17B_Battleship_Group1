/* 
 * File:   Cell.h
 * Purpose: Cell Class Specification
 */

#ifndef CELL_H
#define CELL_H

class Cell {
private:
    int     ship;  //Ship exists
    bool    shot;  //Ship has been shot
    bool    hit;   //Ship has been hit
public:
    Cell();                 //Constructor
    void resetCell();       //Reset Cell
    void HasShip(int);      //Return hasShip
    void HasBeenShot(bool); //Return HasBeenShot
    void HasHit();          //Return the cells hit status
    bool returnShot();      //Return shot
    int returnShip();       //Return ship
    bool returnHit();       //Return hit
};

#endif /* CELL_H */