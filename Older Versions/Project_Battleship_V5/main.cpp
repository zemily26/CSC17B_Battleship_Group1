/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 15 2021
 * Purpose:Project 1: Battleship V1 - Old Project Code
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
// Columns in the 2-D Arrays
const int cols = 8;

//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool choice(char);
void reset(string [][cols], const int);
void playerPat(string [][cols], string [][cols], string [][cols], string [][cols], string [][cols], string [][cols], const int , int);
void compPat(string [][cols], string [][cols], string [][cols], string [][cols], string [][cols], string [][cols], const int , int);
int ref(int &);
void prntDisplay(string [][cols], const int);
void prntPatrn(string [][cols], const int);
void askAgain(char &);
int cords(int &, int &);
void displayHit(string [][cols], string [][cols], int, int, int &);
void compHit(string [][cols], int, int, int &);
void results(char*, int);
int pMissed(string [][cols], const int, int);
int pAccuracy(string [][cols], const int, int);
int rMissed(string [][cols], const int, int);
int rAccuracy(string [][cols], const int, int);
void pStatus(char, int, int);
void rStatus(char, int, int);
void playAgain(char &);
bool verify(char);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    //Local Constants
    const int rows = 8;
    const int size = 20;
    
    // Player and computer fields
    string player[rows][cols];
    string comp[rows][cols];
    string display[rows][cols];
    
    // Different patterns to the game
    // Pattern 1
    string ptrn1[rows][cols] = { {"-", "-", "-", "-", "-", "-", "-", "-"}, 
                                 {"-", "C", "D", "D", "-", "-", "-", "-"}, 
                                 {"-", "C", "-", "S", "S", "S", "-", "-"},
                                 {"-", "C", "-", "-", "-", "-", "M", "-"},
                                 {"-", "C", "-", "-", "-", "-", "M", "-"},
                                 {"-", "C", "-", "-", "-", "-", "M", "-"},
                                 {"-", "-", "B", "B", "B", "B", "-", "-"},
                                 {"-", "-", "-", "-", "-", "-", "-", "-"} };
    
    // Pattern 2
    string ptrn2[rows][cols] = { {"-", "-", "-", "B", "B", "B", "B", "-"}, 
                                 {"M", "M", "M", "-", "-", "-", "-", "-"}, 
                                 {"-", "-", "-", "-", "-", "-", "-", "-"},
                                 {"-", "-", "-", "-", "-", "-", "-", "-"},
                                 {"-", "-", "D", "D", "-", "-", "-", "-"},
                                 {"-", "-", "-", "C", "C", "C", "C", "C"},
                                 {"-", "-", "-", "-", "-", "-", "-", "-"},
                                 {"-", "-", "-", "-", "-", "S", "S", "S"} };
    
    // Pattern 3
    string ptrn3[rows][cols] = { {"-", "-", "-", "C", "C", "C", "C", "C"}, 
                                 {"-", "-", "-", "-", "-", "-", "-", "-"}, 
                                 {"-", "S", "-", "-", "-", "-", "-", "-"},
                                 {"-", "S", "-", "D", "-", "M", "-", "-"},
                                 {"-", "S", "-", "D", "-", "M", "-", "-"},
                                 {"-", "-", "-", "-", "-", "M", "-", "-"},
                                 {"-", "-", "-", "-", "-", "-", "-", "-"},
                                 {"B", "B", "B", "B", "-", "-", "-", "-"} };
    
    // Pattern 4
    string ptrn4[rows][cols] = { {"-", "-", "-", "-", "-", "-", "-", "-"}, 
                                 {"-", "-", "-", "-", "-", "-", "-", "-"}, 
                                 {"M", "M", "M", "-", "-", "-", "D", "-"},
                                 {"-", "S", "-", "-", "-", "-", "D", "-"},
                                 {"-", "S", "-", "-", "-", "-", "-", "-"},
                                 {"-", "S", "B", "B", "B", "B", "-", "-"},
                                 {"-", "-", "-", "-", "-", "-", "-", "-"},
                                 {"-", "-", "-", "C", "C", "C", "C", "C"} };
    
    // Pattern 5
    string ptrn5[rows][cols] = { {"-", "-", "-", "-", "-", "-", "-", "-"}, 
                                 {"-", "-", "D", "-", "-", "-", "C", "-"}, 
                                 {"-", "-", "D", "-", "-", "-", "C", "-"},
                                 {"-", "M", "B", "B", "B", "B", "C", "-"},
                                 {"-", "M", "-", "S", "-", "-", "C", "-"},
                                 {"-", "M", "-", "S", "-", "-", "C", "-"},
                                 {"-", "-", "-", "S", "-", "-", "-", "-"},
                                 {"-", "-", "-", "-", "-", "-", "-", "-"} };
    
    // Other variables
    int pChoseX, pChoseY, rChoseX, rChoseY, pCount, rCount, patrn, pMiss, pHit, rMiss, rHit;
    char play, stats;
    char name[size] = {};
    bool again;
    
    // Ask if player wants to play
    cout << "Hello player, what is your name?" << endl
         << "Enter name here: ";
    cin >> name;
    
    cout << "Would you like to play a game of Battleship? (y/n): ";
    cin >> play;
    
    // initialize bool operator
    again = choice(play);
    
    // start game in loop with bool operator
    while(again == true) {
        // reset display table
        reset(display, rows);
        
        // Process/Map inputs to outputs
        // Initialize count
        pCount = 17;
        rCount = 17;
        pMiss = 0;
        pHit = 0;
        rMiss = 0;
        rHit = 0;
        
        // Pattern for player
        patrn = rand() % 5;
        // Assign player's pattern depending on random
        playerPat(player, ptrn1, ptrn2, ptrn3, ptrn4, ptrn5, rows, patrn);
        
        // Pattern for Computer
        // Pass By Reference
        ref(patrn);
        
        // Assign computer's pattern depending on random
        compPat(comp, ptrn1, ptrn2, ptrn3, ptrn4, ptrn5, rows, patrn);
        
        // Output data
        // Output player's display
        prntDisplay(display, rows);
        
        // Output player's table
        prntPatrn(player, rows);
        
        // Ask User if they want to start playing
        cout << endl << "This is your table, would like to start playing? (y/n): ";
        cin >> play;
        
        // Loop just in case they say no
        askAgain(play);
        
        // Ask User where they want hit
        while(play == 'y' || play == 'Y') {
            // Display player's choices
            prntDisplay(display, rows);
            
            // Ask player where they would like to hit
            cords(pChoseX, pChoseY);
            
            // See if player hit a ship or not
            displayHit(display, comp, pChoseY, pChoseX, rCount);
            
            // Output that computer is choosing
            cout << endl << "The computer is choosing their coordinates..." << endl;
            
            // use random and linear search to see if computer chose that number already;
            rChoseX = rand() % 8;
            rChoseY = rand() % 8;
            
            while(player[rChoseY - 1][rChoseX] == "X" || player[rChoseY - 1][rChoseX] == "O") {
                rChoseX = rand() % 8;
                rChoseY = rand() % 8;
            }
            
            // See if Computer hit a ship or not
            compHit(player, rChoseY, rChoseX, pCount);
            
            // Output player's table
            prntPatrn(player, rows);
            
            if(rCount == 0 || pCount == 0) {
                play = 'n';
            }
            
        }
        
        // Output Results
        results(name, rCount);
        
        // Use linear search to determine how much you missed and how much you hit.
        // Calculate player and computer's accuracy
        pMiss = pMissed(display, rows, pMiss);
        pHit = pAccuracy(display, rows, pHit);
        rMiss = rMissed(player, rows, rMiss);
        rHit = rAccuracy(player, rows, rHit);
        
        // Ask if they would like to know their accuracy
        cout << "Would you like to see your status? (y/n): ";
        cin >> stats;
        
        pStatus(stats, pMiss, pHit);
        
        // Ask if they would like to know computer's accuracy
        cout << endl << "What about the computer, would you like to see their status? (y/n): ";
        cin >> stats;
        
        rStatus(stats, rMiss, rHit);
        
        // Give player choice to play again or not
        playAgain(play);
        
        // Verify player choice
        again = verify(play);
        
    }
    
    cout << endl << "It was fun playing with you! Good Bye!";
    
    //Exit
    return 0;
}

bool choice(char play) {
    switch(play) {
        case 'y': 
            return true;
            break;
        case 'n':
            return false;
            break;
        case 'Y': 
            return true;
            break;
        case 'N':
            return false;
            break;
        default:
            return true;
    }
}

void reset(string display[][cols], const int rows) {
    for(int i = 0; i < rows; i++) {
        for(int u = 0; u < cols; u++) {
            display[i][u] = "-";
        }
    }
}

void playerPat(string player[][cols], string ptrn1[][cols], string ptrn2[][cols], string ptrn3[][cols], string ptrn4[][cols], string ptrn5[][cols], const int rows, int patrn) {
    if(patrn == 0) {
        for(int i = 0; i < rows; i++) {
            for(int u = 0; u < cols; u++) {
            player[i][u] = ptrn1[i][u];
            }
        }
    }
    else if(patrn == 1) {
        for(int i = 0; i < rows; i++) {
            for(int u = 0; u < cols; u++) {
            player[i][u] = ptrn2[i][u];
            }
        }
    }
    else if(patrn == 2) {
        for(int i = 0; i < rows; i++) {
            for(int u = 0; u < cols; u++) {
            player[i][u] = ptrn3[i][u];
            }
        }
    }
    else if(patrn == 3) {
        for(int i = 0; i < rows; i++) {
            for(int u = 0; u < cols; u++) {
            player[i][u] = ptrn4[i][u];
            }
        }
    }
    else if(patrn == 4) {
        for(int i = 0; i < rows; i++) {
            for(int u = 0; u < cols; u++) {
            player[i][u] = ptrn5[i][u];
            }
        }
    }
}

void compPat(string comp[][cols], string ptrn1[][cols], string ptrn2[][cols], string ptrn3[][cols], string ptrn4[][cols], string ptrn5[][cols], const int rows, int patrn) {
    if(patrn == 0) {
        for(int i = 0; i < rows; i++) {
            for(int u = 0; u < cols; u++) {
            comp[i][u] = ptrn1[i][u];
            }
        }
    }
    else if(patrn == 1) {
        for(int i = 0; i < rows; i++) {
            for(int u = 0; u < cols; u++) {
            comp[i][u] = ptrn2[i][u];
            }
        }
    }
    else if(patrn == 2) {
        for(int i = 0; i < rows; i++) {
            for(int u = 0; u < cols; u++) {
            comp[i][u] = ptrn3[i][u];
            }
        }
    }
    else if(patrn == 3) {
        for(int i = 0; i < rows; i++) {
            for(int u = 0; u < cols; u++) {
            comp[i][u] = ptrn4[i][u];
            }
        }
    }
    else if(patrn == 4) {
        for(int i = 0; i < rows; i++) {
            for(int u = 0; u < cols; u++) {
            comp[i][u] = ptrn5[i][u];
            }
        }
    }
}

int ref(int &patrn) {
    int x = patrn;
    patrn = rand() % 5;
    
    // Loop so Player's pattern is not the same as Computer
    while(patrn == x) {
        patrn = rand() % 5;
    }
}

void prntDisplay(string display[][cols], const int rows) {
    cout << endl << "Player Display:" << endl;
    cout << "     X   1   2   3   4   5   6   7   8" << endl;
    cout << "   Y +-----------------------------------+" << endl;
    for(int i = 0; i < rows; i++) {
        cout << "   " << i+1 << " |   ";

        for(int u = 0; u < cols; u++) {
            cout << display[i][u] << "   ";
        }

        cout << "|" << endl;

        if(i == rows-1) {
            cout << "     +-----------------------------------+" << endl;
        }
    }
}

void prntPatrn(string player[][cols], const int rows) {
    cout << endl << "Player Pattern:" << endl;
    cout << "     X   1   2   3   4   5   6   7   8" << endl;
    cout << "   Y +-----------------------------------+" << endl;
    for(int i = 0; i < rows; i++) {
        cout << "   " << i+1 << " |   ";

        for(int u = 0; u < cols; u++) {
            cout << player[i][u] << "   ";
        }

        cout << "|" << endl;

        if(i == rows-1) {
            cout << "     +-----------------------------------+" << endl;
        }
    }
}

void askAgain(char &play) {
    while(play == 'n' || play == 'N') {
        cout << endl << "What about now? (y/n): ";
        cin >> play;
        cout << endl;
    }
}

int cords(int &pChoseX, int &pChoseY) {
    cout << endl << "What coordinates would you like to shoot in?" << endl;
    cout << "X-Coordinate: ";
    cin >> pChoseX;
    cout << "Y-Coordinate: ";
    cin >> pChoseY;

    if(pChoseX > 8 || pChoseY > 8 || pChoseX <= 0 || pChoseY <= 0) {
        do {
        cout << endl << "These are invalid numbers try again..." << endl;
        cout << "X-Coordinate: ";
        cin >> pChoseX;
        cout << "Y-Coordinate: ";
        cin >> pChoseY;
        } while (pChoseX > 8 || pChoseY > 8 || pChoseX <= 0 || pChoseY <= 0);
    }
    
}

void displayHit(string display[][cols], string comp[][cols], int pChoseY, int pChoseX, int &rCount) {
    if(comp[pChoseY - 1][pChoseX - 1] != "-") {
        cout << endl << "You have hit a ship!" << endl;
        display[pChoseY - 1][pChoseX - 1] = 'O';
        rCount -= 1;
    }
    else if(comp[pChoseY - 1][pChoseX - 1] == "-") {
        cout << endl << "You have missed a ship. Try again." << endl;
        display[pChoseY - 1][pChoseX - 1] = 'X';
    }
}

void compHit(string player[][cols], int rChoseY, int rChoseX, int &pCount) {
    if(player[rChoseY][rChoseX] != "-") {
        cout << endl << "The Computer has hit a ship!" << endl;
        player[rChoseY][rChoseX] = 'O';
        pCount -= 1;
    }
    else if(player[rChoseY][rChoseX] == "-") {
        cout << endl << "The Computer has missed a ship." << endl;
        player[rChoseY][rChoseX] = 'X';
    }
}

void results(char* name, int rCount) {
    if(rCount == 0) {
        cout << endl << "You have won! The computer has lost all their ships."
             << endl << "Congratulations " << name << "!" << endl << endl;
    }
    else {
        cout << endl << "You have lost! The computer has won and destroyed all your ships."
             << endl << "Better luck next time " << name << "!" << endl << endl;
    }
}

int pMissed(string display[][cols], const int rows, int pMiss) {
    for(int i = 0; i < rows; i++) {
        for(int u = 0; u < cols; u++) {
            if(display[i][u] == "X") {
                pMiss += 1;
            }
        }
    }
    return pMiss;
}

int pAccuracy(string display[][cols], const int rows, int pHit) {
    for(int i = 0; i < rows; i++) {
        for(int u = 0; u < cols; u++) {
            if(display[i][u] == "O") {
                pHit += 1;
            }
        }
    }
    return pHit;
}

int rMissed(string player[][cols], const int rows, int rMiss) {
    for(int i = 0; i < rows; i++) {
        for(int u = 0; u < cols; u++) {
            if(player[i][u] == "X") {
                rMiss += 1;
            }
        }
    }
    return rMiss;
}

int rAccuracy(string player[][cols], const int rows, int rHit) {
    for(int i = 0; i < rows; i++) {
        for(int u = 0; u < cols; u++) {
            if(player[i][u] == "O") {
                rHit += 1;
            }
        }
    }
    return rHit;
}

void pStatus(char stats, int pMiss, int pHit) {
    if(stats == 'y' || stats == 'Y') {
        cout << "Player missed     = " << pMiss << endl;
        cout << "Player hit        = " << pHit << endl;
    }
    else {
        cout << "That's a shame!" << endl;
    }
}

void rStatus(char stats, int rMiss, int rHit) {
    if(stats == 'y' || stats == 'Y') {
        cout << "Computer missed   = " << rMiss << endl;
        cout << "Computer hit      = " << rHit << endl;
    }
    else {
        cout << "That's a shame!" << endl;
    }
}

void playAgain(char &play) {
    cout << endl << "Would you like to play again? (y/n): ";
    cin >> play;
}

bool verify(char play) {
    if(play == 'n' || play == 'N') {
        cout << endl << "Are you sure? (y/n): ";
        cin >> play;

        if(play == 'y' || play == 'Y') {
            return false;
        }
        else {
            return true;
        } 
    }
    else if(play == 'y' || play == 'Y') {
        return true;
    }
}