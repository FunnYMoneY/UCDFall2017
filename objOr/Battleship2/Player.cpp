//
// Created by scott on 11/15/17.
//

#include "Player.h"
using std::string;

//-----------------------constructors----------------------

Player::Player() {
    name = "Default";
    myBoard = new Gameboard();
    outOfShips = true;
}

Player::~Player() {
    delete(myBoard);
}



//---------------------------turn--------------------------

bool Player::takeTurn() {

}

void Player::displayMyBoard(Gameboard& opponentBoard) {
    std::cout << "My Shots\n";
    myBoard->displayShotBoard();
    std::cout << std::endl;
    std::cout << "My Ships/Opponent Shots\n";
    myBoard->displayShotsOverShips(opponentBoard);
    std::cout << std::endl;
}

void Player::displayMyShipBoard(Gameboard& opponentBoard) {
    std::cout << name << "'s Ship Board\n";
    myBoard->displayShotsOverShips(opponentBoard);
    std::cout << std::endl;
}