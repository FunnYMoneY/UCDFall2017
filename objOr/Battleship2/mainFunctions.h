//
// Created by scott on 11/15/17.
//

#ifndef BATTLESHIP2_MAINFUNCTIONS_H
#define BATTLESHIP2_MAINFUNCTIONS_H

#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Computer.h"

void displayTurnBoards(Player&, Player&); //Displays player shot and ship board

void displayEndOfGameBoards(Player&, Player&); // Displays players' final ship boards

std::string coordinateInput(); //asks for and returns user input

void startTurn(); //break between turns


#endif //BATTLESHIP2_MAINFUNCTIONS_H
