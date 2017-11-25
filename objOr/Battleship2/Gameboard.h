//
// Created by scott on 11/24/17.
//

#ifndef BATTLESHIP2_GAMEBOARD_H
#define BATTLESHIP2_GAMEBOARD_H
#include "WaterVehicle.h"
#include <iostream>

class Gameboard {
public:
    // constructors
    Gameboard();
    Gameboard( std::string );
    // constructor helpers
    void initializeShotBoard(); //sets all values in array to " "
    void initializeShipBoard();//
    void initializeShip( WaterVehicle*, std::ifstream& );
    void placeShip( WaterVehicle*, int, int, char ); //positions ship on board
    // coordinate functions
    int* convertCoordInput( std::string );

    // display
    void displayShipBoard(); //displays grid with ships and opponent shots
    void displayShotBoard(); //displays grid with player's past shots
    // other
    bool validateShot( std::string ); //validates coordinate of shot
    int charToInt( char ); //converts char coordinate input to number
    void takeShot(); //places shot on board and checks hit/miss


private:
    WaterVehicle* shipBoard[10][10];
    std::string shotBoard[10][10];
    WaterVehicle *ship1, *ship2, *ship3, *ship4, *ship5, *ship6;

};


#endif //BATTLESHIP2_GAMEBOARD_H
