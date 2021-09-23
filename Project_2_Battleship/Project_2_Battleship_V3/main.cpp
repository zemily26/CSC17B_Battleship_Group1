/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 30 2021
 * Purpose:Project 2: Battleship V3 - Moved Classes to header files and added STL vectors
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

//User Libraries Here
#include "items.h"

//Global Constants Only, No Global Variables
// Columns in the 2-D Arrays

//Like PI, e, Gravity, or conversions

//Function Prototypes Here
//Bool for choices
bool choice(char);
bool verify(char);
char valid(char);
//Sorting for vectors
bool myfunction (int, int);
bool myobject (int, int);

//******************************************************************************
// Template function For Game Rules...
//******************************************************************************

template <class T>
T rules() {
    T name;
    // Ask if player wants to play
    cout << "Hello player, what is your name?" << endl
         << "Enter name here: ";
    //Input Name
    cin.clear();
    getline(cin, name);
    //Output Rules of the game
    cout << endl;
    cout << "Hello " << name << " are you ready to listen to the rules?" << endl;
    cout << "The rules are simple.." << endl;
    cout << "The player is given nine ships which are placed at random locations..." << endl;
    cout << "The ships are then targeted by the enemy computer..." << endl;
    cout << "You are to hit the computer's ships before it gets all of yours..." << endl;
    cout << "If you lose all your ships, you lose..." << endl;
    cout << "If the computer's ships are destroyed, you win..." << endl;
    cout << endl;
    
    //Output the Table
    cout << "With these rules you are given 2 tables..." << endl;
    cout << "One with your display to see where you've chosen to shoot..." << endl;
    cout << "The other your own battle ships..." << endl;
    cout << "It should look similar to this..." << endl;
    
    //Display
    cout << endl << "Display:" << endl;
    cout << "     X   1   2   3   4   5" << endl;
    cout << "   Y +-----------------------+" << endl;
    for(int rows = 0; rows < 5; rows++) {
        cout << "   " << rows + 1 << " |   ";
        for(int cols = 0; cols < 5; cols++) {
            cout << "-   ";
        }
        cout << "|" << endl;
        if(rows == 4) {
            cout << "     +-----------------------+" << endl;
        }
    }
    
    //End the rules...
    cout << endl << "Did you get everything, " << name << "?" << endl << endl;
    //Return Value
    return name;
}

//******************************************************************************
// Main function...
//******************************************************************************

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size = 5;       //Size of table
    int moves;          //Count for number of moves
    char stats, play;   //Characters for choices
    bool again;         //Boolean for choices
    string name;        //PLayer Name
    
    // Ask if player wants to play and Output game Rules
    name = rules<string>();
    
    //Ask If they want to play Battleship
    cout << "Would you like to play a game of Battleship? (y/n): ";
    cin >> play;
    
    // initialize bool operator
    try {
        again = choice(play);
    }
    catch(char error) {
        cout << "Invalid choice inputed! " << error << " is not an option!" << endl;
        cout << "Input your answer (y/n): ";
        cin >> play;
        again = choice(play);
    }
    
    // start game in loop with bool operator
    while(again == true) {
        //Initialize class
        board var(size);

        //Display player's board
        var.printDisplay();
        var.printPlayer();
        
        // Ask User if they want to start playing
        cout << endl << "This is your table, would like to start playing? (y/n): ";
        cin >> play;
        
        //Exception catch for player
        try {
            play = valid(play);
        }
        catch(char error) {
            cout << "Invalid choice inputed! " << error << " is not an option!" << endl;
            cout << "Input your answer (y/n): ";
            cin >> play;
            play = valid(play);
        }
        
        //Loop Game
        var.game(play);
        
        // Output Results
        var.results(name);
        
        //Initialize number of moves
        moves = var.retrnMoves();
        
        // Ask if they would like to know their accuracy
        try {
            cout << "Would you like to see your status? (y/n): ";
            cin >> stats;
            var.pStatus(stats);
        }
        catch(char error) {
            cout << "Invalid choice inputed! " << error << " is not an option!" << endl;
            cout << "Input your answer (y/n): ";
            cin >> stats;
            var.pStatus(stats);
        }

        // Ask if they would like to know computer's accuracy
        try {
            cout << endl << "What about the computer, would you like to see their status? (y/n): ";
            cin >> stats;
            var.rStatus(stats);
        }
        catch(char error) {
            cout << "Invalid choice inputed! " << error << " is not an option!" << endl;
            cout << "Input your answer (y/n): ";
            cin >> stats;
            var.rStatus(stats);
        }
        
        //Ask The player if they would like to play again
        cout << endl << "Would you like to play again? (y/n): ";
        cin >> play;
        //Exception for the choice
        try {
            again = verify(play);
        }
        catch(char error) {
            cout << "Invalid choice inputed! " << error << " is not an option!" << endl;
            cout << "Input your answer (y/n): ";
            cin >> play;
            again = verify(play);
        }
        
        //Call class for leaderboard
        files lead(size, moves);
        
        //Allocate memory for leaderboard
        int *leaderBoard = new int[size];
        leaderBoard = lead.returnLead();
        
        //Use vector to utilize algorithm
        vector<int> leadVect (leaderBoard, leaderBoard+6);
        leadVect[5] = moves;

        // using default comparison (operator <):
        sort (leadVect.begin(), leadVect.begin()+4);

        // using function as comp
        sort (leadVect.begin()+4, leadVect.end(), myfunction);

        // using object as comp
        sort (leadVect.begin(), leadVect.end(), myobject); 
        
        //Remove last number in the vector
        leadVect.pop_back();
        
        //Assign sorted vector to leaderboard array
        for(int i = 0; i < size; i++) {
            leaderBoard[i] = leadVect[i];
        }
        
        //Output array to binary file
        lead.arrayToFileBin(leaderBoard);
        
        //Print the leaderboard
        try {
            //Ask If they want to see it
            cout << endl << "Would you like to see the leader board for this game? (y/n): ";
            cin >> stats;
            cout << endl;
            lead.printLead(leaderBoard, stats);
        }
        catch(char error) {
            cout << "Invalid choice inputed! " << error << " is not an option!" << endl;
            cout << "Input your answer (y/n): ";
            cin >> stats;
            lead.printLead(leaderBoard, stats);
        }
    }
    
    //Output an ending statement
    cout << endl << "Thank you for visiting! Good Bye!";
    
    //Exit
    return 0;
}