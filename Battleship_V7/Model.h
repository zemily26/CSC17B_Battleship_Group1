/* 
 * File:   Model.h
 * Purpose: Model Class Specification
 */

#ifndef MODEL_H
#define MODEL_H
#include "PlayerData.h" //PlayerData class header file

class Model{
private:
    int shipSize[5]= {5, 4, 3, 3, 2}; //Hold ship sizes
    int shipType[5]= {5, 4, 3, 2, 1}; //Hold ship types
public:
    Model(); //Constructor
    bool shipFits(Grid *, int *, int, int);   //Verify Ship Fit
    Grid *placeShips(Grid *, int *, int, int);//Place ships
};

#endif /* MODEL_H */

