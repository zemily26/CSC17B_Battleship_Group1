#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <cstdlib>
#include "View.h"
#include "Model.h"
#include "Input.h"

class Controller {
private:
  char userInput;
public:
  Model pdata;
  View display;
  Input in;
  Controller();
  void setUp();
  void mainMenu();
  
};

#endif /* CONTROLLER_H */
