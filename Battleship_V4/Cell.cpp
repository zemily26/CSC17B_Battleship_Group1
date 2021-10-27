#include "Cell.h"

Cell::Cell() {
    ship = false;
    shot = false;
    hit = false;
}

void Cell::SetCell(bool hasShip,bool beenShot,bool hasHit)
{
    ship = hasShip;
    shot = beenShot;
    hit = hasHit;
}

void Cell::HasShip(bool hasShip)
{
    ship = hasShip;
}

void Cell::HasBeenShot(bool beenShot)
{
    shot = beenShot;
}

void Cell::HasHit()
{
    if(ship && shot){hit = true;}
}

bool Cell::returnShip() { return ship;}
bool Cell::returnShot() { return shot;}
bool Cell::returnHit() { return hit;}

