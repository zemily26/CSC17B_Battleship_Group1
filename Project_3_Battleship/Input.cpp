
#include "Input.h"
#include "Constants.h"

Input::Input() {
    state = Waiting;
    buffer = new char[bufferSize];
    bufferLength = 0;
}

Input::Input(const Input& orig) {
}

Input::~Input() {
}

//Returns True if able to grab line from Input.
//Should Lock Process Otherwise.

bool Input::ListenInput(char *buffer) {
    std::cin.getline(buffer, bufferSize);
    bufferLength = strlen(buffer);
    return (bufferLength > 0);
}

//Gets And Validates Input Based off Input State.

bool Input::GetUserInput() {
    bool valid = false;
    switch (state) {
        case Command://Command Input, Single Char
            valid = ListenInput(buffer);
            if (!valid)
                ThrowWarning();
            break;
        case Position://Position Input, "A 10" "A,10" "A 10"
            valid = ListenInput(buffer);
            if (valid) //"A10" "A,10" "A 10"
                if (bufferLength < 2 && bufferLength > 4)
                    valid = false;
            if (!valid)
                ThrowWarning();
            break;
        case Phrase:
            valid = ListenInput(buffer);
            if (!valid)
                ThrowWarning();
            break;
        default: // Input Waiting, Not Accepting Input.
            ThrowWarning();
            break;
    }
    return valid;
}

//Used for Debugging if Input is Not Valid.

void Input::ThrowWarning() {
    switch (state) {
        case Command://Command Input, Single Char
            std::cout << invalidWarning_Command << std::endl;
            break;
        case Position://Position Input, "A 10" "A,10" "A 10"
            std::cout << invalidWarning_Position << std::endl;
            break;
        case Phrase:
            std::cout << invalidWarning_Phrase << std::endl;
            break;
        default: // Input Waiting, Not Accepting Input.
            std::cout << invalidWarning_Waiting << std::endl;
            break;
    }
    std::cout << " Your Input :\"" << buffer << "\" length:" << bufferLength << std::endl;
}

//Returns Single Char from Input.
//Returns UpperCase when Possible.
//Char 'A'

char Input::GetCommand() {
    state = Command;
    //Input Loop, Probably should remove this, it will always be true.
    while (!GetUserInput()) {
    }
    return toupper(buffer[0]);
}

//Returns Position from Input.
//A Dynamic int Array [X,Y]

int *Input::GetPosition() {
    //Sets state to 'Position'
    state = Position;
    //Creates Dynamic Array with Position Input.
    int *input = new int[2];
    //Input Loop
    while (!GetUserInput()) {
    }
    //ASCII '0' comes directly before ASCII '1'
    //We can get the direct numeric value,
    //by subtracting the char by the starting value.
    //same can be done with the Alphabetical Char.
    if (bufferLength == 2) {
        //Example A1
        input[0] = buffer[1] - '0';
        input[0]--;
        input[1] = toupper(buffer[0]) - 'A';
    } else if (buffer[1] == ' ' || buffer[1] == ',') {
        if (bufferLength == 3) {
            //Example "1,A"  "1 A"
            input[0] = buffer[2] - '0';
            input[0]--;
            input[1] = toupper(buffer[0]) - 'A';
        } else if (bufferLength == 4) {
            //Example "A,10"  "A 10"
            input[0] = (buffer[2] - '0') * 10;
            input[0] += buffer[3] - '0';
            input[0]--;
            input[1] = toupper(buffer[0]) - 'A';
        }
    } else {
        //Example A10
        input[0] = (buffer[1] - '0') * 10;
        input[0] += buffer[2] - '0';
        input[0]--;
        input[1] = toupper(buffer[0]) - 'A';
    }
    return input;
}

//Returns Dynamic Char Array from Input.

char *Input::GetPhrase() {
    state = Phrase;
    char *input = new char[bufferLength];
    //Input Loop, Probably should remove this, it will always be true.
    while (!GetUserInput()) {
    }
    for (int i = 0; i < bufferLength; i++)
        input[i] = buffer[i];
    return input;
}

//INPUT TEST//
void Input::RunTest()
{
  int *posTest;
  char charTest, *phraseTest;
  std::cout << "Format is \"A1\" or \"A,10\" or \"A 10\"\n";
  std::cout << "Assume \"A\" is on the Y Axis. \"1\" is on the X Axis.\n";
  std::cout << "Input a position :";
  posTest = GetPosition();
  std::cout << "A Command is a Menu Option, a Single char for example (Y) (N) \n";
  std::cout << "Input a Command :";
  charTest = GetCommand();
  std::cout << "A Phrase is a string, for example \"Your Name\"\n";
  std::cout << "Input a Phrase :";
  phraseTest = GetPhrase();
  std::cout << "The Position you Input was X:" << posTest[0] << " ,Y:" << posTest[1] << std::endl;
  std::cout << "The Char you Input was \'"<< charTest << "\'" << std::endl;
  std::cout << "The Phrase you Input was \"" << phraseTest << "\"\n";
  delete []posTest;
  delete []phraseTest;
}

void Input::Destroy() {
    delete []buffer;
}