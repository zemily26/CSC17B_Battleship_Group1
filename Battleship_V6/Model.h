#ifndef MODEL_H
#define MODEL_H

#include "PlayerData.h"

class Model{
private:
    int playerNum;
    //Do turn counter
public:
    PlayerData player[2];
    Model();
    PlayerData returnPlayerData(int);
    void updatePlayerGrid(int *);
    repeatedCoordinates(int *);
    bool shipFits(int *, int, int, int);
    void placeShips(int *, int, int, int);
    //shooting function, if hit = true, go again
    //win condition check playerdata shiptype[5] array
};
#endif /* MODEL_H */