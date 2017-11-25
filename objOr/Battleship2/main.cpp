#include <iostream>
#include "Gameboard.h"


int main() {
    Gameboard board;
    board.displayShipBoard();
    std::cout << std::endl;
    board.displayShotBoard();

    std::string coord;
    bool done = false;
    while (!done) {
        std::cin >> coord;
        if ( coord == "999" )
            done = true;
        else
            board.validateShot(coord);

    }
    return 0;
}