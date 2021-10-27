#include <cstdlib>
#include <iostream>
#include <string>

#include "Controller.h"
using namespace std;
int main(int argc, char** argv) {
    //Variables for main function
    char rMenu; //to return to menu
    Controller game;
    do {
      game.mainMenu();
      cout<<"return to main menu (Y/N): ";
      cin>>rMenu;
    } while(toupper(rMenu)=='Y');
    
    /*
    game.start();
    switch(game.)
    do{
      game.setup();
      game.twoPlayer();
      game.ai();
    }while(userInput!=0);
    */
    
    return 0;
    
}

