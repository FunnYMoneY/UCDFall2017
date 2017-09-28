
#include "Submarine.h"
#include "grid.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Submarine::Submarine () {

}

Submarine::Submarine (int len, int locRow, int locCol, int ori, int depth) {
    setLength(len);
    setStartLoc(locRow-1, locCol-1);
    setOri(ori);
    setDiveDepth(depth);
}

void Submarine::setDiveDepth(int depth) { diveDepth = depth; }

int Submarine::getDiveDepth() const { return diveDepth; }

bool Submarine::isSurfaced() const { return surfaced; }

void Submarine::printAttributes() {
    cout << "Length of ship: " << lengthOfShip << endl;
    cout << "orientation: ";
    if (orientation == 1)
        cout << "horizontal";
    else
        cout << "vertical";
    cout << endl;
    cout << "Starting location: row - " << startingLocRow+1;
    cout << "\n                   column - " << startingLocCol+1;
    cout << "\nDive depth: " << diveDepth << endl;
}

Submarine& Submarine::operator= (const Submarine& sub1) {
    setLength(sub1.getLength());
    setStartLoc(sub1.getLocRow(), sub1.getLocCol());
    setOri(sub1.getOri());
    setDiveDepth(sub1.getDiveDepth());
    return *this;
}