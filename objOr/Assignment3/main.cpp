#include <iostream>
#include "Submarine.h"
#include "grid.h"


int main() {

    grid gameboard;
    submarine sub1();
    gameboard.randomizeGrid();
    gameboard.printGrid();
    return 0;
}