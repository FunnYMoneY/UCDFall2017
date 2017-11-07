//
// Created by Scott Clay on 10/29/17.
//

#ifndef FINALPROJBATTLESHIP_GAMEBOARD_H
#define FINALPROJBATTLESHIP_GAMEBOARD_H
#include <iostream>
#include <map>
#include <fstream>
#include "WaterVehicle.h"

class Gameboard {
public:
    Gameboard() throw ( std::string );
    void initializeShip( WaterVehicle&, std::ifstream& );


private:
    WaterVehicle Carrier, Battleship, Destroyer, Submarine, PTboat, Cruiser;
    WaterVehicle shipBoard[10][10];
    std::map<std::string, WaterVehicle> positionBoard;

};


#endif //FINALPROJBATTLESHIP_GAMEBOARD_H
