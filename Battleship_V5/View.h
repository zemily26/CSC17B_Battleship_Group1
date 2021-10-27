#ifndef VIEW_H
#define VIEW_H
#include "Controller.h"


class View {
public:
    void drawGrids(Data *, int);
    void drawSymbolsKey();
    void menu();
    void rules();
    void userInputError();
    void coordinatePrompt();
    void directionPrompt();
    void playerNamePrompt();
    void shipMessage();
    void verifyShipPos();
    void endMessage();
    void leaderboard();
};
#endif /* VIEW_H */

