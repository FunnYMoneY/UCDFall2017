#include "mainFunctions.h"

using namespace mainFunctions;

int main() {
    srand(time(nullptr));

    gameboard* myBoard = new gameboard("/Users/tylerseale/CLionProjects/Battleship/Positions.txt");

    bool keepPlaying = true;
    while(keepPlaying) {
        startTurn();
        displayTurnBoards(myBoard);
        cout << "Enter 'Q' to quit any time.\n";

        bool validTurn = false;
        while (!validTurn) {
            string input = coordinateInput();
            if (input == "Q" || input == "q") {
                cout << "Quitting\n";
                keepPlaying = false;
                validTurn = true;
            } else {
                validTurn = myBoard->shoot(input);
            }
        }

        if(myBoard->allBoatsSunk()){
            keepPlaying = false;
            cout << "All Ships Sunk!\n\n";
        }
    }
    cout << "game ending...\n\n";
    cout << "Shots vs Boats\n";
    myBoard->displayShotsOverBoats();

    return 0;
}