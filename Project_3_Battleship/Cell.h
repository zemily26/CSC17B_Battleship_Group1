
#ifndef CELL_H
#define CELL_H

class Cell {
public:
    Cell();
    Cell(const Cell& orig);
    virtual ~Cell();
private:
    bool ship;
    bool shot;
    bool hit;
};

#endif /* CELL_H */

