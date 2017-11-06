//
// Created by Scott Clay on 10/11/17.
//

#include "Battleship.h"
#include <iostream>
using std::cout;
using std::endl;

Battleship::Battleship() {
    cout << "Welcome to Battleship!";
    printBoard();
}

void Battleship::printBoard() const {
    board.printBoard();
}