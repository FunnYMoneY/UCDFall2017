//
// Created by Scott Clay on 9/15/17.
//

#ifndef ASSIGNMENT3_WATERVEHICLE_H
#define ASSIGNMENT3_WATERVEHICLE_H
#include "grid.h"

class WaterVehicle {
public:
    void setLength(int);
    void setStartLoc(int, int);
    void setOri(int);

    int getLength() const;
    int getLocRow() const;
    int getLocCol() const;
    int getOri() const;
    void hits(grid&, grid&);
    bool isHit() const;
    bool isSunk() const;

    grid placeVehicle();

    void printAttributes();

    WaterVehicle();
    WaterVehicle(int, int, int, int);

protected:
    int lengthOfShip;
    int startingLocRow;
    int startingLocCol;
    int orientation;
    bool hit = false;
    bool sunk = false;
};


#endif //ASSIGNMENT3_WATERVEHICLE_H
