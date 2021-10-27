#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include "Grid.h"
#include "FileData.h"

class PlayerData {
private:
    Grid *gridData;   
    char *playerName;
    int shipType[5] = {2,3,3,4,5};
public:
    PlayerData();
    ~PlayerData();
    void setPlayerName(char *);
    Grid *returnGridData();
    char *returnPlayerName();
};

#endif /* PLAYERDATA_H */