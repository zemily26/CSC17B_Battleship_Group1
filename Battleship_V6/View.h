#ifndef VIEW_H
#define VIEW_H
#include "PlayerData.h"

class View {
public:
    void drawGrids(PlayerData);
    void drawSymbolsKey();
    void menu();
    void rules();
    void userInputError();
    void coordinatePrompt();
    void directionPrompt();
    void playerNamePrompt();
    void badfit();
};

#endif /* VIEW_H */

