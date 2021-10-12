
#include "PlayerData.h"

PlayerData::PlayerData() {
}

PlayerData::PlayerData(const PlayerData& orig) {
}

PlayerData::~PlayerData() {
}

PlayerData::Destroy()
{
    targetBoard.Destroy();
    playerBoard.Destroy();
}