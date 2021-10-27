#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

//>> Model/Grid.h
int const BOARD_WIDTH = 8;
int const BOARD_HEIGHT = 8;

//>> Model/Ship.h
const int FLEET_SIZE = 5;
const std::string SHIP_NAMES[] = {"AirCraft_Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"};
const int SHIP_SIZE[] = {2, 3, 3, 4, 5};

//>>Input.h View.h
enum CellChars{Aircraft_Carrier = '5', Battleship = '4', Cruiser = '3', Submarine = '2', Destroyer = '1', Empty= '-', Hit='!', Miss='0'};

#endif /* CONSTANTS_H */