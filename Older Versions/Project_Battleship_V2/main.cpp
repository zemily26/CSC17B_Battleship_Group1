/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on June 3 2021
 * Purpose:Project 2: Battleship V2 [Base Game (No Functions)]
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
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int rows = 8;
    const int cols = 8;
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
    int pChoseX, pChoseY, rChoseX, rChoseY, pCount, rCount, patrn;
    char play;
    char name[size] = {};
    bool again;
    
    // Ask if player wants to play
    cout << "Hello player, what is your name?" << endl
         << "Enter name here: ";
    cin >> name;
    
    cout << "Would you like to play a game of Battleship? (y/n): ";
    cin >> play;
    
    // initialize bool operator
    switch(play) {
        case 'y': 
            again = true;
            break;
        case 'n':
            again = false;
            break;
        case 'Y': 
            again = true;
            break;
        case 'N':
            again = false;
            break;
    }
    
    // start game in loop with bool operator
    while(again == true) {
        // reset display table
        for(int i = 0; i < rows; i++) {
            for(int u = 0; u < cols; u++) {
            display[i][u] = "-";
            }
        }
        
        // Process/Map inputs to outputs
        // Initialize count
        pCount = 17;
        rCount = 17;
        
        // Pattern for player
        patrn = rand() % 5;
        
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
        
        // Pattern for Computer
        int x = patrn;
        patrn = rand() % 5;
        // Loop so Player's pattern is not the same as Computer
        while(patrn == x) {
            patrn = rand() % 5;
        }
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
        
        // Output data
        // Output player's display
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
        
        // Output player's table
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
        
        // Ask User if they want to start playing
        cout << endl << "This is your table, would like to start playing? (y/n): ";
        cin >> play;
        
        // Loop just in case they say no
        while(play == 'n' || play == 'N') {
            cout << endl << "What about now? (y/n): " << endl;
            cin >> play;
            cout << endl;
        }
        
        // Ask User where they want hit
        while(play == 'y' || play == 'Y') {
            // Display player's choices
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
            
            cout << endl << "What coordinates would you like to shoot in?" << endl;
            cout << "X-Coordinate: ";
            cin >> pChoseX;
            cout << "Y-Coordinate: ";
            cin >> pChoseY;
            
            // See if player hit a ship or not
            if(comp[pChoseY - 1][pChoseX - 1] != "-") {
                cout << endl << "You have hit a ship!" << endl;
                display[pChoseY - 1][pChoseX - 1] = 'O';
                rCount -= 1;
            }
            else if(comp[pChoseY - 1][pChoseX - 1] == "-") {
                cout << endl << "You have missed a ship. Try again." << endl;
                display[pChoseY - 1][pChoseX - 1] = 'X';
            }
            
            cout << endl << "The computer is choosing their coordinates..." << endl;
            
            // use random and linear search to see if computer chose that number already;
            rChoseX = rand() % 8;
            rChoseY = rand() % 8;
            
            while(player[rChoseY - 1][rChoseX] == "X" || player[rChoseY - 1][rChoseX] == "O") {
                rChoseX = rand() % 8;
                rChoseY = rand() % 8;
            }
            
            // See if Computer hit a ship or not
            if(player[rChoseY][rChoseX] != "-") {
                cout << endl << "The Computer has hit a ship!" << endl;
                player[rChoseY][rChoseX] = 'O';
                pCount -= 1;
            }
            else if(player[rChoseY][rChoseX] == "-") {
                cout << endl << "The Computer has missed a ship." << endl;
                player[rChoseY][rChoseX] = 'X';
            }
            
            // Output player's table
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
            
            if(rCount == 0 || pCount == 0) {
                play = 'n';
            }
            
        }
        
        if(rCount == 0) {
            cout << endl << "You have won! The computer has lost all their ships."
                 << endl << "Congratulations " << name << endl << endl;
        }
        else {
            cout << endl << "You have lost! The computer has won and destroyed all your ships."
                 << endl << "Better luck next time " << name << endl << endl;
        }
        
        // Give player choice to play again or not
        cout << endl << "Would you like to play again? (y/n): ";
        cin >> play;
        
        if(play == 'n') {
            again = false;
        }
        else {
            again = true;
            cout << endl << endl;
        }
        
    }
    
    cout << endl << "It was fun playing with you! Good Bye!";
    
    //Exit
    return 0;
}