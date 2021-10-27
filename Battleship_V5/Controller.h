#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <cstdlib>
#include "Constants.h"
#include "View.h"
#include "Model.h"

class Controller {
private:
  View out;
  Input in;
  Model pdata;
  PlayerData players;
  
public:
  Controller();
  void setUp();
  void play();
  void stats(); //times shot etc.
  void write(); //calls the file write function
  void leaderboard();//Calls a view function that displays the leaderboard
  void stats(); //Calls a view funtion that displays current player stats????

};

#endif /* CONTROLLER_H */
