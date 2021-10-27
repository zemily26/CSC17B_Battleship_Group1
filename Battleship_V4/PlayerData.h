#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include <string>
#include "Grid.h"
#include "Ship.h"
#include "Model.h"
#include "Data.h"
using namespace std;

class PlayerData {
private:
    Data *data;
public:
    //PlayerData();    
    //~PlayerData();
    //void CreateFleet();
    //int SetShip(int ship, int *cords, bool sideways);
    //void Destroy();
    Data *getPlayerData();
    Data *returnPlayerData();
};

#endif /* PLAYERDATA_H */