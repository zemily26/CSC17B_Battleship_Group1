#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include "Grid.h"
#include "FileData.h"

class PlayerData {
private:
    const int BOARD_WIDTH = 8;
    const int BOARD_HEIGHT = 8;
public:
    Data *data;
    PlayerData();
    ~PlayerData();
    void allocateBoard(int);
    void ResetBoard(int);
    
};


#endif /* PLAYERDATA_H */