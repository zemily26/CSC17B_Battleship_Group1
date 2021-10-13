
#include "Ship.h"

#include "Constants.h"

Ship::Ship() {
}

Ship::Ship(const Ship& orig) {
}

Ship::~Ship() {
}

//Setup ship with new values

void Ship::SetUp(int newx, int newy, int type, bool isSideways) {
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

bool Ship::IsShipOverlap(Ship b) {
    bool Overlapping = false;
    //
    //Check if lines Intersecting
    //
    if (sideways != b.sideways) {
        //Ship A sideways
        if (sideways) {
            //Check Intersection
            //Check X intersection
            if (b.x >= x && b.x <= x + size) {
                //Check Y intersection
                if (y >= b.y && y <= b.y + b.size) {
                    Overlapping = true;
                }
            }
        }            //Ship B sideways
        else {
            //Check Intersection
            //Check X intersection
            if (x >= b.x && x <= b.x + b.size) {
                //Check Y intersection
                if (b.y >= y && b.y <= y + size) {
                    Overlapping = true;
                }
            }
        }
    }        //
        //Check if lines are in-range
        //
    else {
        //<--> x axis check , If Sideways (both will always be sideways because of intersect check)
        if (y == b.y && sideways) {
            //see if overlapping
            if (x == b.x || x < b.x && x + size > b.x || b.x < x && b.x + b.size > x)
                Overlapping = true;
        }            //^|v y axis check , If Not Sideways (both will always not be sideways because of intersect check)
        else if (x == b.x&&!sideways) {
        }
        //see if overlapping
        if (y == b.y || y < b.y && y + size > b.y || b.y < x && b.y + b.size > y)
            Overlapping = true;
    }
    //Return Results.
    return Overlapping;
}