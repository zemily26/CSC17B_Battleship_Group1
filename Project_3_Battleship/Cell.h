
#ifndef CELL_H
#define CELL_H

class Cell {
public:
    Cell();
    Cell(const Cell& orig);
    virtual ~Cell();
    
void SetCell(bool hasShip);
void SetCell(bool hasShip,bool beenShot,bool hasHit);

bool HasShip();
bool HasBeenShot();
bool HasHit();

bool Shoot();

private:
    bool ship;
    bool shot;
    bool hit;
};

#endif /* CELL_H */

