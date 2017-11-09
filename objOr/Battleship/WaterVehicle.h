//
// Created by Scott Clay on 10/29/17.
//

#ifndef FINALPROJBATTLESHIP_WATERVEHICLE_H
#define FINALPROJBATTLESHIP_WATERVEHICLE_H
#include <iostream>


class WaterVehicle {
public:
    WaterVehicle(  );
    explicit WaterVehicle( std::ifstream &positions );

    void readShipFile( std::ifstream &positions  ) throw( std::string ); //reads input stream into object
    void decrementHP(); //decrements number of hit points

    std::string getType();
    int getHitPoints();


private:
    std::string type;
    std::string startingCoord;
    int length;
    std::string orientation;
    int hitPoints;
    bool sunk;
};


#endif //FINALPROJBATTLESHIP_WATERVEHICLE_H
