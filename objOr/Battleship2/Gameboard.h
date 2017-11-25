//
// Created by scott on 11/24/17.
//

#ifndef BATTLESHIP2_GAMEBOARD_H
#define BATTLESHIP2_GAMEBOARD_H
#include "WaterVehicle.h"
#include <iostream>

class Gameboard {
public:
    Gameboard(); //default constructor
    Gameboard( std::string ); //constructor
    // other
    void initializeShotBoard(); //sets all values in array to " "
    void displayShipBoard(); //displays grid with ships and opponent shots
    void displayShotBoard(); //displays grid with player's past shots
    bool validateShot( std::string ); //validates coordinate of shot
    int charToInt( char ); //converts char coordinate input to number
    void takeShot(); //places shot on board and checks hit/miss
    void placeBoat(); //positions ship on board

private:
    WaterVehicle* shipBoard[10][10];
    std::string shotBoard[10][10];
    WaterVehicle *ship1, *ship2, *ship3, *ship4, *ship5, *ship6;

};


#endif //BATTLESHIP2_GAMEBOARD_H
