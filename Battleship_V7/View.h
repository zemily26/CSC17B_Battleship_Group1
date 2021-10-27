/* 
 * File:   View.h
 * Purpose: View Class Specification
 */

#ifndef VIEW_H
#define VIEW_H
#include "PlayerData.h"

class View {
public:
    View();
    void drawSymbolsKey();          //Output Symbol Key
    void menu();                    //Output Menu Message
    void rules();                   //Output Rules
    void userInputError();          //Output Input Error Message
    void coordinatePrompt();        //Prompt for Coordinates
    void directionPrompt();         //Prompt for Orientation Direction
    void playerNamePrompt(int);     //Prompt for Player Name
    void drawPlayerGrid(PlayerData);//Output One Player's Grid
    void shipFitMessage(bool);      //Output Ship Fit Message
    void shipPosCheckMessage();     //Prompt for Ship Position Check
    void quitMessage();             //Output Menu Quit Message
    void startTwoPlayerMessage();   //Output Two Player Start Game Message
};

#endif /* VIEW_H */

