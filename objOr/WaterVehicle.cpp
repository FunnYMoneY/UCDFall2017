//
// Created by Scott Clay on 10/29/17.
//

#include "WaterVehicle.h"
#include <map>
#include <fstream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

WaterVehicle::WaterVehicle(  ) {

}

WaterVehicle::WaterVehicle( std::ifstream &positions ) {
    readShipFile( positions );
    hitPoints = length;
    sunk = false;
}

void WaterVehicle::readShipFile( std::ifstream &positions ) throw( string ){
    const char DELIMITER = ',';
    char row;
    int column;
    std::map<string, int> shipTypes;
    shipTypes["Carrier"] = 5;
    shipTypes["Battleship"] = 4;
    shipTypes["Destroyer"] = 3;
    shipTypes["Submarine"] = 3;
    shipTypes["PT Boat"] = 2;
    shipTypes["Cruiser"] = 1;

    //Set type
    getline( positions, type, DELIMITER );
    if ( shipTypes.find(type) == shipTypes.end() )
        throw "typeError";

    //Set starting coordinate
    getline( positions, startingCoord, DELIMITER );
    row = startingCoord[0];
    column = ( int )startingCoord[1];
    if ( row < 'A' || row > 'J' ) {
        if ( row < 'a' || row > 'j')
            throw "coordinateError";
    }
    if ( column < 1 || column > 10 )
        throw "coordinateError";

    getline( positions, orientation, DELIMITER );
    if ( orientation != "H" || orientation != "V" )
        throw "orientationError";

    //Set length
    length = shipTypes.find( type )->second;

}

void WaterVehicle::decrementHP() {
    hitPoints--;
    if ( hitPoints == 0 )
        sunk = true;
}

string WaterVehicle::getType() {
    return type;
}

int WaterVehicle::getHitPoints() {
    return hitPoints;
}