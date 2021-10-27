#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

//>> Model/Grid.h
const int BOARD_WIDTH = 8;
const int BOARD_HEIGHT = 8;

//>> Model/Ship.h
const int FLEET_SIZE = 5;
enum ShipType {
    Carrier = 0, Battleship = 1, Cruiser = 2, Submarine = 3, Destroyer = 4
};
const std::string SHIP_NAMES[] = {"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"};
const int SHIP_SIZE[] = {5, 4, 3, 3, 2};

//>>Input.h View.h
enum CellChars{
    Empty= '-', Ship='S', Hit='!', Miss='0'
};
const std::string invalidWarning_Waiting = "Currently Not Accepting Inputs.";
const std::string invalidWarning_Command = "Input Is Invalid. Exceeds 256 Length.";
const std::string invalidWarning_Position = "Input Is Invalid,\nFormat Must be \"A1\" or \"A,1\"";
const std::string invalidWarning_Phrase = "Input Is Invalid. Exceeds 256 Length.";

#endif /* CONSTANTS_H */