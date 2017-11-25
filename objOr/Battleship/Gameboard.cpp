//
// Created by Scott Clay on 10/29/17.
//

#include "Gameboard.h"
using std::cout;
using std::cin;
using std::endl;

Gameboard::Gameboard() throw ( std::string ) {
    //read file
    std::ifstream positionsFile( "Positions.txt" );
    if ( !positionsFile.is_open() )
        throw "Error Reading File";
    initializeShip(Carrier, positionsFile);
    //positionsFile.ignore('\n');
    initializeShip(Battleship, positionsFile);
    //positionsFile.ignore('\n');
    initializeShip(Destroyer, positionsFile);
    //positionsFile.ignore('\n');
    initializeShip(Submarine, positionsFile);
    //positionsFile.ignore('\n');
    initializeShip(PTboat, positionsFile);
    //positionsFile.ignore('\n');
    initializeShip(Cruiser, positionsFile);



}

void Gameboard::initializeShip( WaterVehicle* ship, std::ifstream &infile) {
    *ship = WaterVehicle( infile );
}

bool Gameboard::checkShot( ) {

}
