
#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include <string>

#include "Grid.h"

class PlayerData {
public:
    PlayerData();
    PlayerData(const PlayerData& orig);
    virtual ~PlayerData();
    void Destroy();
private:
    Grid targetBoard;
    Grid playerBoard;
    //Ship* ships To-Do, Add Dynamic Array of Ships
    std::string playerName;
};

#endif /* PLAYERDATA_H */

