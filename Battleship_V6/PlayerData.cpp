
#include "PlayerData.h"

PlayerData::PlayerData(){
    gridData = new Grid;
    playerName = new char;
}

Grid *PlayerData::returnGridData(){
  return gridData;
}

char *PlayerData::returnPlayerName(){
    return playerName;
}

PlayerData::~PlayerData(){
    delete gridData;
    delete playerName;
}

void PlayerData::setPlayerName(char * input){
    playerName = input;
}