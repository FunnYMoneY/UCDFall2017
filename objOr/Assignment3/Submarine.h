//
// Created by Scott Clay on 9/15/17.
//

#ifndef ASSIGNMENT3_SUBMARINE_H
#define ASSIGNMENT3_SUBMARINE_H

#include "WaterVehicle.h"

class Submarine : public WaterVehicle {
public:
    void setDiveDepth(int);

    int getDiveDepth();
    bool isSurfaced();
    bool isHit(); //TODO
    bool isSunk(); //TODO

    Submarine();
    Submarine(int, int, int, int);
    ~Submarine();
private:
    int diveDepth;
    bool surfaced = false;
};


#endif //ASSIGNMENT3_SUBMARINE_H

