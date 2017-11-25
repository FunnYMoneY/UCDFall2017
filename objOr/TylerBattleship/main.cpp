#include <iostream>

#include "gameboard.h"

int main() {
    srand(time(nullptr));

    gameboard* myBoard = new gameboard("/Users/tylerseale/CLionProjects/Battleship/Positions.txt");

    cout << "Boats Board\n";
    myBoard->displayBoatBoard();

    bool keepPlaying = true;
    while(keepPlaying) {

        cout << "\n\n\nNext Turn!\n\n\n";

        bool validTurn = false;
        while (!validTurn) {

            cout << "Shot Tracker\n";
            myBoard->displayShotBoard();

            cout << "\n\n\nEnter 'Q' to quit any time.\nEnter Coords: ";
            string input;
            std::cin >> input;

            if (input == "Q" || input == "q") {
                keepPlaying = false;
                validTurn = true;
            } else {
                validTurn = myBoard->shoot(input);
            }
        }
    }

    return 0;
}