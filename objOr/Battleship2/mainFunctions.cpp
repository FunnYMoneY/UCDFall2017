//
// Created by scott on 11/15/17.
//

#include "mainFunctions.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

void displayTurnBoards(Player &player1, Player &player2){
    player1.displayMyBoard(*player2.getMyBoard());
    cout << endl;
}

void displayEndOfGameBoards(Player &player1, Player &player2) {
    cout << player1.getName() << "'s Board\n";
    player1.displayMyShipBoard(*player2.getMyBoard());
    cout << endl;
    cout << player2.getName() << "'s Board\n";
    player2.displayMyShipBoard(*player2.getMyBoard());
    cout << endl;

}

string coordinateInput() {
    cout << "Enter Target Coordinates: ";
    string input;
    cin.clear();
    cin >> input;
    return input;
}

void startTurn() {
    cout << "Press any key + enter to start the next turn. ";
    string wait;
    cin >> wait;
    cout << "\n\n";
}