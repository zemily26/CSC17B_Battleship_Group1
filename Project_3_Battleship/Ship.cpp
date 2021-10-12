
#include "Ship.h"

#include "Constants.h"

Ship::Ship() {
}

Ship::Ship(const Ship& orig) {
}

Ship::~Ship() {
}

//Setup ship with new values

void Ship::SetUp(int newx, int newy, ShipType type, bool isSideways) {
    x = newx;
    y = newy;
    size = SHIP_SIZE[type];
    sideways = isSideways;
    //hitpoints equal to size.
    hitpoints = size;
}

//Check if ship hitpoints is 0

bool Ship::IsDestoyed() {
    return hitpoints == 0;
}

//See if Shot Hit, Modify Data and return results.

bool Ship::CheckShot(int shotX, int shotY) {
    bool hit = false;
    //Ship is sideways, size x axis
    if (sideways) {
        //Check if shot is within bounds
        if (shotY == y && shotX >= x && shotX <= x + size)
            hit = true;
        //Ship is not sideways, size y axis
    } else {
        //Check if shot is within bounds
        if (shotX == x && shotY >= y && shotY <= y + size)
            hit = true;
    }
    //If Hit, Modify Hitpoints
    if (hit)
        hitpoints--;
    return hit;
}