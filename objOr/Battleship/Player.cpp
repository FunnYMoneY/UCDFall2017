//
// Created by Scott Clay on 10/29/17.
//

#include "Player.h"
using std::string;

Player::Player() {
    outOfShips = false;
}

void Player::setOutOfShips( bool status) {
    outOfShips = status;
}

string Player::getName() {
    return name;
}

Gameboard Player::getBoard() {
    return board;
}

bool Player::isOutOfShips() {
    return outOfShips;
}

//void populateBoard() {

//}

//void Player::takeTurn() {

//}

void Player::takeShot() {
    //TODO
}