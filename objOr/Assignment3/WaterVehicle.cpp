//
// Created by Scott Clay on 9/15/17.
//

#include "WaterVehicle.h"
//#include "Grid.h"
#include <iostream>
using std::cout;
using std::endl;


WaterVehicle::WaterVehicle() {

}

WaterVehicle::WaterVehicle(int len, int locRow, int locCol, int ori) {
    lengthOfShip = len;
    startingLocRow = locRow-1;
    startingLocCol = locCol-1;
    orientation = ori;
}

void WaterVehicle::setLength(int len) {
    lengthOfShip = len;
}

void WaterVehicle::setStartLoc(int locRow, int locCol) {
    startingLocRow = locRow;
    startingLocCol = locCol;
}

void WaterVehicle::setOri(int ori) {
    orientation = ori;
}

int WaterVehicle::getLength() const {
    return lengthOfShip;
}

int WaterVehicle::getLocRow() const {
    return startingLocRow;
}

int WaterVehicle::getLocCol() const {
    return startingLocCol;
}

int WaterVehicle::getOri() const {
    return orientation;
}

void WaterVehicle::hits(grid& gameboard, grid& vehiclePos) {
    int shotCount = 0;
    for (int i = 0; i < gameboard.getRowSize(); i++) {
        for (int j = 0; j < gameboard.getColSize(); j++) {

            if (vehiclePos.hasX(gameboard, i, j)) {
                hit = true;
                vehiclePos.setPointO(i, j);
                shotCount++;
            }
        }
        if (shotCount >= lengthOfShip) {
            sunk = true;
            break;
        }
    }
    vehiclePos.printGrid();
    cout << endl;
}

bool WaterVehicle::isHit() const {
    return hit;
}

bool WaterVehicle::isSunk() const {
    return sunk;
}

grid WaterVehicle::placeVehicle() {
    grid board;
    board.initializeGrid();
    if (orientation == 2) {
        for (int i = 0; i < lengthOfShip; i++)
            board.setPointX(startingLocRow + i, startingLocCol);
    }
    else {
        for (int j = 0; j < lengthOfShip; j++)
            board.setPointX(startingLocRow, startingLocCol + j);
    }
    board.printGrid();
    cout << endl;
    return board;
}

void WaterVehicle::printAttributes() {
    cout << "Length of ship: " << lengthOfShip << endl;
    cout << "orientation: ";
    if (orientation == 1)
        cout << "horizontal";
    else
        cout << "vertical";
    cout << endl;
    cout << "Starting location: row - " << startingLocRow+1;
    cout << "\n                   column - " << startingLocCol+1;
}