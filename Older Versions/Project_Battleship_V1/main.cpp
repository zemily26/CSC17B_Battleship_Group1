/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on June 1 2021
 * Purpose:Project 2: Battleship (Just the Patterns used and some variable to use)
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
    
    // Player and computer fields
    char* display[rows][cols];
    char* player[rows][cols];
    char* enemy[rows][cols];
    
    // Different patterns to the game
    // Pattern 1
    char* ptrn1[rows][cols] = { {"-", "-", "-", "-", "-", "-", "-", "-"}, 
                                {"-", "C", "D", "D", "-", "-", "-", "-"}, 
                                {"-", "C", "-", "S", "S", "S", "-", "-"},
                                {"-", "C", "-", "-", "-", "-", "M", "-"},
                                {"-", "C", "-", "-", "-", "-", "M", "-"},
                                {"-", "C", "-", "-", "-", "-", "M", "-"},
                                {"-", "-", "B", "B", "B", "B", "-", "-"},
                                {"-", "-", "-", "-", "-", "-", "-", "-"} };
    
    // Pattern 2
    char* ptrn2[rows][cols] = { {"-", "-", "-", "B", "B", "B", "B", "-"}, 
                                {"M", "M", "M", "-", "-", "-", "-", "-"}, 
                                {"-", "-", "-", "-", "-", "-", "-", "-"},
                                {"-", "-", "-", "-", "-", "-", "-", "-"},
                                {"-", "-", "D", "D", "-", "-", "-", "-"},
                                {"-", "-", "-", "C", "C", "C", "C", "C"},
                                {"-", "-", "-", "-", "-", "-", "-", "-"},
                                {"-", "-", "-", "-", "-", "S", "S", "S"} };
    
    // Pattern 3
    char* ptrn3[rows][cols] = { {"-", "-", "-", "C", "C", "C", "C", "C"}, 
                                {"-", "-", "-", "-", "-", "-", "-", "-"}, 
                                {"-", "S", "-", "-", "-", "-", "-", "-"},
                                {"-", "S", "-", "D", "-", "M", "-", "-"},
                                {"-", "S", "-", "D", "-", "M", "-", "-"},
                                {"-", "-", "-", "-", "-", "M", "-", "-"},
                                {"-", "-", "-", "-", "-", "-", "-", "-"},
                                {"B", "B", "B", "B", "-", "-", "-", "-"} };
    
    // Pattern 4
    char* ptrn4[rows][cols] = { {"-", "-", "-", "-", "-", "-", "-", "-"}, 
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
    int pChoseX, pChoseY, rChoseX, rChoseY, pCount, rCount, play;
    
    //Initialize Variables
    
    //Process/Map inputs to outputs
    
    //Output data
    
    cout << "Pattern 1:" << endl;
    for(int i = 0; i < rows; i++) {
        
        for(int u = 0; u < cols; u++) {
            cout << ptrn1[i][u] << " ";
        }
        
        cout <<  endl;
    }
    
    cout << endl << "Pattern 2:" << endl;
    for(int i = 0; i < rows; i++) {
        
        for(int u = 0; u < cols; u++) {
            cout << ptrn2[i][u] << " ";
        }
        
        cout <<  endl;
    }
    
    cout << "Pattern 3:" << endl;
    for(int i = 0; i < rows; i++) {
        
        for(int u = 0; u < cols; u++) {
            cout << ptrn3[i][u] << " ";
        }
        
        cout <<  endl;
    }
    
    cout << endl << "Pattern 4:" << endl;
    for(int i = 0; i < rows; i++) {
        
        for(int u = 0; u < cols; u++) {
            cout << ptrn4[i][u] << " ";
        }
        
        cout <<  endl;
    }
    
    cout << endl << "Pattern 5:" << endl;
    for(int i = 0; i < rows; i++) {
        
        for(int u = 0; u < cols; u++) {
            cout << ptrn5[i][u] << " ";
        }
        
        cout <<  endl;
    }
    //Exit
    return 0;
}