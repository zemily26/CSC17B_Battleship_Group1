#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool ship;  //Ship exists
    bool shot;  //Ship has been shot
    bool hit;   //Ship has been hit
public:
    void SetCell(bool hasShip,bool beenShot,bool hasHit);
    void HasShip(bool);
    void HasBeenShot(bool);
    void HasHit();
    bool returnShot();
    bool returnShip();
    bool returnHit();
};
#endif /* CELL_H */
