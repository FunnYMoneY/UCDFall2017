
#include "Submarine.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Submarine::Submarine () {

}

Submarine::Submarine (int len, int loc, int ori, int depth) {
    lengthOfShip = len;
    startingLoc = loc;
    orientation = ori;
    diveDepth = depth;
}

void Submarine::setDiveDepth(int depth) { diveDepth = depth; }

int Submarine::getDiveDepth() { return diveDepth; }

bool Submarine::isSurfaced() { return surfaced; }

bool Submarine::isHit(grid gameboard) {

    //TODO
    return false;
}
