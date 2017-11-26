//
// Created by scott on 11/15/17.
//

#include "Gameboard.h"
#include <iomanip>
#include <fstream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;


//---------------------------constructors----------------------------

Gameboard::Gameboard() {
    randomizeBoard();
    initializeShotBoard();

}


Gameboard::Gameboard(string filePath) {
    initializeShotBoard();

    bool boatsPlaced = true;

    //open file
    std::ifstream file( filePath.c_str() );
    if ( !file.is_open() ) {
        cout << "File Error: " << filePath << " unable to be opened.\n";
        boatsPlaced = false;
    }
    // read file
    if(boatsPlaced)
        boatsPlaced = initializeShip(ship1, file);
    if(boatsPlaced)
        boatsPlaced = initializeShip(ship2, file);
    if(boatsPlaced)
        boatsPlaced = initializeShip(ship3, file);
    if(boatsPlaced)
        boatsPlaced = initializeShip(ship4, file);
    if(boatsPlaced)
        boatsPlaced = initializeShip(ship5, file);
    if(boatsPlaced)
        boatsPlaced = initializeShip(ship6, file);
    // close file
    file.close();

    // if there was a problem, create default board
    if(!boatsPlaced) {
        cout << "Cannot create board from file. Creating random board instead...\n\n";
        nullShipBoard();
        randomizeBoard();
    }



    /*string line;
    std::ifstream infile( filePath.c_str() );
    if ( !infile.is_open() ){
        cout << "Error Reading File: Using default gameboard\n";
    }
    else {
        initializeShotBoard();
        initializeShipBoard();
        bool shipPlaced = true;
        if (shipPlaced)
            initializeShip( ship1, infile );
        if (shipPlaced)
            initializeShip( ship2, infile );
        if (shipPlaced)
            initializeShip( ship3, infile );
        if (shipPlaced)
            initializeShip( ship4, infile );
        if (shipPlaced)
            initializeShip( ship5, infile );
        if (shipPlaced)
            initializeShip( ship6, infile );
    }*/

}



//------------------------Constructor Helpers-------------------------

void Gameboard::initializeShotBoard() {
    for ( int y = 0; y < 10; y++ ) {
        for ( int x = 0; x < 10; x++ )
            shotBoard[y][x] = " ";
    }
}


void Gameboard::nullShipBoard(){
    for (int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++)
            shipBoard[y][x] = NULL;
    }
}


void Gameboard::randomizeBoard() {
    // create and place each boat
    ship1 = new WaterVehicle("Carrier");
    randomizeShipPlacement(ship1);
    ship2 = new WaterVehicle("Battleship");
    randomizeShipPlacement(ship2);
    ship3 = new WaterVehicle("Destroyer");
    randomizeShipPlacement(ship3);
    ship4 = new WaterVehicle("Submarine");
    randomizeShipPlacement(ship4);
    ship5 = new WaterVehicle("PT Boat");
    randomizeShipPlacement(ship5);
    ship6 = new WaterVehicle("Cruiser");
    randomizeShipPlacement(ship6);
}


void Gameboard::randomizeShipPlacement(WaterVehicle* boat){
    bool shipPlaced = false;

    // while the boat is not placed, keep trying random placements
    while(!shipPlaced) {
        int randX = rand() % 10;
        int randY = rand() % 10;
        char orientation;

        if (rand() % 2 == 0)
            orientation = 'V';
        else
            orientation = 'H';

        shipPlaced = placeShip(boat, randX, randY, orientation);
    }
}


void Gameboard::initializeShipBoard() {
    for ( int y = 0; y < 10; y++ ) {
        for ( int x = 0; x < 10; x++ )
            shipBoard[y][x] = NULL;
    }
}


bool Gameboard::initializeShip( WaterVehicle* ship, std::ifstream &infile ) {
    // get boat name
    string name;
    getline( infile, name, ',' );
    if(infile.eof())
        return false;

    // initialize boat
    ship = new WaterVehicle(name);

    // get starting coord
    infile.ignore(' ');
    string startingPos;
    getline( infile, startingPos, ',' );
    if(infile.eof())
        return false;

    // validate coord
    int yx[2];
    convertCoordInput(startingPos, yx);
    int x = yx[1];
    int y = yx[0];
    if (x == -1 || y == -1) {
        cout << "Invalid coordinate: " << startingPos << ".\n";
        return false;
    }

    // get orientation
    infile.ignore(' ');
    string orientation;
    getline( infile, orientation);
    if(infile.eof())
        return false;

    // put the boat on the board using starting coord and orientation
    return placeShip( ship, x, y, orientation[0] );



    /*string name;
    getline( infile, name, ',' );
    ship = new WaterVehicle( name );
    infile.ignore(' ');
    if(infile.eof())
        return false;

    string startingPos;
    getline( infile, startingPos, ',' );
    int* coord = convertCoordInput(startingPos);
    if (coord[0] == -1 || coord[1] == -1) {
        //todo
    }
    if(infile.eof())
        return false;

    infile.ignore(' ');
    string orientation;
    getline( infile, orientation);
    if(infile.eof())
        return false;

    placeShip( ship, coord[0], coord[1], orientation[0] );

    return true;*/

}


bool Gameboard::placeShip( WaterVehicle* ship, int x, int y, char orientation ) {
    bool placed;

    cout << "Placing boat " << ship->getName() << " (length " << ship->getLength() << ") starting at ["  << y << "][" << x << "] (orientation '" << orientation  << "').\n";

    // vertical placement
    if(orientation == 'V' || orientation == 'v'){
        cout << "Try south...\n";
        placed = placeShipDown(ship, x, y);
        if(!placed) {
            cout << "Try north...\n";
            placed = placeShipUp(ship, x, y);
        }
    }
        //horizontal placement
    else if (orientation == 'H' || orientation == 'h'){
        cout << "Try east...\n";
        placed = placeShipRight(ship, x, y);
        if(!placed) {
            cout << "Try west...\n";
            placed = placeShipLeft(ship, x, y);
        }
    }
    else{
        cout << "Invalid Direction: " << orientation << ".";
        placed = false;
    }

    return placed;
}


bool Gameboard::placeShipUp(WaterVehicle* boat, int x, int y) {
    if ( y - boat->getLength() < 0 ) {
        cout << "Does not fit on the board.\n";
        return false;
    }
    else {
        for(int i = y; i > y - boat->getLength(); i--) {
            if (shipBoard[i][x] != NULL) {
                cout << "Boat: " << shipBoard[i][x]->getName() << " already exists at [" << x << "][" << i << "]. Cannot place.\n";
                return false;
            }
        }
        for(int i = y; i > y - boat->getLength(); i--) {
            shipBoard[i][x] = boat;
        }
    }

    cout << "placed successfully.\n\n";
    return true;
}


bool Gameboard::placeShipDown(WaterVehicle* ship, int x, int y) {
    if(y + ship->getLength() > 10) {
        cout << "Does not fit on the board.\n";
        return false;
    }
    else {
        for(int i = y; i < y + ship->getLength(); i++) {
            if (shipBoard[i][x] != NULL) {
                cout << "Boat: " << shipBoard[i][x]->getName() << " already exists at [" << x << "][" << i << "]. Cannot place.\n";
                return false;
            }
        }
        for(int i = y; i < y + ship->getLength(); i++) {
            shipBoard[i][x] = ship;
        }
    }

    cout << "placed successfully.\n\n";
    return true;
}


bool Gameboard::placeShipRight(WaterVehicle* ship, int x, int y) {
    if(x + ship->getLength() > 10) {
        cout << "Does not fit on the board.\n";
        return false;
    }
    else{
        for(int i = x; i < x + ship->getLength(); i++){
            if (shipBoard[y][i] != NULL) {
                cout << "Boat: " << shipBoard[y][i]->getName() << " already exists at [" << x << "][" << i << "]. Cannot place.\n";
                return false;
            }
        }
        for(int i = x; i < x+ship->getLength(); i++){
            shipBoard[y][i] = ship;
        }
    }

    cout << "placed successfully.\n\n";
    return true;
}


bool Gameboard::placeShipLeft(WaterVehicle* ship, int x, int y) {
    if(x - ship->getLength() < 0) {
        cout << "Does not fit on the board.\n";
        return false;
    }
    else{
        for(int i = x; i > x - ship->getLength(); i--){
            if (shipBoard[y][i] != NULL) {
                cout << "Boat: " << shipBoard[y][i]->getName() << " already exists at [" << x << "][" << i << "]. Cannot place.\n";
                return false;
            }
        }
        for(int i = x; i > x - ship->getLength(); i--){
            shipBoard[y][i] = ship;
        }
    }

    cout << "placed successfully.\n\n";
    return true;
}



//-----------------------------Coordinates-----------------------------

void Gameboard::convertCoordInput(string coordinate, int* yx){
    if(coordinate.length() == 2) {
        yx[0] = convertYChar(coordinate[0]);
        yx[1] = convertXChar(coordinate[1]) - 1;
    }
    else if (coordinate.length() == 3) {
        yx[0] = convertYChar(coordinate[0]);
        int x1 = convertXChar(coordinate[1]);
        int x2 = convertXChar(coordinate[2]);

        if(x1 == 1 && x2 == 0)
            yx[1]=9;
        else
            yx[1]=-1;
    }
    else {
        yx[0] = -1;
        yx[1] = -1;
    }
}


int Gameboard::convertYChar(char y){
    if(y == 'A' || y == 'a')
        return 0;
    else if(y == 'B' || y == 'b')
        return 1;
    else if(y == 'C' || y == 'c')
        return 2;
    else if(y == 'D' || y == 'd')
        return 3;
    else if(y == 'E' || y == 'e')
        return 4;
    else if(y == 'F' || y == 'f')
        return 5;
    else if(y == 'G' || y == 'g')
        return 6;
    else if(y == 'H' || y == 'h')
        return 7;
    else if(y == 'I' || y == 'i')
        return 8;
    else if(y == 'J' || y == 'j')
        return 9;
    else
        return -1;
}


int Gameboard::convertXChar(char x){
    if(charIsInt(x))
        return x - '0';
    else
        return -1;
}


bool Gameboard::charIsInt(char charInt){
    if(48 <= charInt && charInt <= 57)
        return true;
    else
        return false;
}



//--------------------------------Display--------------------------------

void Gameboard::displayShipBoard() {
    // x headers
    cout << std::setw(46) << std::setfill('*') << "\n";
    cout << "     1   2   3   4   5   6   7   8   9  10\n";

    // loop row
    for ( int y = 0; y < 10; y++ ) {
        // line separation
        cout << "   " << std::setw(42) << std::setfill('-') << "\n";

        // y header
        cout << " ";
        if (y == 0)
            cout << "A";
        else if (y == 1)
            cout << "B";
        else if (y == 2)
            cout << "C";
        else if (y == 3)
            cout << "D";
        else if (y == 4)
            cout << "E";
        else if (y == 5)
            cout << "F";
        else if (y == 6)
            cout << "G";
        else if (y == 7)
            cout << "H";
        else if (y == 8)
            cout << "I";
        else if (y == 9)
            cout << "J";
        cout << " ";

        // loop column
        for ( int x = 0; x < 10; x++ ) {
            // positional display
            if ( shipBoard[y][x] == NULL )
                cout << "|   ";
            else
                cout << "| # ";
        }

        // end row
        cout << "|\n";
    }
    cout << "   " << std::setw(42) << std::setfill('-') << "\n";
    //cout << std::setw(46) << std::setfill('*') << "\n";
}

void Gameboard::displayShotBoard() {
    // x headers
    cout << std::setw(46) << std::setfill('*') << "\n";
    cout << "     1   2   3   4   5   6   7   8   9  10\n";

    // loop row
    for ( int y = 0; y < 10; y++ ) {
        // line separation
        cout << "   " << std::setw(42) << std::setfill('-') << "\n";

        // y header
        cout << " ";
        if (y == 0)
            cout << "A";
        else if (y == 1)
            cout << "B";
        else if (y == 2)
            cout << "C";
        else if (y == 3)
            cout << "D";
        else if (y == 4)
            cout << "E";
        else if (y == 5)
            cout << "F";
        else if (y == 6)
            cout << "G";
        else if (y == 7)
            cout << "H";
        else if (y == 8)
            cout << "I";
        else if (y == 9)
            cout << "J";
        cout << " ";

        // loop column
        for ( int x = 0; x < 10; x++ ) {
            // positional display
            cout << "| " << shotBoard[y][x] << " ";
        }

        // end row
        cout << "|\n";
    }
    cout << "   " << std::setw(42) << std::setfill('-') << "\n";
    //cout << std::setw(46) << std::setfill('*') << "\n";
}

void Gameboard::displayShotsOverShips(Gameboard& opponentBoard){
    // x headers
    cout << std::setw(46) << std::setfill('*') << "\n";
    cout << "*   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10 *\n";

    // loop row
    for ( int y = 0; y < 10; y++ ) {
        // line separation
        cout << "*" << std::setw(45) << std::setfill('-') << "*\n";

        // y header
        cout << "* ";
        if (y == 0)
            cout << "A";
        else if (y == 1)
            cout << "B";
        else if (y == 2)
            cout << "C";
        else if (y == 3)
            cout << "D";
        else if (y == 4)
            cout << "E";
        else if (y == 5)
            cout << "F";
        else if (y == 6)
            cout << "G";
        else if (y == 7)
            cout << "H";
        else if (y == 8)
            cout << "I";
        else if (y == 9)
            cout << "J";
        cout << " ";

        // loop column
        for ( int x = 0; x < 10; x++ ) {

            if(opponentBoard.shotBoard[y][x] != " ")
                cout << "| " << opponentBoard.shotBoard[y][x] << " ";
            else if(shipBoard[y][x] == NULL)
                cout << "|   ";
            else
                cout << "| # ";
        }

        // end row
        cout << "*\n";
    }
    cout << std::setw(46) << std::setfill('*') << "\n";
}



//-------------------------------Shooting--------------------------------

bool Gameboard::shoot(const string& coordinate, Gameboard* opponentBoard){
    int yx[2];
    convertCoordInput(coordinate, yx);
    int x = yx[1];
    int y = yx[0];

    if (x == -1 || y == -1){
        cout << "Invalid coordinate: " << coordinate << ".\n\n";
        return false;
    }
    else if(validShot(x, y)){
        if(opponentBoard->shipBoard[y][x] == NULL) {
            shotBoard[y][x] = "O";
            cout << "Missed!\n\n";
        }
        else{
            opponentBoard->shipBoard[y][x]->decrimentHP();
            shotBoard[y][x] = "X";
            cout << "Hit!\n";
            if(opponentBoard->shipBoard[y][x]->isSunk())
                cout << opponentBoard->shipBoard[y][x]->getName() << " sunk!\n";
            cout << endl;
        }

        return true;
    }
    else{
        cout << coordinate << " has already been shot.\n\n";
        return false;
    }
}


bool Gameboard::validShot(int x, int y){
    if(shotBoard[y][x] == " ")
        return true;
    else
        return false;
}


bool Gameboard::allShipsSunk(){
    if(ship1->isSunk() && ship2->isSunk() && ship3->isSunk() && ship4->isSunk() && ship5->isSunk() && ship6->isSunk())
        return true;
    else
        return false;
}
