/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   data.h
 * Author: jyroj
 *
 * Created on July 17, 2021, 7:04 PM
 */

#ifndef DATA_H
#define DATA_H

struct board {
    char **player, **comp, **display;
};

struct data{
    board *arrays;
    int pChoseX, pChoseY, rChoseX, rChoseY, pCount, rCount, pMiss, pHit, rMiss, rHit, nBoats;
};

#endif /* DATA_H */

