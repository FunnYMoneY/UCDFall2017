#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mainFunctions.h"
using std::cout;
using std::string;


int main() {
    srand(time(NULL));

    string filePath = "Positions.txt";

    Human player1("scott", filePath);
    Computer player2;

    bool keepPlaying = true;
    while(keepPlaying) {
        bool validTurn = false;

        //------------------------Player1 turn------------------------
        startTurn();
        while (!validTurn) {
            cout << player1.getName() << "'s turn!\n\n";
            displayTurnBoards(player1, player2);
            string input = coordinateInput();
            cout << "Enter 'Q' to quit any time.\n";
            if (input == "Q" || input == "q") {
                cout << "Quitting\n";
                keepPlaying = false;
                validTurn = true;
            } else {
                validTurn = player1.takeTurn(player2, input);
            }
        }
        if(player2.isOutOfShips()){
            keepPlaying = false;
            cout << "All of " << player2.getName() << "'s Ships are Sunk!\n\n";
        }

        //------------------------Player2 turn------------------------
        if (keepPlaying) {
            startTurn();
            cout << player2.getName() << "'s turn!\n\n";
            validTurn = false;
            while (!validTurn) {
                validTurn = player2.takeTurn(player1);
                }
        }
        if (player1.isOutOfShips()) {
            keepPlaying = false;
            cout << "All of " << player1.getName() << "'s Ships are Sunk!\n\n";
        }
    }

    cout << "game ending...\n\n";
    displayEndOfGameBoards(player1, player2);

    return 0;
}