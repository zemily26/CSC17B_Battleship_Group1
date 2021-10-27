#ifndef INPUT_H
#define INPUT_H
#include "View.h"

class Input {    
private:
    int size = 4;
    char *input;     
public:
    int *inputCoordinates();
    int inputUserSetUp(); //changed to int to chose up, down, left, right
    char *inputPlayerData(); //Input name into char array
    int inputMenu(int);
    View inputDisplay;
    ~Input();
};

#endif /* INPUT_H */