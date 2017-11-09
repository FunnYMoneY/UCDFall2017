//
// Created by Scott Clay on 10/29/17.
//

#ifndef FINALPROJBATTLESHIP_HUMAN_H
#define FINALPROJBATTLESHIP_HUMAN_H
#include "Player.h"

class Human : public Player{
public:
    explicit Human( std::string );
    void takeTurn();
    void inputCoords();
    void populateBoard();
};


#endif //FINALPROJBATTLESHIP_HUMAN_H
