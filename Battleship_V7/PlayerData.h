/* 
 * File:   PlayerData.h
 * Purpose: PlayerData Class Specification
 */

#ifndef PLAYERDATA_H
#define PLAYERDATA_H
#include "Grid.h" //Grid Class header file

class PlayerData {
private:
    Grid *gridData;   //Hold a player's grid
    char *playerName; //Hold a player's name
    int  *shipHealth;  //Hold ship health
public:
    PlayerData();                   //Constructor
    ~PlayerData();                  //Destructor
    void setPlayerName(char *);     //Set Player's Name
    char *returnPlayerName();       //Return Player's Name
    void resetGrid();               //Reset Player's Grid
    Grid *returnGrid();             //Return Player's Grid
    void shootCoordinate(int *);    //Update cell that has been shot
    void updateGrid(Grid *);        //Update Player's Grid
};


#endif /* PLAYERDATA_H */

