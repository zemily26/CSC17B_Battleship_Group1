
#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool ship;  //Ship exists
    bool shot;  //Ship has been shot
    bool hit;   //Ship has been hit
public:
    Cell();
    void SetCell(bool hasShip);
    void SetCell(bool hasShip,bool beenShot,bool hasHit);
    bool HasShip();
    bool HasBeenShot();
    bool HasHit();
    bool Shoot();
};

#endif /* CELL_H */

