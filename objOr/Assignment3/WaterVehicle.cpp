//
// Created by Scott Clay on 9/15/17.
//

#include "WaterVehicle.h"

WaterVehicle::WaterVehicle() {

}

WaterVehicle::WaterVehicle(int len, int loc, int ori) {
    lengthOfShip = len;
    startingLoc = loc;
    orientation = ori;
}

void WaterVehicle::setLength(int len) {
    lengthOfShip = len;
}

void WaterVehicle::setStartLoc(int loc) {
    startingLoc = loc;
}

void WaterVehicle::setOri(int ori) {
    orientation = ori;
}

int WaterVehicle::getLength() {
    return lengthOfShip;
}

int WaterVehicle::getLoc() {
    return startingLoc;
}

int WaterVehicle::getOri() {
    return orientation;
}

bool inSunk() {
    //TODO
    return false;
}

bool isHit() {
    //TODO
    return false;
}
