/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   items.h
 * Author: jyroj
 *
 * Created on July 30, 2021, 8:27 PM
 */

#include <string>
using namespace std;

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
    int *returnLead() {
        return leader;
    }
    void printLead(int *, char);
};