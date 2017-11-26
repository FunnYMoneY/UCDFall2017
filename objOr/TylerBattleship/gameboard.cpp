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
    int yx[2];
    convertCoordInput(startingPos, yx);
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
    int yx[2];
    convertCoordInput(coordinate, yx);
    int x = yx[1];
    int y = yx[0];

    if (x == -1 || y == -1){
        cout << "Invalid coordinate: " << coordinate << ".\n";
        return false;
    }
    else if(validShot(x, y)){
        cout << "Bombs Away..... ";
        if(boatBoard[y][x] == nullptr) {
            shotBoard[y][x] = "O";
            cout << "Missed!\n\n";
        }
        else{
            shotBoard[y][x] = "X";
            boatBoard[y][x]->decrimentHitPoints();
            cout << "Hit!\n";
            if(boatBoard[y][x]->isSunk())
                cout << boatBoard[y][x]->getName() << " sunk!\n";
            cout << endl;
        }

        return true;
    }
    else{
        cout << "You already shot at " << coordinate << " before.\n\n";
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
void gameboard::convertCoordInput(string coordinate, int yx[]){
    //int yx[2];
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

    //return yx;
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



// ------------------------------- status ------------------------------
bool gameboard::allBoatsSunk(){
    if(boat1->isSunk() && boat2->isSunk() && boat3->isSunk() && boat4->isSunk() && boat5->isSunk() && boat6->isSunk())
        return true;
    else
        return false;
}



// ------------------------------ display ------------------------------
void gameboard::displayBoatBoard() {
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
            // positional display
            if ( boatBoard[y][x] == nullptr )
                cout << "|   ";
            else
                cout << "| $ ";
        }

        // end row
        cout << "*\n";
    }
    cout << std::setw(46) << std::setfill('*') << "\n";
}


void gameboard::displayShotBoard(){
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
            // positional display
            cout << "| " << shotBoard[y][x] << " ";
        }

        // end row
        cout << "*\n";
    }
    cout << std::setw(46) << std::setfill('*') << "\n";
}


void gameboard::displayShotsOverBoats(){
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

            if(shotBoard[y][x] != " ")
                cout << "| " << shotBoard[y][x] << " ";
            else if(boatBoard[y][x] == nullptr)
                cout << "|   ";
            else
                cout << "| $ ";
        }

        // end row
        cout << "*\n";
    }
    cout << std::setw(46) << std::setfill('*') << "\n";
}