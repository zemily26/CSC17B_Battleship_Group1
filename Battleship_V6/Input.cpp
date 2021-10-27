#include "Input.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Input Menu
int Input::inputMenu(int choices) {
  //input choice
  cin >> menuInput;
  //Change int choices to a character for validation
  char a = choices + '0';
  //validates number of inputs
  while(menuInput < '0' || menuInput > a) {
    //display.userInputError();
    inputDisplay.userInputError();
    cin >> menuInput;
  }
  int userInput = menuInput - '0';
  return userInput;
}

//Input Coordinates to shoot in
      // Format - letter=y, number=x
int *Input::inputCoordinates(char menuInput) {
  //display.coordinatePrompt();
  //Cin coordinates
  cin.clear();
  cin.getline(input, size-1);
  //Validating input if it is in range
  while(((input[0] < 'A' || input[0] > 'H') && (input[0] < 'a' || input[0] > 'h')) || (input[1] < '1' || input[1] > '8')) {
      inputDisplay.userInputError();
      cin.clear();
      cin.getline(input, size-1);
  }
  //intialize array for [X,Y] Coordinates
  int intSize = 2;
  int intCoordinates = new int[intSize];
  //Change characters into int
  intCoordinates[0] = input[1] - '0';
  intCoordinates[0]--;
  intCoordinates[1] = toupper(input[0]) - 'A';
  //return coordinates as integers
  return intCoordinates;
}

//Input User Set Up
int Input::inputUserSetUp() {
  //Initialize stuff
  char orientation;
  //Ask for the direction of the rotation
  //display.directionPrompt();
  cin >> orientation;
  //Change if not one of the options
    while(orientation != 'U' && orientation != 'D' && orientation != 'L' && orientation != 'R') {
        inputDisplay.userInputError();
        cin >> orientation;
    }
  //Return sideways as true if Yes, and false if No for ship orientation
  switch(toupper(orientation)) {
    case 'U': return 1; break;
    case 'R': return 2; break;
    case 'D': return 3; break;
    case 'L': return 4; break;
    default: return 1; break;
  }
}

//Input Player Data
char *Input::inputPlayerData() {
  //declare size of array, and dynamic char array for name
  int nameSize = 10;
  char *name = new char[nameSize];
  //Input the name of player
  //display.playerNamePrompt();
  //getline with playerName var from playerdata.h
  cin.clear();
  cin.getline(name, nameSize - 1);
  //Return name
  return name;
  //Deallocate
  delete [] name;
}

Input::~Input(){
  delete input;
}