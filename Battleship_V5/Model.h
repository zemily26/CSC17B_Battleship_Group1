#ifndef MODEL_H
#define MODEL_H

#include "PlayerData.h"

class Model{
private:
    int playerNum;
    PlayerData player[2];
public:
    Model();
    PlayerData returnPlayerData(int);
    
};
#endif /* MODEL_H */