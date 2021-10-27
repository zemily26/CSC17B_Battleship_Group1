/*
 * Project 1: C++ Battleship Game
 * Course:    CIS 17B 48594
 * Group Members: Lindsay Kislingbury, Joash Gem Marcos, Jyro Jimenez, 
 *                Anabelle Tamano, Andrew Robledo, Amanda Sarenana,
 *                Eaby Hernandez
 */

//System Libraries
#include <iostream>  //I/O Stream
using namespace std; //Standard namespace

//User Libraries
#include "Controller.h" //Controller Class Header File

//Program Execution
int main(int argc, char** argv) {
    
    //Declare Variables
    Controller start; //Controller Object
    
    //Execute Main Menu
    start.mainMenu(); 
    
    //Exit
    return 0;
}