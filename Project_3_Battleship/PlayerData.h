
#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include <string>

#include "Grid.h"
#include "Ship.h"

class PlayerData {
public:
    PlayerData();
    PlayerData(const PlayerData& orig);
    virtual ~PlayerData();
    
    void CreateFleet();
    int SetShip(int ship, int x, int y, bool sideways);
    
    void Destroy();
private:
    Grid targetBoard;
    Grid playerBoard;
    Ship* fleet;
    std::string playerName;
};

#endif /* PLAYERDATA_H */

