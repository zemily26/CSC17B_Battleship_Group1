#ifndef VIEW_H
#define VIEW_H
#include "Controller.h"

class View {
public:
    View();
    void drawGrids(Data *, int);
    void drawSymbolsKey();
    void menu();
    void rules();
    void coordinatePrompt();
    void directionPrompt();
    void playerNamePrompt();
    void userInputError();
    void askQuit();
};