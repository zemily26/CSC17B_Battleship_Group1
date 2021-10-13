
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"
#include "View.h"
#include "Input.h"
#include "File.h"

class Controller {
public:
    Controller();
    Controller(const Controller& orig);
    virtual ~Controller();
private:
    Model model;
    View view;
    Input input;
    File file;
    
    //To-Do Program Flow
    //int MainLoop();
    //int MenuLoop();
    //int GameLoop();
    void InitializeGame(bool AI);
};

#endif /* CONTROLLER_H */

