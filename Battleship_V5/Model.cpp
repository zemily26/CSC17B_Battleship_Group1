#include "Model.h"

Model::Model(){
    playerNum = 0;
}
PlayerData Model::returnPlayerData(int playerNum){
    return player[playerNum];
}