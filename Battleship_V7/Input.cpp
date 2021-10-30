/*
 * File:   Input.cpp
 * Purpose: Input Class Function Definitions
 */

#include "Input.h"  //Input Class header file
#include <iostream> //I/O library
using namespace std;//Standard Namespace

//Constructor
Input::Input() {
  //Allocate memory for coordinate input
  size = 4;
  input = new char;
  //Allocate memory for name
  nameSize = 10;
  name = new char[nameSize];
}

//Input Menu
int Input::inputMenu(int choices) {
  char menuInput;
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
int *Input::inputCoordinates() {
  //display.coordinatePrompt();
  //Cin coordinates
  cin >> input[0] >> input[1];
  //Validating input if it is in range
  while(((input[0] < 'A' || input[0] > 'H') && (input[0] < 'a' || input[0] > 'h')) || (input[1] < '1' || input[1] > '8')) {
      inputDisplay.userInputError();
      //cin.getline(input, size-1); replace this line with the next line
      cin >> input[0] >> input[1]; //doesn't repeat userInputError()
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
  //display.directionPrompt();
  cin >> orientation;
  //Change if not one of the options
    while(orientation != 'U' && orientation != 'D' && orientation != 'L' && orientation != 'R' && orientation != 'u' && orientation != 'd' && orientation != 'l' && orientation != 'r') {
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
  //Input the name of player
  cin.ignore();
  cin.getline(name, nameSize - 1);
  //Return name
  return name;
}

//Check if user likes ship positions
char Input::inputLikePlacement(){
    char again;
    cin>>again;
    return again;
}

//Destructor
Input::~Input(){
  delete [] input;
  delete [] name;
}
