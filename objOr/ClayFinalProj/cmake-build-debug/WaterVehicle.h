//
// Created by Scott Clay on 10/11/17.
//

#ifndef CLAYFINALPROJ_WATERVEHICLE_H
#define CLAYFINALPROJ_WATERVEHICLE_H


class WaterVehicle {
public:
    void setHit();
    void setSunk();

    bool isHit();
    bool isSunk();


private:
    bool hit;
    bool sunk;
};


#endif //CLAYFINALPROJ_WATERVEHICLE_H
