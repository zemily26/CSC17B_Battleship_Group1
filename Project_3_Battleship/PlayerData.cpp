
#include "PlayerData.h"

PlayerData::PlayerData() {
}

PlayerData::PlayerData(const PlayerData& orig) {
}

PlayerData::~PlayerData() {
}

void PlayerData::Destroy()
{
    targetBoard.Destroy();
    playerBoard.Destroy();
    //delete[] ships; To-Do, Add Dynamic Array of Ships
}