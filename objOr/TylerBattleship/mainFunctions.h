//
// Created by Tyler Seale on 11/24/17.
//

#ifndef BATTLESHIP_MAINFUNCTIONS_H
#define BATTLESHIP_MAINFUNCTIONS_H

#include "gameboard.h"

namespace mainFunctions {
    void displayTurnBoards(gameboard*);

    string coordinateInput();

    void startTurn();
}

#endif //BATTLESHIP_MAINFUNCTIONS_H
