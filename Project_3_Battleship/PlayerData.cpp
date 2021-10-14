
#include "PlayerData.h"

#include "Constants.h"

PlayerData::PlayerData() {
}

PlayerData::PlayerData(const PlayerData& orig) {
}

PlayerData::~PlayerData() {
}

void PlayerData::CreateFleet() {
    fleet = new Ship[FLEET_SIZE];
}

//Places Ship on Player Board, 
//Returns Result
//-1 General Unsuccessful, -2 Overlapping, -3 Out of bounds , 1 Successful
int PlayerData::SetShip(int ship, int x, int y, bool sideways) {
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

void PlayerData::Destroy() {
    targetBoard.Destroy();
    playerBoard.Destroy();
    delete[] fleet;
}