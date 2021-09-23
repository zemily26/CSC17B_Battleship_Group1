/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 16 2021
 * Purpose:Project 2: Battleship V1 - Copied code from previous project
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

//User Libraries Here
#include "data.h"

//Global Constants Only, No Global Variables
// Columns in the 2-D Arrays

//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool choice(char);
data *reset(int);
void prntDisplay(data *, int);
void plyrPatrn(data *, int);
void askAgain(char &);
void game(data *, int, char, char, string, fstream &, fstream &);
void results(string, data *);
int pMissed(data *, int);
int pAccuracy(data *, int);
int rMissed(data *, int);
int rAccuracy(data *, int);
void wrtTxt(fstream &, data *, int);
void wrtBin(fstream &, data *, int);
void pStatus(char, data *);
void rStatus(char, data *);
void playAgain(char &);
bool verify(char);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    data *var;
    int size = 5;
    char stats, play;
    string name;
    bool again;
    
    //Declare fstream variables
    fstream txtFile,binFile;
    txtFile.open("data.txt",ios::in|ios::out);
    binFile.open("data.bin",ios::in|ios::out|ios::binary);
    
    // Ask if player wants to play
    cout << "Hello player, what is your name?" << endl
         << "Enter name here: ";
    cin.clear();
    getline(cin, name);

    //Ask If they want to play Battleship
    cout << "Would you like to play a game of Battleship? (y/n): ";
    cin >> play;
    
    // initialize bool operator
    again = choice(play);
    
    
    // start game in loop with bool operator
    while(again == true) {
        // reset display table and initialize dynamic structure
        var = reset(size);
        
        //Display player's board
        prntDisplay(var, size);
        plyrPatrn(var, size);
        
        // Ask User if they want to start playing
        cout << endl << "This is your table, would like to start playing? (y/n): ";
        cin >> play;
        
        // Loop just in case they say no
        askAgain(play);
        
        //Loop Where user wants to hit and output results
        game(var, size, play, stats, name, txtFile, binFile);
        
        // Give player choice to play again or not
        playAgain(play);
        
        // Verify player choice
        again = verify(play);
        
        //Deallocate Memory
        delete [] var->arrays->display;
        delete [] var->arrays->player;
        delete [] var->arrays->comp;
        delete [] var->arrays;
        delete [] var;
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

data *reset(int size) {
    //Allocate Memory
    data *a = new data;
    a->arrays = new board;
    //Initialize
    int x, y;
    x = y = 0;
    a->nBoats = a->pCount = a->rCount = 9;
    a->nBoats = a->pCount = a->rCount = 9;
    //Allocate memory for 2 dim-arrays
    a->arrays->display = new char*[size];
    a->arrays->player = new char*[size];
    a->arrays->comp = new char*[size];
    //Allocate the memory for each row
    for(int row = 0; row < size; row++) {
        a->arrays->display[row] = new char[size];
        a->arrays->player[row] = new char[size];
        a->arrays->comp[row] = new char[size];
    }
    //Initialize Arrays with "-" to fill with ships
    for(int rows = 0; rows < size; rows++) {
        for(int cols = 0; cols < size; cols++) {
            a->arrays->display[rows][cols] = '-';
            a->arrays->player[rows][cols] = '-';
            a->arrays->comp[rows][cols] = '-';
        }
    }
    //Initialize the patterns for the player
    for(int boats = 0; boats < a->nBoats; boats++) {
        x = rand() % 5;
        y = rand() % 5;
        while(a->arrays->player[x][y] == 'G') {
            x = rand() % 5;
            y = rand() % 5;
        }
        a->arrays->player[x][y] = 'G';
    }
    //Initialize the patterns for the computer
    for(int boats = 0; boats < a->nBoats; boats++) {
        x = rand() % 5;
        y = rand() % 5;
        while(a->arrays->comp[x][y] == 'G') {
            x = rand() % 5;
            y = rand() % 5;
        }
        a->arrays->comp[x][y] = 'G';
    }
    //Return data
    return a;
}

void prntDisplay(data *a, int size) {
    cout << endl << "Player Display:" << endl;
    cout << "     X   1   2   3   4   5" << endl;
    cout << "   Y +-----------------------+" << endl;
    for(int rows = 0; rows < size; rows++) {
        cout << "   " << rows + 1 << " |   ";
        for(int cols = 0; cols < size; cols++) {
            cout << a->arrays->display[rows][cols] << "   ";
        }
        cout << "|" << endl;
        if(rows == size - 1) {
            cout << "     +-----------------------+" << endl;
        }
    }
}

void plyrPatrn(data *a, int size) {
    cout << endl << "Player Pattern:" << endl;
    cout << "     X   1   2   3   4   5" << endl;
    cout << "   Y +-----------------------+" << endl;
    for(int rows = 0; rows < size; rows++) {
        cout << "   " << rows + 1 << " |   ";
        for(int cols = 0; cols < size; cols++) {
            cout << a->arrays->player[rows][cols] << "   ";
        }
        cout << "|" << endl;
        if(rows == size - 1) {
            cout << "     +-----------------------+" << endl;
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

void game(data *a, int size, char play, char stats, string name, fstream &txtFile, fstream &binFile) {
    while(play == 'y' || play == 'Y') {
        // Display player's choices
        prntDisplay(a, size);

        // Ask player where they would like to hit
        cout << endl << "What coordinates would you like to shoot in?" << endl;
        cout << "X-Coordinate: ";
        cin >> a->pChoseX;
        cout << "Y-Coordinate: ";
        cin >> a->pChoseY;
        // Validate User input if choice is invalid
        if(a->pChoseX > 5 || a->pChoseY > 5 || a->pChoseX <= 0 || a->pChoseY <= 0 || a->arrays->comp[a->pChoseY - 1][a->pChoseX - 1] == 'O' || a->arrays->comp[a->pChoseY - 1][a->pChoseX - 1] == 'X') {
            do {
            cout << endl << "These are invalid numbers try again..." << endl;
            cout << "X-Coordinate: ";
            cin >> a->pChoseX;
            cout << "Y-Coordinate: ";
            cin >> a->pChoseY;
            } while (a->pChoseX > 5 || a->pChoseY > 5 || a->pChoseX <= 0 || a->pChoseY <= 0 || a->arrays->comp[a->pChoseY - 1][a->pChoseX - 1] == 'O' || a->arrays->comp[a->pChoseY - 1][a->pChoseX - 1] == 'X');
        }
        
        // See if player hit a ship or not
        if(a->arrays->comp[a->pChoseY - 1][a->pChoseX - 1] != '-') {
            cout << endl << "You have hit a ship!" << endl;
            a->arrays->display[a->pChoseY - 1][a->pChoseX - 1] = 'O';
            a->rCount -= 1;
        }
        else if(a->arrays->comp[a->pChoseY - 1][a->pChoseX - 1] == '-') {
            cout << endl << "You have missed a ship. Try again." << endl;
            a->arrays->display[a->pChoseY - 1][a->pChoseX - 1] = 'X';
        }

        // Output that computer is choosing
        cout << endl << "The computer is choosing their coordinates..." << endl;

        // use random and linear search to see if computer chose that number already;
        a->rChoseX = rand() % 5;
        a->rChoseY = rand() % 5;
        //Loop so it doesn't choose the same coordinate again
        while(a->arrays->player[a->rChoseY][a->rChoseX] == 'X' || a->arrays->player[a->rChoseY][a->rChoseX] == 'O') {
            a->rChoseX = rand() % 5;
            a->rChoseY = rand() % 5;
        }

        // See if Computer hit a ship or not
        if(a->arrays->player[a->rChoseY][a->rChoseX] != '-') {
            cout << endl << "The Computer has hit a ship!" << endl;
            a->arrays->player[a->rChoseY][a->rChoseX] = 'O';
            a->pCount -= 1;
        }
        else if(a->arrays->player[a->rChoseY][a->rChoseX] == '-') {
            cout << endl << "The Computer has missed a ship." << endl;
            a->arrays->player[a->rChoseY][a->rChoseX] = 'X';
        }

        // Output player's table
        plyrPatrn(a, size);

        if(a->rCount == 0 || a->pCount == 0) {
            play = 'n';
        }

    }
    
    // Output Results
    results(name, a);

    // Use linear search to determine how much you missed and how much you hit.
    // Calculate player and computer's accuracy
    a->pMiss = pMissed(a, size);
    a->pHit = pAccuracy(a, size);
    a->rMiss = rMissed(a, size);
    a->rHit = rAccuracy(a, size);
    
    //Write Both results into binary and txt
    wrtBin(binFile, a, size);
    wrtTxt(txtFile, a, size);

    // Ask if they would like to know their accuracy
    cout << "Would you like to see your status? (y/n): ";
    cin >> stats;
    pStatus(stats, a);

    // Ask if they would like to know computer's accuracy
    cout << endl << "What about the computer, would you like to see their status? (y/n): ";
    cin >> stats;
    rStatus(stats, a);
}

void results(string name, data *a) {
    if(a->rCount == 0) {
        cout << endl << "You have won! The computer has lost all their ships."
             << endl << "Congratulations " << name << "!" << endl << endl;
    }
    else if(a->pCount == 0){
        cout << endl << "You have lost! The computer has won and destroyed all your ships."
             << endl << "Better luck next time " << name << "!" << endl << endl;
    }
    else if(a->pCount == a->rCount){
        cout << endl << "You have tied! your ships and the computer's ships are all destroyed."
             << endl << "Better luck next time " << name << "!" << endl << endl;
    }
}

int pMissed(data *a, int size) {
    for(int i = 0; i < size; i++) {
        for(int u = 0; u < size; u++) {
            if(a->arrays->display[i][u] == 'X') {
                a->pMiss += 1;
            }
        }
    }
    return a->pMiss;
}

int pAccuracy(data *a, int size) {
    for(int i = 0; i < size; i++) {
        for(int u = 0; u < size; u++) {
            if(a->arrays->display[i][u] == 'O') {
                a->pHit += 1;
            }
        }
    }
    return a->pHit;
}

int rMissed(data *a, int size) {
    for(int i = 0; i < size; i++) {
        for(int u = 0; u < size; u++) {
            if(a->arrays->player[i][u] == 'X') {
                a->rMiss += 1;
            }
        }
    }
    return a->rMiss;
}

int rAccuracy(data *a, int size) {
    for(int i = 0; i < size; i++) {
        for(int u = 0; u < size; u++) {
            if(a->arrays->player[i][u] == 'O') {
                a->rHit += 1;
            }
        }
    }
    return a->rHit;
}

void wrtBin(fstream &out, data *a, int size){
    out.write(reinterpret_cast<char *>(a), sizeof(a));
}

void wrtTxt(fstream &out, data *a, int size){
    //output Diagrams
    out << endl << "Player Display:" << endl;
    out << "     X   1   2   3   4   5" << endl;
    out << "   Y +-----------------------+" << endl;
    for(int rows = 0; rows < size; rows++) {
        out << "   " << rows + 1 << " |   ";
        for(int cols = 0; cols < size; cols++) {
            out << a->arrays->display[rows][cols] << "   ";
        }
        out << "|" << endl;
        if(rows == size - 1) {
            out << "     +-----------------------+" << endl;
        }
    }
    
    out << endl << "Player Pattern:" << endl;
    out << "     X   1   2   3   4   5" << endl;
    out << "   Y +-----------------------+" << endl;
    for(int rows = 0; rows < size; rows++) {
        out << "   " << rows + 1 << " |   ";
        for(int cols = 0; cols < size; cols++) {
            out << a->arrays->player[rows][cols] << "   ";
        }
        out << "|" << endl;
        if(rows == size - 1) {
            out << "     +-----------------------+" << endl;
        }
    }
    //Output Results
    out << "Player missed     = " << a->pMiss << endl;
    out << "Player hit        = " << a->pHit << endl;
    out << "Computer missed   = " << a->rMiss << endl;
    out << "Computer hit      = " << a->rHit << endl;
}

void pStatus(char stats, data *a) {
    if(stats == 'y' || stats == 'Y') {
        cout << "Player missed     = " << a->pMiss << endl;
        cout << "Player hit        = " << a->pHit << endl;
    }
    else {
        cout << "That's a shame!" << endl;
    }
}

void rStatus(char stats, data *a) {
    if(stats == 'y' || stats == 'Y') {
        cout << "Computer missed   = " << a->rMiss << endl;
        cout << "Computer hit      = " << a->rHit << endl;
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