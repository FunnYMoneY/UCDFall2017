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
    Gameboard( std::string ); //takes file path

    // constructor helpers
    void initializeShotBoard(); //sets all values in array to " "
    void nullShipBoard(); //
    void randomizeBoard();
    void randomizeShipPlacement( WaterVehicle* );
    void initializeShipBoard(); //
    bool initializeShip( WaterVehicle*, std::ifstream& );
    bool placeShip( WaterVehicle*, int, int, char ); //positions ship on board
    bool placeShipDown( WaterVehicle*, int, int );
    bool placeShipUp( WaterVehicle*, int, int );
    bool placeShipRight( WaterVehicle*, int, int );
    bool placeShipLeft( WaterVehicle*, int, int );

    // coordinate functions
    void convertCoordInput( std::string, int* );
    int convertYChar( char ); //converts Y coordinate input to integer
    int convertXChar( char ); //converts x coordinate input to integer
    bool charIsInt( char ); //

    // display
    void displayShipBoard(); //displays grid with player's ships
    void displayShotBoard(); //displays grid with player's shots made
    void displayShotsOverShips(Gameboard&); //displays grid with player's ships and opponents shots

    // shooting
    bool validShot( int, int ); //validates coordinate of shot
    bool shoot( const std::string&, Gameboard* ); //places shot on board and checks hit/miss
    bool allShipsSunk();


private:
    WaterVehicle* shipBoard[10][10];
    std::string shotBoard[10][10];
    WaterVehicle *ship1, *ship2, *ship3, *ship4, *ship5, *ship6;

};


#endif //BATTLESHIP2_GAMEBOARD_H
