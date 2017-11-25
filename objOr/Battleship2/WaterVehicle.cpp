//
// Created by scott on 11/24/17.
//

#include "WaterVehicle.h"
using std::string;
using std::cout;
using std::endl;

WaterVehicle::WaterVehicle() {
    name = "empty";
    length = 0;
    hitpoints = 0;
    sunk = false;
}

WaterVehicle::WaterVehicle( string name ) {
    this->name = name;
    // set length based on name of ship
    if ( name == "Carrier" )
        length = 5;
    else if ( name == "Battleship" )
        length = 4;
    else if ( name == "Destroyer" )
        length = 3;
    else if ( name == "Submarine" )
        length = 3;
    else if ( name == "PT Boat" )
        length = 2;
    else if ( name == "Cruiser" )
        length = 1;
    else {
        cout << "Error: Invalid Ship Name\nDefault length 2 used" << endl;
        length = 2;
    }

    hitpoints = length;
    sunk = false;
}

void WaterVehicle::decrimentHP() {
    hitpoints--;

    if ( hitpoints == 0 )
        sunk = true;

}