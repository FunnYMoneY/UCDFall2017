//
// Created by Scott Clay on 9/15/17.
//

#ifndef ASSIGNMENT3_WATERVEHICLE_H
#define ASSIGNMENT3_WATERVEHICLE_H


class WaterVehicle {
public:
    void setLength(int);
    void setStartLoc(int);
    void setOri(int);

    int getLength();
    int getLoc();
    int getOri();
    bool isSunk();
    bool isHit();

    WaterVehicle();
    WaterVehicle(int, int, int);

protected:
    int lengthOfShip;
    int startingLoc;
    int orientation;
    bool sunk = false;
};


#endif //ASSIGNMENT3_WATERVEHICLE_H
