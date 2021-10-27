#include "Model.h"

#include "PlayerData.h"
using namespace std;

Model::Model() {
}

Model::Model(const Model& orig) {
}

Model::~Model() {
}

void Model::SetupModel(bool hasAI) {
    players = new PlayerData[2];
    ai = hasAI;
    currentTurn = 0;
    numberTurns = 0;
}

void Model::Destroy() {
    delete []players;
}