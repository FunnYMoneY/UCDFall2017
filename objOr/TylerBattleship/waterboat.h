//
// Created by Tyler Seale on 11/24/17.
//

#ifndef BATTLESHIP_WATERBOAT_H
#define BATTLESHIP_WATERBOAT_H

#include <iostream>

using std::string;
using std::cout;

class waterboat {

public:
    // ---------- constructors ----------
    waterboat();
    // takes a name and builds everything else based on that
    waterboat(string);
    // ------------ getters -------------
    string getName(){return name;}
    int getLength(){return length;}
    int getHitPoints(){return hitPoints;}
    bool isSunk(){return sunk;}
    // ------------- other --------------
    // minus hitpoints, sunk = true if hitpoints <= 0
    void decrimentHitPoints();

private:
    string name;
    int length;
    int hitPoints;
    bool sunk;

};


#endif //BATTLESHIP_WATERBOAT_H
