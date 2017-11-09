//
// Created by Scott Clay on 10/29/17.
//

#ifndef FINALPROJBATTLESHIP_PLAYER_H
#define FINALPROJBATTLESHIP_PLAYER_H
#include <iostream>
#include "Gameboard.h"


class Player {
public:
    Player();
    void setOutOfShips( bool );

    Gameboard getBoard();
    std::string getName();
    bool isOutOfShips();

    virtual void populateBoard() = 0;
    virtual void takeTurn() = 0;
    virtual void takeShot();

protected:
    std::string name;
    Gameboard board;
    bool outOfShips;
};


#endif //FINALPROJBATTLESHIP_PLAYER_H
