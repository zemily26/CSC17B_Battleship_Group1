/* 
 * File:   PlayerData.cpp
 * Purpose: PlayerData Class Function Definitions
 */

#include "PlayerData.h"

//Constructor
PlayerData::PlayerData() {
    gridData = new Grid;
    playerName = new char;
    shipHealth = new int;
}

//Destructor
PlayerData::~PlayerData() {
    delete gridData;
    delete playerName;
    delete shipHealth;
}

//Set Player Name
void PlayerData::setPlayerName(char *input) {
    playerName = input;
}

//Return Player Name
char *PlayerData::returnPlayerName() {
    return playerName;
}

//Reset player's grid
void PlayerData::resetGrid() {
    gridData->ResetBoard();
}

//Return player's grid
Grid *PlayerData::returnGrid() {
    return gridData;
}

//Update cell that has been shot
void PlayerData::shootCoordinate(int *cords) {
    gridData->Update(cords);
}

//Update grid
void PlayerData::updateGrid(Grid *a) {
    gridData = a;
}