
#ifndef MODEL_H
#define MODEL_H

#include "PlayerData.h"

class Model {
public:
    Model();
    Model(const Model& orig);
    virtual ~Model();
    
    void SetupModel(bool hasAI);
    void Destroy();
private:
    PlayerData* players;
    int currentTurn;
    int numberTurns;
    bool ai;
};

#endif /* MODEL_H */

