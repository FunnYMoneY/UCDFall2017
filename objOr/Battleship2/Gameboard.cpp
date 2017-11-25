//
// Created by scott on 11/24/17.
//

#include "Gameboard.h"
#include <iomanip>
#include <fstream>
using std::cout;
using std::endl;
using std::string;

Gameboard::Gameboard() {
    initializeShotBoard();

}

Gameboard::Gameboard(string filePath) {
    initializeShotBoard();
    std::ifstream infile( filePath.c_str() );

    initializeShip( ship1, infile );
    initializeShip( ship2, infile );
    initializeShip( ship3, infile );
    initializeShip( ship4, infile );
    initializeShip( ship5, infile );
    initializeShip( ship6, infile );

}

//----------------------Constructor Helpers------------------------
void Gameboard::initializeShotBoard() {
    for ( int y = 0; y < 10; y++ ) {
        for ( int x = 0; x < 10; x++ )
            shotBoard[y][x] = " ";
    }
}

void Gameboard::initializeShipBoard() {

}

void Gameboard::initializeShip( WaterVehicle* ship, std::ifstream &infile ) {
    string name;
    getline( infile, name, ',' );
    ship = new WaterVehicle( name );
    infile.ignore(' ');

    string startingPos;
    getline( infile, startingPos, ',' );
    int* coord = convertCoordInput(startingPos);
    if (coord[0] == -1 || coord[1] == -1) {
        //todo
    }

    infile.ignore(' ');
    string orientation;
    getline( infile, orientation);

    placeShip( ship, coord[0], coord[1], orientation[0] );

}

void Gameboard::placeShip( WaterVehicle* ship, int x, int y, char orientation ) {
    //todo
}

int* Gameboard::convertCoordInput(string) {
    //todo
}

random boat


//----------------------------Display-------------------------------
void Gameboard::displayShipBoard() {
    cout << "Players Ships/Opponent's shots\n";
    for ( int y = 0; y < 10; y++ ) {
        cout << std::setw(22) << std::setfill('-') << "-\n";
        cout << "|";
        for ( int x = 0; x < 10; x++ ) {
            if ( shipBoard[y][x] == NULL )
                cout << " |";
            else
                cout << "x|";
        }
        cout << endl;
    }
    cout << std::setw(22) << std::setfill('-') << "-\n";
}

void Gameboard::displayShotBoard() {
    cout << "Payers Shots\n";
    for ( int y = 0; y < 10; y++ ) {
        cout << std::setw(22) << std::setfill('-') << "-\n";
        cout << "|";
        for ( int x = 0; x < 10; x++ ) {
            cout << shotBoard[y][x] << "|";
        }
        cout << endl;
    }
    cout << std::setw(22) << std::setfill('-') << "-\n";
}

//------------------------------Shot stuff--------------------------------
bool Gameboard::validateShot( string coordinate ) {
    bool valid = false;
    if ( coordinate[0] >= 'A' && coordinate[0] <= 'J' || coordinate[0] >= 'a' && coordinate[0] <= 'j' ) {
        if (coordinate[1] >= '1' && coordinate[1] <= '9') {
            if (coordinate.length() == 3) {
                if (coordinate[2] == '0')
                    valid = true;
            } else
                valid = true;
        }
    }
    return valid;
}

void Gameboard::takeShot() {

}

