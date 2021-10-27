/* 
 * File:   Input.h
 * Purpose: Input Class Specification
 */

#ifndef INPUT_H
#define INPUT_H
#include "View.h" //View Class header file

class Input {    
private:
    int size, nameSize;     //Size of coordinate and name arrays
    char *input, *name;     //To hold coordinate input and name input
public:
    Input();                    //Constructor
    ~Input();                   //Destructor
    int *inputCoordinates();    //Coordinate Input
    int inputUserSetUp();       //Setup Input
    char *inputPlayerData();    //Name Input
    int inputMenu(int);         //Menu Input
    View inputDisplay;          //For output messages
    char inputLikePlacement();  //Placement like input
};

#endif /* INPUT_H */

