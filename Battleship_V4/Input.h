//User Input VERSION 2 ANDREW ROBLEDO OCT 10 2021

#ifndef INPUT_H
#define INPUT_H

#include <iostream> //std::cout std::cin
#include <string>   //std::string
#include <cstring>  //std::strlen()
#include <ctype.h>  //std::toupper()
#include "Controller.h"
using namespace std;


class Input {
public:

    int *inputCoordinates(char);
    int inputUserSetUp(); //changed to int to chose up, down, left, right
    char *inputPlayerData(); //Input name into char array
    int inputMenu(char,int);

private:
    //InputState state;
    View display;
    int size = 4;
    char *input;
    //int bufferLength;
};

//Andrew's Section of inputCoordinates
/*
enum InputState {
    Waiting, Command, Position, Phrase
};

    Input();
    Input(const Input& orig);
    ~Input();
    bool ListenInput(char *buffer);
    bool GetUserInput();
    void ThrowWarning();
    char GetCommand();
    int *GetPosition();
    char *GetPhrase();
    void RunTest();
    */
#endif /* INPUT_H */