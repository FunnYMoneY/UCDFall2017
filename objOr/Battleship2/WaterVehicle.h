//
// Created by scott on 11/24/17.
//

#ifndef BATTLESHIP2_WATERVEHICLE_H
#define BATTLESHIP2_WATERVEHICLE_H
#include <iostream>

class WaterVehicle {
public:
    WaterVehicle(); //default constructor
    WaterVehicle( std::string name ); //constructor
    // getters
    std::string getName() { return name; }
    int getLength() { return length; }
    int getHP() { return hitpoints; }
    bool isSunk() { return sunk; }
    // other
    void decrimentHP();

private:
    std::string name;
    int length, hitpoints;
    bool sunk;
};


#endif //BATTLESHIP2_WATERVEHICLE_H
