#ifndef INPUT_H
#define INPUT_H
#include "Controller.h"

class Input {    
public:
    Input();
    char *inputPlayerData(); //Input name into char array
    int inputUserSetUp();
    int *inputCoordinates();
    int inputMenu();
private:
    int size = 4;
    char menuInput;
    char *input;
};

#endif /* INPUT_H */