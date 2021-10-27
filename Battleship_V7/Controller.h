/* 
 * File:   Controller.h
 * Purpose: Controller Class Specification
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Input.h"      //Input Class header file
#include "Model.h"      //Model Class header file
#include "View.h"       //View Class header file
#include "PlayerData.h" //PlayerData Class header file

class Controller {
private:
    char userInput;             //Hold user input
    const int numPlayers = 2;   //Hold number of players
    PlayerData *players;        //Pointer to array of players
public:
    Controller();   //Constructor
    Model pdata;    //Model object to hold player data
    View display;   //View object for output
    Input in;       //Input object for input
    void setUp();   //Game setup
    void mainMenu();//Main menu
};


#endif /* CONTROLLER_H */

