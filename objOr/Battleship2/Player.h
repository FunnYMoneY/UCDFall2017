//
// Created by scott on 11/15/17.
//

#ifndef BATTLESHIP2_PLAYER_H
#define BATTLESHIP2_PLAYER_H
#include <iostream>
#include "Gameboard.h"

class Player {
public:
    //constructors
    Player();
    //destructor
    ~Player();

    //getters
    std::string getName() { return name; }
    Gameboard* getMyBoard() { return myBoard; }
    bool isOutOfShips() { return outOfShips; }

    //setters
    void setShipStatus() { outOfShips = myBoard->allShipsSunk(); }
        //sets out of ships based on gameboard.allShipSunk

    //turn
    virtual bool takeTurn();
    void displayMyBoard(Gameboard&);
    void displayMyShipBoard(Gameboard&);

protected:
    std::string name;
    Gameboard* myBoard;
    bool outOfShips;

};


#endif //BATTLESHIP2_PLAYER_H
