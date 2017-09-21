//
// Created by Scott on 9/18/2017.
//

#include "functions.h"
#include <iostream>
#include <ctime>
using namespace std;

int rollDice(int sides) {
    srand((unsigned int)time(NULL));
    int roll = rand() % sides + 1;
    return roll;
}

int playGame(int goal) {
    const int NUMBER_OF_DIE = 2;
    int player1 = 0, player2 = 0;
    int sides;
    char roll1, roll2;

    cout << "Enter number of sides per die: ";
    cin >> sides;
    sides *= NUMBER_OF_DIE;
    cout << endl;

    while (player1 < goal && player2 < goal) {
        cout << "Player 1, Roll? (y/n) ";
        cin >> roll1;
        if (roll1 == 'y')
            player1 += rollDice(sides);
        cout << "Player 1's roll total: " << player1 << endl << endl;
        if (player1 > goal)
            return 2;

        cout << "Player 2, Roll? (y/n) ";
        cin >> roll2;
        if (roll2 == 'y')
            player2 += rollDice(sides);
        cout << "Player 2's roll total: " << player2 << endl << endl;
        if (player2 > goal)
            return 1;

        if (roll1 == 'n' && roll2 == 'n')
            if (player1 > player2)
                return 1;
            else if (player2 > player1)
                return 2;
            else
                return 0;
    }
}