#include "Model.h"
#include "Constants.h"

Model::Model(){
    playerNum = 0;
}
PlayerData Model::returnPlayerData(int playerNum){
    return player[playerNum];
}

bool Model::shipFits(int *array, int direction, int ship, int pnum){
    bool hasSpace = false;
    if (returnPlayerData(pnum).returnGridData()->board[array[0]][array[1]].returnShip() == 0){
        int sum = 0;
        switch(direction){
            case 1: 
                for (int i = 1; i < SHIP_SIZE[ship]; i++){
                    sum = array[1] - i;
                    if(returnPlayerData(pnum).returnGridData()->board[array[0]][sum].returnShip() == 0 || sum >= 0){
                        hasSpace == true;
                    }     
                    else{
                        hasSpace == false;
                        return hasSpace;
                    }   
                }
                return hasSpace;
                break;
            case 2: 
                for (int i = 1; i < SHIP_SIZE[ship]; i++){
                    sum = array[0] + i;
                    if(returnPlayerData(pnum).returnGridData()->board[sum][array[1]].returnShip() == 0 || sum <= 7){
                        hasSpace == true;
                    }     
                    else{
                        hasSpace == false;
                        return hasSpace;
                    }   
                }
                return hasSpace;
                break;
            case 3: 
                for (int i = 1; i < SHIP_SIZE[ship]; i++){
                    sum = array[1] + i;
                    if(returnPlayerData(pnum).returnGridData()->board[array[0]][sum].returnShip() == 0 || sum <= 7){
                        hasSpace == true;
                    }     
                    else{
                        hasSpace == false;
                        return hasSpace;
                    }   
                }
                return hasSpace;
                break;
            case 4: 
                for (int i = 1; i < SHIP_SIZE[ship]; i++){
                    sum = array[0] - i;
                    if(returnPlayerData(pnum).returnGridData()->board[sum][array[1]].returnShip() == 0 || sum >= 0){
                        hasSpace == true;
                    }     
                    else{
                        hasSpace == false;
                        return hasSpace;
                    }   
                }
                return hasSpace;
                break;
            default: {return hasSpace = false;} break;     
        }
    }
    else{
        return hasSpace = false;
    }
}

void Model::placeShips(int *array, int direction, int ship, int pnum){
    switch(direction){
            case 1: 
                for (int i = 1; i < SHIP_SIZE[ship]; i++){
                    returnPlayerData(pnum).returnGridData()->board[array[0]][array[1] - i].HasShip(ship);
                }
                break;
            case 2: 
                for (int i = 1; i < SHIP_SIZE[ship]; i++){
                    returnPlayerData(pnum).returnGridData()->board[array[0] + i][array[1]].HasShip(ship);
                }
                break;
            case 3: 
                for (int i = 1; i < SHIP_SIZE[ship]; i++){
                    returnPlayerData(pnum).returnGridData()->board[array[0]][array[1] + i].HasShip(ship);
                }
                break;
            case 4: 
                for (int i = 1; i < SHIP_SIZE[ship]; i++){
                    returnPlayerData(pnum).returnGridData()->board[array[0]- i][array[1]].HasShip(ship);
                }
                break;
            default: break;
    }
}