//
// Created by Scott Clay on 9/15/17.
//

#ifndef ASSIGNMENT3_SUBMARINE_H
#define ASSIGNMENT3_SUBMARINE_H

#include "WaterVehicle.h"

class Submarine : public WaterVehicle {
public:
    void setDiveDepth(int);

    int getDiveDepth() const;
    bool isSurfaced() const;

    void printAttributes();

    Submarine();
    Submarine(int, int, int, int, int);

    Submarine& operator= (const Submarine&);

private:
    int diveDepth = 0;
    bool surfaced = false;
};


#endif //ASSIGNMENT3_SUBMARINE_H

