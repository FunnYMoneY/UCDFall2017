//
// Created by Scott Clay on 10/30/17.
//

#ifndef FINALPROJBATTLESHIP_BATTLESHIPFUNCTIONS_H_H
#define FINALPROJBATTLESHIP_BATTLESHIPFUNCTIONS_H_H
#include <cstdlib>
#include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Gameboard.h"
#include "WaterVehicle.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

void mainMenu() {
    cout << "Welcome To Battleship!\n\n"
         << "\tMain Menu\n"
         << "1. Player vs. CPU\n"
         << "2. Player vs. Player\n"
         << "3. Player vs. Player vs. CPU\n"
         << "4. Rules\n" << "5. Quit\n";
}

int chooseDifficulty() {
    int difficulty = 0;
    bool valid = false;
    while ( !valid ) {
        system( "clear" );
        valid = true;
        cout << "Choose Difficulty\n" << "1. WAH! I'm a baby\n"
             << "2. Make the computer smart!\n";
        cin >> difficulty;
        if (difficulty < 1 || difficulty > 2) {
            cout << "Please Enter a valid difficulty";
            valid = false;
        }
    }
    return difficulty;
}

bool playRound( Player &player1, Player &player2 ) {
    bool gameOver = false;
    player1.takeTurn();
    if ( player2.isOutOfShips() )
        gameOver = true;
    player2.takeTurn();
    if ( player1.isOutOfShips() )
        gameOver = true;
    return gameOver;
}


#endif //FINALPROJBATTLESHIP_BATTLESHIPFUNCTIONS_H_H
