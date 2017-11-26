//
// Created by scott on 11/26/17.
//

#include "Human.h"


//-----------------------------constructors---------------------------

Human::Human() {
    name = "Default";
    myBoard = new Gameboard();
    outOfShips = myBoard->allShipsSunk();
}

Human::Human(std::string name, std::string filePath) {
    this->name = name;
    int choice;
    bool done = false;

    //choose ship configuration preference
    while (!done) {
        std::cout << "Enter 1 to use configuration file or 2 to randomize ship placement: ";
        std::cin >> choice;
        if (choice == 1) {
            myBoard = new Gameboard(filePath);
            done = true;
        }
        else if (choice == 2) {
            myBoard = new Gameboard();
            done = true;
        }
        else
            std::cout << "Invalid option\n";
        std::cin.clear();
    }

    outOfShips = myBoard->allShipsSunk();
}



//--------------------------------turn--------------------------------

bool Human::takeTurn(Player &opponent, std::string input) {
    if(takeShot(opponent, input)) {
        opponent.setShipStatus();
        return true;
    }
    else
        return false;
}

bool Human::takeShot(Player &opponent, std::string &coordInput) {
    return myBoard->shoot(coordInput, opponent.getMyBoard());
}