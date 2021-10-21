
#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include <string>
#include "Grid.h"
#include "Ship.h"

class PlayerData {
private:
    Grid targetBoard;
    Grid playerBoard;
    Ship* fleet;
    std::string playerName;
public:
    PlayerData();    
    ~PlayerData();
    void CreateFleet();
    int SetShip(int ship, int x, int y, bool sideways);
    void Destroy();
    void setPlayerName(std::string name);
    std::string getPlayerName();
};

#endif /* PLAYERDATA_H */

