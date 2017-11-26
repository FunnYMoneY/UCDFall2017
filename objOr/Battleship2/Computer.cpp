//
// Created by scott on 11/25/17.
//

#include "Computer.h"
#include <ctime>
#include <cstdlib>
#include <string>

//--------------------------constructors----------------------------

Computer::Computer() {
    name = "Jim";
    difficulty = 1;
    myBoard = new Gameboard();

}

Computer::Computer( int difficulty ) {
    this->difficulty = difficulty;
    if (difficulty == 1)
        name = "Jim";
    else
        name = "Mega Jim";
    myBoard = new Gameboard();
}



//-------------------------------turn------------------------------

bool Computer::takeTurn(Player &opponent) {
    if (difficulty == 1) {
        if (takeRandShot(opponent)) {
            opponent.setShipStatus();
            return true;
        }
        else
            return false;
    }
    else {
        /*
         * if (takeSmartShot(opponent)) {
         *     opponent.setShipStatus();
         *     return true;
         * }
         * else
         *     return false;
         */
    }
}

bool Computer::takeRandShot(Player &opponent) {
    srand(time(NULL));
    int y = rand() % 10;
    int x = rand() % 10;

    std::string coord;
    if (y == 0)
        coord = "A";
    else if (y == 1)
        coord = "B";
    else if (y == 2)
        coord = "C";
    else if (y == 3)
        coord = "D";
    else if (y == 4)
        coord = "E";
    else if (y == 5)
        coord = "F";
    else if (y == 6)
        coord = "G";
    else if (y == 7)
        coord = "H";
    else if (y == 8)
        coord = "I";
    else
        coord = "J";

    coord.append(intToString(x));

    std::cout << "Firing at " << coord << "!\n\n";

    return myBoard->shoot( coord, opponent.getMyBoard() );
}

//bool Computer::takeSmartShot(Player &opponent) {}

std::string Computer::intToString( int x ) {
    std::string str;
    if (x == 0)
        str = "1";
    else if (x == 1)
        str = "2";
    else if (x == 2)
        str = "3";
    else if (x == 3)
        str = "4";
    else if (x == 4)
        str = "5";
    else if (x == 5)
        str = "6";
    else if (x == 6)
        str = "7";
    else if (x == 7)
        str = "8";
    else if (x == 8)
        str = "9";
    else
        str = "10";
     return str;
}