//
// Created by scott on 11/24/17.
//

#include "Gameboard.h"
#include <iomanip>
using std::cout;
using std::endl;
using std::string;

Gameboard::Gameboard() {
    initializeShotBoard();

}

Gameboard::Gameboard(std::string filePath) {

}

void Gameboard::initializeShotBoard() {
    for ( int y = 0; y < 10; y++ ) {
        for ( int x = 0; x < 10; x++ )
            shotBoard[y][x] = " ";
    }
}

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

bool Gameboard::validateShot( string coordinate ) {
    bool valid = true;
    int ycoord = charToInt( coordinate[0] );
    if ( char charToInt( coordinate[2] == 0 ) )
        
    cout << charToInt(coordinate[0]) << endl;
    if ( charToInt( coordinate[0] ) == -1 || charToInt( coordinate[1] ) == -1 )
        valid = false;
    if ( valid && charToInt( coordinate[2] ) != 0 )
        valid = false;

    if(valid)
        cout << "true\n";
    else
        cout << "false\n";

    return valid;
}

int Gameboard::charToInt( char in ) {
    int coord = 0;
    if ( in >= 'A' && in <= 'J' )
        coord = in - 'A' + 1;
    else if ( in >= 'a'  && in <= 'j' )
        coord = in - 'a' + 1;
    else if ( in >= '1' && in <= '9' )
        coord = in - '0';
    return coord;

    /*int numCoord = 0;
    if ( letter == 'A' || letter == 'a' )
        numCoord = 1;
    else if ( letter == 'B' || letter == 'b' )
        numCoord = 2;
    else if ( letter == 'C' || letter == 'c' )
        numCoord = 3;
    else if ( letter == 'D' || letter == 'd' )
        numCoord = 4;
    else if ( letter == 'E' || letter == 'e' )
        numCoord = 5;
    else if ( letter == 'F' || letter == 'f' )
        numCoord = 6;
    else if ( letter == 'G' || letter == 'g' )
        numCoord = 7;
    else if ( letter == 'H' || letter == 'h' )
        numCoord = 8;
    else if ( letter == 'I' || letter == 'i' )
        numCoord = 9;
    else if ( letter == 'J' || letter == 'j' )
        numCoord = 10;
    return numCoord;
     */
}

void Gameboard::takeShot() {

}

void Gameboard::placeBoat() {

}
