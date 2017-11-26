//
// Created by scott on 11/25/17.
//

#ifndef BATTLESHIP2_COMPUTER_H
#define BATTLESHIP2_COMPUTER_H
#include "Player.h"

class Computer : public Player {
public:
    //constructors
    Computer();
    Computer( int ); //takes difficulty

    //constructor helpers


    //turn
    bool takeTurn(Player&);
    bool takeRandShot(Player&); //generates a shot based on random coordinates
    //bool takeSmartShot(Player&); //generates a shot based previous shot status
    std::string intToString( int );
        /* helper for takeRandShot/takeSmartShot: converts random int generated
         * to string for use with gameboard.takeShot function
         */


private:
    int difficulty;

};


#endif //BATTLESHIP2_COMPUTER_H
