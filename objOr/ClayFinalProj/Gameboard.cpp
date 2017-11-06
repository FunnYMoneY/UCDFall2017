//
// Created by Scott Clay on 10/11/17.
//

#include "Gameboard.h"
#include <iostream>
using std::cout;
using std::endl;

Gameboard::Gameboard() {
    grid = new char*[ROWS];
    for (int i = 0; i < ROWS; i++) {
        grid[i] = new char[COLS];
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
        }
    }
}

int Gameboard::getRows() const { return ROWS; }

int Gameboard::getCols() const { return COLS; }

void Gameboard::printBoard() const {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << '[' << grid[i][j] << ']';
        }
        cout << endl;
    }
}