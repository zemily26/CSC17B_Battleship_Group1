//User Input VERSION 2 ANDREW ROBLEDO OCT 10 2021
//Edited By :
//

//  Input input;
//  input.Destroy();

//Make sure to used Destroy on this class.

#ifndef INPUT_H
#define INPUT_H

#include <iostream> //std::cout std::cin
#include <string>   //std::string
#include <cstring>  //std::strlen()
#include <ctype.h>  //std::toupper()

enum InputState {
    Waiting, Command, Position, Phrase
};

class Input {
public:
    Input();
    Input(const Input& orig);
    virtual ~Input();
    bool ListenInput(char *buffer);
    bool GetUserInput();
    void ThrowWarning();
    char GetCommand();
    int *GetPosition();
    char *GetPhrase();
    
    void RunTest();
    void Destroy();

private:
    InputState state;
    const int bufferSize = 256;
    char *buffer;
    int bufferLength;
};

#endif /* INPUT_H */

