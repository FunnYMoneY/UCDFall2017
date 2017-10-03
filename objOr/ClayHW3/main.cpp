#include <iostream>
#include "Submarine.h"
#include "grid.h"
using std::cout;
using std::cin;
using std::endl;


int main() {

    grid gameboard, boatPos;
    int length, row, col, ori, depth;
    cout << "Enter length of ship: ";
    cin >> length;
    cout << "Enter row and column number of desired starting location (i.e. \"2 4\"): ";
    cin >> row >> col;
    cout << "Enter 1 for horizontal or 2 for vertical orientation: ";
    cin >> ori;
    cout << "Enter dive depth: ";
    cin >> depth;
    cout << endl;

    Submarine sub1(length, row, col, ori, depth);
    cout << "x marks the placement of the ship\n";
    boatPos = sub1.placeVehicle();
    std::cout << std::endl;
    // randomize shots and print gameboard
    gameboard.randomizeShots();
    cout << "x marks shots\n";
    gameboard.printGrid();

    cout << endl;
    cout << "o marks hit on boat\n";
    sub1.hits(gameboard, boatPos);

    if (sub1.isHit())
        std::cout << "Boat Hit" << std::endl;
    else
        std::cout << "Boat Missed" << std::endl;
    if (sub1.isSunk())
        std::cout << "Boat SUNK";

    Submarine sub2;
    sub2 = sub1;
    cout << "\nShip 2" << endl;
    sub2.printAttributes();


    gameboard.deletePointer();
    boatPos.deletePointer();

    return 0;
}