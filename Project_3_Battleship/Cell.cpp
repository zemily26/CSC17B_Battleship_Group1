
#include "Cell.h"

Cell::Cell() {
    ship = false;
    shot = false;
    hit = false;
}

void Cell::SetCell(bool hasShip)
{
    ship = hasShip;
}

void Cell::SetCell(bool hasShip,bool beenShot,bool hasHit)
{
    ship = hasShip;
    shot = beenShot;
    hit = hasHit;
}

bool Cell::HasShip()
{
    return ship;
}

bool Cell::HasBeenShot()
{
    return shot;
}

bool Cell::HasHit()
{
    return hit;
}

bool Cell::Shoot()
{
    shot = true;
    if(ship)
        hit = true;
    return hit;
}
