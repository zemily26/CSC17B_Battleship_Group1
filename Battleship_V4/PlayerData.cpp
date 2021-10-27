#include "PlayerData.h"
#include "Constants.h"
/*
PlayerData::PlayerData() {
  
}

PlayerData::PlayerData(const PlayerData& orig) {
}

//Destructor: Delete all dynamically allocated data
PlayerData::~PlayerData() {
  delete [] fleet;
}

void PlayerData::CreateFleet() {
    fleet = new Ship[FLEET_SIZE];
}

//Places Ship on Player Board, 
//Returns Result
//-1 General Unsuccessful, -2 Overlapping, -3 Out of bounds , 1 Successful
// change sideways to orientation of ship
int PlayerData::SetShip(int ship, int *cords, bool sideways) {
    int result = -1;
    //FIRST CHECK IF IN BOUNDS
    if (x < BOARD_WIDTH && y < BOARD_HEIGHT) {
        if (sideways && x + SHIP_SIZE[ship] < BOARD_WIDTH || !sideways && y + SHIP_SIZE[ship] < BOARD_HEIGHT) {
            //is in bounds
            fleet[ship].SetUp(x, y, ship, sideways);
            for (int i = ship - 1; i >= 0; i--) {
                //check if previous ships overlap
                if (fleet[ship].IsShipOverlap(fleet[i])) {
                    //overlapping
                    result = -2;
                    break;
                }
                //successfully placed ship
                result = 1;
                //draw to board
                for (int i = 0; i < SHIP_SIZE[ship]; i++) {
                    //cell set to have ship.       
                    if (sideways) {
                        //X axis
                        playerBoard.GetCell(x+i,y).SetCell(true);
                    } else {
                        //Y axis
                        playerBoard.GetCell(x,y+i).SetCell(true);
                    }
                }
            }
        }
    } else {
        //out of bounds
        result = -3;
    }
    return result;
}


Cell *PlayerData::getCell(int plyr, int col, int row){
    if(plyr==0){ //0 is player
      return playerBoard.GetCell(col,row);
    }
    else{ //any other number is target
      return targetBoard.GetCell(col,row);
    }
}

void PlayerData::Destroy() {
    targetBoard.Destroy();
    playerBoard.Destroy();
    delete[] fleet;
}
*/
data PlayerData::returnPlayerData(){
  return data;
}