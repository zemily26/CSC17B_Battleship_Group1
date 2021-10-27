
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"
#include "View.h"
#include "Input.h"
#include "File.h"
#include "Constants.h"

View display;
Input user;
PlayerData stats;


class Controller {
private:
  char userInput;
public:
  Controller();
  virtual ~Controller();
};

#endif /* CONTROLLER_H */
