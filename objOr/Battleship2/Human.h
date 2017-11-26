//
// Created by scott on 11/26/17.
//

#ifndef BATTLESHIP2_HUMAN_H
#define BATTLESHIP2_HUMAN_H
#include <iostream>
#include "Player.h"
#include "Gameboard.h"

class Human : public Player {
public:
    //constructors
    Human();
    Human(std::string, std::string); //takes name and file path

    //turn
    bool takeTurn(Player&, std::string);
    bool takeShot(Player&, std::string&);


private:
    //none
};


#endif //BATTLESHIP2_HUMAN_H
