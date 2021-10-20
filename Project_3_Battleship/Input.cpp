#include <iomanip>
using namespace std;

#include "Input.h"
//Add this file later from git hub
//#include "Constants.h"

//Constructor
Input::Input() {
    state = Waiting;
    buffer = new char[bufferSize];
    bufferLength = 0;
}

//Overloaded constructor
Input::Input(const Input& orig) {
  //ask andrew what he wanted to do with this overloaded constructor
}

//Destructor
Input::~Input() {
  //delete any dynamic stuff
  delete [] buffer;
}

//Input Coordinates to shoot in
      // Format - letter=y, number=x
void Input::inputCoordinates() {
  cout << "Format is \"A1\" or \"A,10\" or \"A 10\"\n" << endl
       << "Assume \"A\" is on the Y Axis. \"1\" is on the X Axis.\n" << endl
       << "Input the coordinates of your choice..." << endl
       << "Enter Input: ";
  //Cin coordinates
  cin.clear();
  cin.getline(buffer, bufferSize);
}

//Input User Set Up
bool Input::inputUserSetUp() {
  //Initialize stuff
  char sideways;
  //Ask for the direction of the rotation
  cout << "Would you like your ship to be horizontal or not? (Y) (N): ";
  cin>>sideways;
  //Return sideways as true if Yes, and false if No for ship orientation
  if(toupper(sideways)=='Y') {
    return true;
  } else {
    return false;
  }
}

//Input Player Data
void Input::inputPlayerData() {
  //Input the name of players
  //Need to check whether string will work when put into a binary file
  //Might have to chnage string to dynamic char array
  //First player
  cout << "Input player name : ";
  //getline with playerName var from playerdata.h
}

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