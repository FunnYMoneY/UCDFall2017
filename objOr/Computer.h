//
// Created by Scott Clay on 10/29/17.
//

#ifndef FINALPROJBATTLESHIP_COMPUTER_H
#define FINALPROJBATTLESHIP_COMPUTER_H
#include "Player.h"

class Computer : public Player {
public:
    Computer( int );
    void takeTurn();
    void randCoords();
    void smartCoords();
    void populateBoard();

private:
    int difficulty; //difficulty 1 - easy or 2 - hard
};


#endif //FINALPROJBATTLESHIP_COMPUTER_H
