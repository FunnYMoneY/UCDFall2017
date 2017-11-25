//
// Created by Tyler Seale on 11/24/17.
//

#include "mainFunctions.h"

using std::cin;

void mainFunctions::displayTurnBoards(gameboard* board){
    cout << "Boats Board\n";
    board->displayBoatBoard();
    cout << "Shot Tracker\n";
    board->displayShotBoard();
    cout << "\n";
}

string mainFunctions::coordinateInput() {
    cout << "Enter Target Coordinates: ";
    string input;
    cin.clear();
    cin >> input;
    return input;
}

void mainFunctions::startTurn() {
    cout << "press any key + enter to start the next turn. ";
    string wait;
    cin >> wait;
    cout << "\n\n";
}