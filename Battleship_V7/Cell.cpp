/* 
 * File:   Cell.cpp
 * Purpose: Cell Class Function Definitions
 */

#include "Cell.h" //Cell Class Header File

//Constructor
Cell::Cell() { 
    ship = 0;
    shot = false;
    hit = false;
}

//Reset Cell
void Cell::resetCell() { 
    ship = 0;
    shot = false;
    hit = false;
}

//Set hasShip
void Cell::HasShip(int hasShip) { 
    ship = hasShip;
}

//Set HasBeenShot
void Cell::HasBeenShot(bool beenShot) {
    shot = beenShot;
}

//Set the cells hit status
void Cell::HasHit() {
    if(ship != 0 && shot){ //If ship is not empty and has been shot
        hit = true; //Return true
    }
}

//Return ship
int Cell::returnShip() {
    return ship;
}
//Return shot
bool Cell::returnShot() { 
    return shot;
}

//Return hit
bool Cell::returnHit(){ 
    return hit;
}