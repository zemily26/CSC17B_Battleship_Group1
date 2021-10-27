#include <iomanip>
using namespace std;

#include "Input.h"
//Add this file later from git hub

/*/Constructor
Input::Input() {
    state = Waiting;
    buffer = new char[bufferSize];
    bufferLength = 0;
}

//Overloaded constructor
Input::Input(const Input& orig) {
  //ask andrew what he wanted to do with this overloaded constructor
}*/

//Destructor
Input::~Input() {
  //delete any dynamic stuff
  delete [] input;
}

//Input Menu
int inputMenu(char menuInput, int choices) {
  //validates number of inputs
  while(menuInput < '0' || menuInput > static_cast<char>(choices)) {
    //display.userInputError();
    //display.askQuit();
    display.userInputError();
    cin >> menuInput;
  }
  return menuInput;
}

//Input Coordinates to shoot in
      // Format - letter=y, number=x
int *Input::inputCoordinates(char menuInput) {
  display.coordinatePrompt();
  //Cin coordinates
  cin.clear();
  cin.getline(input, size-1);
  //Validating input if it is in range
  while(((input[0] < 'A' || input[0] > 'H') && (input[0] < 'a' || input[0] > 'h')) || (input[1] < '1' || input[1] > '8')) {
      display.userInputError();
      cin.clear();
      cin.getline(input, size-1);
  }
  //Allocate Dynamic array for [X,Y] Coordinates
  int *intCoordinates = new int[size - 2];
  //Change characters into int
  intCoordinates[0] = input[1] - '0';
  intCoordinates[0]--;
  intCoordinates[1] = toupper(input[0]) - 'A';
  //return coordinates as integers
  return intCoordinates;
  //Deallocate
  delete [] intCoordinates;
}

//Input User Set Up
int Input::inputUserSetUp() {
  //Initialize stuff
  char orientation;
  //Ask for the direction of the rotation
  display.directionPrompt();
  cin>>orientation;
  //Return sideways as true if Yes, and false if No for ship orientation
  switch(toupper(orientation)) {
    case 'U': return 1; break;
    case 'D': return 2; break;
    case 'L': return 3; break;
    case 'R': return 4; break;
    default: return -1; break;
  }
}

//Input Player Data
char *Input::inputPlayerData() {
  //declare size of array, and dynamic char array for name
  int nameSize = 10;
  char *name = new char[nameSize];
  //Input the name of player
  display.playerNamePrompt();
  //getline with playerName var from playerdata.h
  cin.clear();
  cin.getline(name, nameSize - 1);
  //Return name
  return name;
  //Deallocate
  delete [] name;
}

/* Might need later on
//Returns True if able to grab line from Input.
//Should Lock Process Otherwise.
bool Input::ListenInput(char *buffer) {
    cin.getline(buffer, bufferSize);
    bufferLength = strlen(buffer);
    return (bufferLength > 0);
}

//Gets And Validates Input Based off Input State.
//input depending on state.
bool Input::GetUserInput() {
    bool valid = false;
    switch (state) {
        case Command:
            //Command Input, Single Char
            


            valid = ListenInput(buffer);
            if (!valid)
                ThrowWarning();
            break;
        case Position:
            //Position Input, "A 10" "A,10" "A 10"
            //inputCoordinates();


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
        default: 
            // Input Waiting, Not Accepting Input.
            ThrowWarning();
            break;
    }
    return valid;
}

//Used for Debugging if Input is Not Valid.
//Don't forget to include constant file for the results
void Input::ThrowWarning() {
    switch (state) {
        case Command:
            //Command Input, Single Char
            //cout << invalidWarning_Command << endl;
            break;
        case Position:
            //Position Input, "A 10" "A,10" "A 10"
            //cout << invalidWarning_Position << endl;
            break;
        case Phrase:
            //cout << invalidWarning_Phrase << endl;
            break;
        default: // Input Waiting, Not Accepting Input.
            //cout << invalidWarning_Waiting << endl;
            break;
    }
    cout << " Your Input :\"" << buffer << "\" length:" << bufferLength << endl;
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
*/

/* Might need later on
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
*/

/*
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
*/

/*
//INPUT TEST//
void Input::RunTest()
{
  int *posTest;
  char charTest, *phraseTest;
  cout << "Format is \"A1\" or \"A,10\" or \"A 10\"\n";
  cout << "Assume \"A\" is on the Y Axis. \"1\" is on the X Axis.\n";
  cout << "Input a position :";
  posTest = GetPosition();
  cout << "A Command is a Menu Option, a Single char for example (Y) (N) \n";
  cout << "Input a Command :";
  charTest = GetCommand();
  cout << "A Phrase is a string, for example \"Your Name\"\n";
  cout << "Input a Phrase :";
  phraseTest = GetPhrase();
  cout << "The Position you Input was X:" << posTest[0] << " ,Y:" << posTest[1] << endl;
  cout << "The Char you Input was \'"<< charTest << "\'" << endl;
  cout << "The Phrase you Input was \"" << phraseTest << "\"\n";
  delete []posTest;
  delete []phraseTest;
}
*/