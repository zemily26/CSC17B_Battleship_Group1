#ifndef CELL_H
#define CELL_H

class Cell {
private:
    int ship;  //Ship exists
    bool shot;  //Ship has been shot
    bool hit;   //Ship has been hit
public:
    void SetCell(int hasShip,bool beenShot,bool hasHit);
    void HasShip(int);
    void HasBeenShot(bool);
    void HasHit();
    bool returnShot();
    int returnShip();
    bool returnHit();
};
#endif /* CELL_H */
