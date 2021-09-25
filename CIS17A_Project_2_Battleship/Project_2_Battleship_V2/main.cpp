/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jyro Jimenez
 * Created on July 28 2021
 * Purpose:Project 2: Battleship V2 - Changed Structures to classes and added other concepts
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
// Columns in the 2-D Arrays

//Like PI, e, Gravity, or conversions

//Function Prototypes Here
//Bool for choices
bool choice(char);
bool verify(char);
char valid(char);

//******************************************************************************
// Classes...
//******************************************************************************

class data {
protected:
    //Player and Computer's Choices
    int pChoseX, pChoseY, rChoseX, rChoseY;
    //Player and Computer's hits and miss
    int pCount, rCount, pMiss, pHit, rMiss, rHit;
    //Static Int for number of boats
    static int nBoats;
    //Int for number of moves to put in leader board
    int nMoves;
    friend class files;
public:
    data();
    void results(string);
    void pStatus(char);
    void rStatus(char);
    int retrnMoves();
};

class board: public data {
private:
    char **player,
         **comp, 
         **display;
    int  size;
public:
    board(int);
    ~board();
    char **resetDisplay();
    char **resetPattern();
    void printDisplay();
    void printPlayer();
    void game(char);
    int pMissed();
    int pAccuracy();
    int rMissed();
    int rAccuracy();
    void wrtTxt();
};

class files {
private:
    int stats;
    int size;
    int *leader;
public:
    files(int, int);
    ~files();
    int arrayToFileBin(int *);
    int *fileToArray();
    int *returnLead();
};

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
        
        //DONT FORGET TO ADD STL VECTORS FOR LEADERBOARD
        //USE Number of moves for leader baord
        //Use this for binary files calss
        
    }
    
    //Output an ending statement
    cout << endl << "Thank you for visiting! Good Bye!";
    
    //Exit
    return 0;
}

//******************************************************************************
// Functions for Vector sorting...
//******************************************************************************

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

//******************************************************************************
// Functions for boolean operators and try/catch functions...
//******************************************************************************

bool choice(char play) {
    if(play == 'y' || play == 'Y' || play == 'n' || play == 'N') {
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
        }
    }
    else {
        throw play;
    }
    return false;
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
    else {
        throw play;
    }
    return false;
}

char valid(char play) {
    if(play == 'y' || play == 'Y') {
        return play;
    }
    else if(play == 'n' || play == 'N') {
        while(play == 'n' || play == 'N') {
            cout << endl << "What about now? (y/n): ";
            cin >> play;
            cout << endl;
        }
    }
    else {
        throw play;
    }
    return play;
}

//******************************************************************************
// Constructors...
//******************************************************************************

data::data() {
    //Initialize
    pChoseX = 0;
    pChoseY = 0;
    rChoseX = 0;
    rChoseY = 0;
    //Player and Computer's hits and miss
    pCount = 9;
    rCount = 9;
    //initialize number of moves
    nMoves = 0;
}

board::board(int s) {
    size = s;
    display = resetDisplay();
    player = resetPattern();
    comp = resetPattern();
}

//******************************************************************************
// Static Member for Number of Boats...
//******************************************************************************

int data::nBoats = 9;

//******************************************************************************
// Destructor...
//******************************************************************************

board::~board() {
    //Deallocate Display
    for(int i = 0; i < size; i++){
        delete [] display[i];
    }
    delete [] display;
    //Deallocate player
    for(int i = 0; i < size; i++){
        delete [] player[i];
    }
    delete [] player;
    //Deallocate Comp
    for(int i = 0; i < size; i++){
        delete [] comp[i];
    }
    delete [] comp;
}

//******************************************************************************
// Initialize values of the board using another function...
//******************************************************************************

char **board::resetDisplay() {
    //Initialize dynamic array
    char **a = new char*[size];
    //Allocate the memory for each row
    for(int row = 0; row < size; row++) {
        a[row] = new char[size];
    }
    //Initialize Arrays with "-" to fill with ships
    for(int rows = 0; rows < size; rows++) {
        for(int cols = 0; cols < size; cols++) {
            a[rows][cols] = '-';
        }
    }
    //Return values
    return a;
    //Deallocate Values
    for(int i = 0; i < size; i++){
        delete [] a[i];
    }
    delete [] a;
}

char **board::resetPattern() {
    //Initialize dynamic array
    char **a = new char*[size];
    int x, y;
    //Allocate the memory for each row
    for(int row = 0; row < size; row++) {
        a[row] = new char[size];
    }
    //Initialize Arrays with "-" to fill with ships
    for(int rows = 0; rows < size; rows++) {
        for(int cols = 0; cols < size; cols++) {
            a[rows][cols] = '-';
        }
    }
    //Initialize the patterns for the player
    for(int boats = 0; boats < nBoats; boats++) {
        x = rand() % 5;
        y = rand() % 5;
        while(a[x][y] == 'G') {
            x = rand() % 5;
            y = rand() % 5;
        }
        a[x][y] = 'G';
    }
    //Return values
    return a;
    //Deallocate Values
    for(int i = 0; i < size; i++){
        delete [] a[i];
    }
    delete [] a;
}

//******************************************************************************
// Print Player's pattern and Player's Display
//******************************************************************************

void board::printDisplay() {
    cout << endl << "Player Display:" << endl;
    cout << "     X   1   2   3   4   5" << endl;
    cout << "   Y +-----------------------+" << endl;
    for(int rows = 0; rows < size; rows++) {
        cout << "   " << rows + 1 << " |   ";
        for(int cols = 0; cols < size; cols++) {
            cout << display[rows][cols] << "   ";
        }
        cout << "|" << endl;
        if(rows == size - 1) {
            cout << "     +-----------------------+" << endl;
        }
    }
}

void board::printPlayer() {
    cout << endl << "Player Pattern:" << endl;
    cout << "     X   1   2   3   4   5" << endl;
    cout << "   Y +-----------------------+" << endl;
    for(int rows = 0; rows < size; rows++) {
        cout << "   " << rows + 1 << " |   ";
        for(int cols = 0; cols < size; cols++) {
            cout << player[rows][cols] << "   ";
        }
        cout << "|" << endl;
        if(rows == size - 1) {
            cout << "     +-----------------------+" << endl;
        }
    }
}

//******************************************************************************
// Function for the entire game
//******************************************************************************

void board::game(char play) {
    while(play == 'y' || play == 'Y') {
        // Display player's choices
        printDisplay();
        
        // Ask player where they would like to hit and validate
        cout << endl << "What coordinates would you like to shoot in?" << endl;
        
        //Exception check for Y-Coordinate
        try {
            //Input Y
            cout << "Y-Coordinate: ";
            cin >> pChoseY;
            // Validate User input if choice is invalid
            if(pChoseY > 5 || pChoseY <= 0) {
                throw pChoseY;
            }
        }
        catch(int error) {
            cout << endl << "The Y-Coordinate " << error << " is invalid! Try again..." << endl;
            //Do-While loop for input
            do {
            cout << "Y-Coordinate: ";
            cin >> pChoseY;
            } while (pChoseY > 5 || pChoseY <= 0);
        }
        
        //Exception Check for X-Coordinate
        try {
            //Input X
            cout << "X-Coordinate: ";
            cin >> pChoseX;
            // Validate User input if choice is invalid
            if(pChoseX > 5 || pChoseX <= 0) {
                throw pChoseX;
            }
        }
        catch(int error) {
            cout << endl << "The X-Coordinate " << error << " is invalid! Try again..." << endl;
            //Do-While loop for input
            do {
            cout << "X-Coordinate: ";
            cin >> pChoseX;
            } while (pChoseX > 5 || pChoseX <= 0);
        }
        
        //Loop If try The choice is already taken...
        if(display[pChoseY - 1][pChoseX - 1] == 'O' || display[pChoseY - 1][pChoseX - 1] == 'X') {
            do {
                cout << endl << "These are invalid numbers try again..." << endl;
                cout << "Y-Coordinate: ";
                cin >> pChoseY;
                cout << "X-Coordinate: ";
                cin >> pChoseX;
            } while (pChoseX > 5 || pChoseY > 5 || pChoseX <= 0 || pChoseY <= 0 || comp[pChoseY - 1][pChoseX - 1] == 'O' || comp[pChoseY - 1][pChoseX - 1] == 'X');
        }
        
        // See if player hit a ship or not
        if(comp[pChoseY - 1][pChoseX - 1] != '-') {
            cout << endl << "You have hit a ship!" << endl;
            display[pChoseY - 1][pChoseX - 1] = 'O';
            rCount -= 1;
            nMoves++;
        }
        else if(comp[pChoseY - 1][pChoseX - 1] == '-') {
            cout << endl << "You have missed a ship. Try again." << endl;
            display[pChoseY - 1][pChoseX - 1] = 'X';
            nMoves++;
        }
        
        // Output that computer is choosing
        cout << endl << "The computer is choosing their coordinates..." << endl;

        // use random and linear search to see if computer chose that number already;
        rChoseX = rand() % 5;
        rChoseY = rand() % 5;
        //Loop so it doesn't choose the same coordinate again
        while(player[rChoseY][rChoseX] == 'X' || player[rChoseY][rChoseX] == 'O') {
            rChoseX = rand() % 5;
            rChoseY = rand() % 5;
        }

        // See if Computer hit a ship or not
        if(player[rChoseY][rChoseX] != '-') {
            cout << endl << "The Computer has hit a ship!" << endl;
            player[rChoseY][rChoseX] = 'O';
            pCount -= 1;
        }
        else if(player[rChoseY][rChoseX] == '-') {
            cout << endl << "The Computer has missed a ship." << endl;
            player[rChoseY][rChoseX] = 'X';
        }

        // Output player's table
        printDisplay();
        printPlayer();
        
        
        //If statement to end game if there are no more boats left for one or both sides
        if(rCount == 0 || pCount == 0) {
            play = 'n';
        }
        
    }

    // Use linear search to determine how much you missed and how much you hit.
    // Calculate player and computer's accuracy
    pMiss = pMissed();
    pHit = pAccuracy();
    rMiss = rMissed();
    rHit = rAccuracy();
    
    //Write Both results and txt
    wrtTxt();
}

//******************************************************************************
// Function for results...
//******************************************************************************

int data::retrnMoves() {
    //return Number of moves to main
    return nMoves;
}

//******************************************************************************
// Function for results...
//******************************************************************************

void data::results(string name) {
    if(rCount == 0) {
        cout << endl << "You have won! The computer has lost all their ships."
             << endl << "Congratulations " << name << "!" << endl << endl;
    }
    else if(pCount == 0){
        cout << endl << "You have lost! The computer has won and destroyed all your ships."
             << endl << "Better luck next time " << name << "!" << endl << endl;
    }
    else if(pCount == rCount){
        cout << endl << "You have tied! your ships and the computer's ships are all destroyed."
             << endl << "Better luck next time " << name << "!" << endl << endl;
    }
}

//******************************************************************************
// Function for Player and Computer Stats...
//******************************************************************************

int board::pMissed() {
    //Initialize to 0
    pMiss = 0;
    //Count how much is missed
    for(int i = 0; i < size; i++) {
        for(int u = 0; u < size; u++) {
            if(display[i][u] == 'X') {
                pMiss += 1;
            }
        }
    }
    //return results
    return pMiss;
}

int board::pAccuracy() {
    //Initialize to 0
    pHit = 0;
    //Count how much is hit
    for(int i = 0; i < size; i++) {
        for(int u = 0; u < size; u++) {
            if(display[i][u] == 'O') {
                pHit += 1;
            }
        }
    }
    //return results
    return pHit;
}

int board::rMissed() {
    //Initialize to 0
    rMiss = 0; 
    //Count how much is missed
    for(int i = 0; i < size; i++) {
        for(int u = 0; u < size; u++) {
            if(player[i][u] == 'X') {
                rMiss += 1;
            }
        }
    }
    //return results
    return rMiss;
}

int board::rAccuracy() {
    //Initialize to 0
    rHit = 0;
    //Count how much is hit
    for(int i = 0; i < size; i++) {
        for(int u = 0; u < size; u++) {
            if(player[i][u] == 'O') {
                rHit += 1;
            }
        }
    }
    //return results
    return rHit;
}

void data::pStatus(char stats) {
    if(stats == 'y' || stats == 'Y') {
        cout << "Player missed     = " << pMiss << endl;
        cout << "Player hit        = " << pHit << endl;
    }
    else if(stats == 'n' || stats == 'N'){
        cout << "That's a shame!" << endl;
    }
    else {
        throw stats;
    }
}

void data::rStatus(char stats) {
    if(stats == 'y' || stats == 'Y') {
        cout << "Computer missed   = " << rMiss << endl;
        cout << "Computer hit      = " << rHit << endl;
    }
    else if(stats == 'n' || stats == 'N'){
        cout << "That's a shame!" << endl;
    }
    else {
        throw stats;
    }
}

//******************************************************************************
// Write The match results to a binary file...
//******************************************************************************

void board::wrtTxt(){
    //Declare fstream variables
    fstream out;
    out.open("data.txt",ios::in|ios::out);
    
    //output Diagrams
    out << endl << "Player Display:" << endl;
    out << "     X   1   2   3   4   5" << endl;
    out << "   Y +-----------------------+" << endl;
    for(int rows = 0; rows < size; rows++) {
        out << "   " << rows + 1 << " |   ";
        for(int cols = 0; cols < size; cols++) {
            out << display[rows][cols] << "   ";
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
            out << player[rows][cols] << "   ";
        }
        out << "|" << endl;
        if(rows == size - 1) {
            out << "     +-----------------------+" << endl;
        }
    }
    //Output Results
    out << "Player missed     = " << pMiss << endl;
    out << "Player hit        = " << pHit << endl;
    out << "Computer missed   = " << rMiss << endl;
    out << "Computer hit      = " << rHit << endl;
}