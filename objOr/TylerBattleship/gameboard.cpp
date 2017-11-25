//
// Created by Tyler Seale on 11/24/17.
//

#include <iomanip>
#include <fstream>
#include "gameboard.h"

using std::getline;
using std::endl;

// --------------------------- constructors ----------------------------
gameboard::gameboard() {
    randomizeBoard();
    initializeShotBoard();
}


gameboard::gameboard(string filePath) {
    initializeShotBoard();

    bool boatsPlaced = true;

    //open file
    ifstream file( filePath.c_str() );
    if ( !file.is_open() ) {
        cout << "File Error: " << filePath << " unable to be opened.\n";
        boatsPlaced = false;
    }
    // read file
    if(boatsPlaced)
        boatsPlaced = initializeBoat(boat1, file);
    if(boatsPlaced)
        boatsPlaced = initializeBoat(boat2, file);
    if(boatsPlaced)
        boatsPlaced = initializeBoat(boat3, file);
    if(boatsPlaced)
        boatsPlaced = initializeBoat(boat4, file);
    if(boatsPlaced)
        boatsPlaced = initializeBoat(boat5, file);
    if(boatsPlaced)
        boatsPlaced = initializeBoat(boat6, file);
    // close file
    file.close();

    // if there was a problem, create default board
    if(!boatsPlaced) {
        cout << "Cannot create board from file. Creating random board instead...\n\n";
        nullBoatBoard();
        randomizeBoard();
    }
}



// ------------------------ constructor helpers ------------------------
void gameboard::initializeShotBoard() {
    for (int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++)
            shotBoard[y][x] = " ";
    }
}


void gameboard::nullBoatBoard(){
    for (int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++)
            boatBoard[y][x] = nullptr;
    }
}


void gameboard::randomizeBoard() {
    // create and place each boat
    boat1 = new waterboat("Carrier");
    randomizeBoatPlacement(boat1);
    boat2 = new waterboat("Battleship");
    randomizeBoatPlacement(boat2);
    boat3 = new waterboat("Destroyer");
    randomizeBoatPlacement(boat3);
    boat4 = new waterboat("Submarine");
    randomizeBoatPlacement(boat4);
    boat5 = new waterboat("PT Boat");
    randomizeBoatPlacement(boat5);
    boat6 = new waterboat("Cruiser");
    randomizeBoatPlacement(boat6);
}


void gameboard::randomizeBoatPlacement(waterboat* boat){
    bool boatPlaced = false;

    // while the boat is not placed, keep trying random placements
    while(!boatPlaced) {
        int randX = rand() % 10;
        int randY = rand() % 10;
        char orientation;

        if (rand() % 2 == 0)
            orientation = 'V';
        else
            orientation = 'H';

        boatPlaced = placeBoat(boat, randX, randY, orientation);
    }
}


bool gameboard::initializeBoat( waterboat* boat, ifstream& file ) {
    // get boat name
    string name;
    getline( file, name, ',' );
    if(file.eof())
        return false;

    // initialize boat
    boat = new waterboat(name);

    // get starting coord
    file.ignore(' ');
    string startingPos;
    getline( file, startingPos, ',' );
    if(file.eof())
        return false;

    // validate coord
    int* yx = convertCoordInput(startingPos);
    int x = yx[1];
    int y = yx[0];
    if (x == -1 || y == -1) {
        cout << "Invalid coordinate: " << startingPos << ".\n";
        return false;
    }

    // get orientation
    file.ignore(' ');
    string orientation;
    getline( file, orientation);
    if(file.eof())
        return false;

    // put the boat on the board using starting coord and orientation
    return placeBoat( boat, x, y, orientation[0] );
}


bool gameboard::placeBoat(waterboat* boat, int x, int y, char orientation) {
    bool placed;

    cout << "Placing boat " << boat->getName() << " (length " << boat->getLength() << ") starting at ["  << y << "][" << x << "] (orientation '" << orientation  << "').\n";

    // vertical placement
    if(orientation == 'V' || orientation == 'v'){
        cout << "Try south...\n";
        placed = placeBoatSouth(boat, x, y);
        if(!placed) {
            cout << "Try north...\n";
            placed = placeBoatNorth(boat, x, y);
        }
    }
    //horizontal placement
    else if (orientation == 'H' || orientation == 'h'){
        cout << "Try east...\n";
        placed = placeBoatEast(boat, x, y);
        if(!placed) {
            cout << "Try west...\n";
            placed = placeBoatWest(boat, x, y);
        }
    }
    else{
        cout << "Invalid Direction: " << orientation << ".";
        placed = false;
    }

    return placed;
}


bool gameboard::placeBoatNorth(waterboat* boat, int x, int y) {
    if(y - boat->getLength() < 0) {
        cout << "Does not fit on the board.\n";
        return false;
    }
    else{
        for(int i = y; i > y - boat->getLength(); i--){
            if (boatBoard[i][x] != NULL) {
                cout << "Boat: " << boatBoard[i][x]->getName() << " already exists at [" << x << "][" << i << "]. Cannot place.\n";
                return false;
            }
        }
        for(int i = y; i > y - boat->getLength(); i--){
            boatBoard[i][x] = boat;
        }
    }

    cout << "placed successfully.\n\n";
    return true;
}


bool gameboard::placeBoatSouth(waterboat* boat, int x, int y) {
    if(y + boat->getLength() > 10) {
        cout << "Does not fit on the board.\n";
        return false;
    }
    else{
        for(int i = y; i < y + boat->getLength(); i++){
            if (boatBoard[i][x] != NULL) {
                cout << "Boat: " << boatBoard[i][x]->getName() << " already exists at [" << x << "][" << i << "]. Cannot place.\n";
                return false;
            }
        }
        for(int i = y; i < y + boat->getLength(); i++){
            boatBoard[i][x] = boat;
        }
    }

    cout << "placed successfully.\n\n";
    return true;
}


bool gameboard::placeBoatEast(waterboat* boat, int x, int y) {
    if(x + boat->getLength() > 10) {
        cout << "Does not fit on the board.\n";
        return false;
    }
    else{
        for(int i = x; i < x + boat->getLength(); i++){
            if (boatBoard[y][i] != NULL) {
                cout << "Boat: " << boatBoard[y][i]->getName() << " already exists at [" << x << "][" << i << "]. Cannot place.\n";
                return false;
            }
        }
        for(int i = x; i < x+boat->getLength(); i++){
            boatBoard[y][i] = boat;
        }
    }

    cout << "placed successfully.\n\n";
    return true;
}


bool gameboard::placeBoatWest(waterboat* boat, int x, int y) {
    if(x - boat->getLength() < 0) {
        cout << "Does not fit on the board.\n";
        return false;
    }
    else{
        for(int i = x; i > x - boat->getLength(); i--){
            if (boatBoard[y][i] != nullptr) {
                cout << "Boat: " << boatBoard[y][i]->getName() << " already exists at [" << x << "][" << i << "]. Cannot place.\n";
                return false;
            }
        }
        for(int i = x; i > x - boat->getLength(); i--){
            boatBoard[y][i] = boat;
        }
    }

    cout << "placed successfully.\n\n";
    return true;
}



// ---------------------------- coordinate -----------------------------
bool gameboard::shoot(string coordinate){
    int* yx = convertCoordInput(coordinate);
    int x = yx[1];
    int y = yx[0];

    if (x == -1 || y == -1){
        cout << "Invalid coordinate: " << coordinate << ".\n\n";
        return false;
    }
    else if(validShot(x, y)){
        if(boatBoard[y][x] == nullptr)
            shotBoard[y][x] = "O";
        else{
            boatBoard[y][x]->decrimentHitPoints();
            shotBoard[y][x] = "X";
        }

        return true;
    }
    else{
        cout << coordinate << " has already been shot.\n\n";
        return false;
    }
}


bool gameboard::validShot(int x, int y){
    if(shotBoard[y][x] == " ")
        return true;
    else
        return false;
}



// --------------------------- convert input ---------------------------
int* gameboard::convertCoordInput(string coordinate){
    int yx[2];
    if(coordinate.length() == 2){
        yx[0] = convertYChar(coordinate[0]);
        yx[1] = convertXChar(coordinate[1]) - 1;
    }
    else if (coordinate.length() == 3){
        yx[0] = convertYChar(coordinate[0]);
        int x1 = convertXChar(coordinate[1]);
        int x2 = convertXChar(coordinate[2]);

        if(x1 == 1 && x2 == 0)
            yx[1]=9;
        else
            yx[1]=-1;
    }
    else{
        yx[0] = -1;
        yx[1] = -1;
    }

    return yx;
}


int gameboard::convertYChar(char y){
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


int gameboard::convertXChar(char x){
    if(charIsInt(x))
        return x - '0';
    else
        return -1;
}


bool gameboard::charIsInt(char charInt){
    if(48 <= charInt && charInt <= 57)
        return true;
    else
        return false;
}



// ------------------------------ display ------------------------------
void gameboard::displayBoatBoard() {
    for ( int y = 0; y < 10; y++ ) {
        cout << std::setw(42) << std::setfill('-') << "\n";
        cout << "|";
        for ( int x = 0; x < 10; x++ ) {
            if ( boatBoard[y][x] == nullptr )
                cout << "   |";
            else
                cout << " # |";
        }
        cout << endl;
    }
    cout << std::setw(42) << std::setfill('-') << "\n";
}


void gameboard::displayShotBoard(){
    for ( int y = 0; y < 10; y++ ) {
        cout << std::setw(42) << std::setfill('-') << "\n";
        cout << "|";
        for ( int x = 0; x < 10; x++ ) {
            cout << " " << shotBoard[y][x] << " |";
        }
        cout << endl;
    }
    cout << std::setw(42) << std::setfill('-') << "\n";
}