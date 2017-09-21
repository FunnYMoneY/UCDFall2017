/* Name: Scott Clay
 * Class: CSCI 1411-004
 * Description: This program plays a game of dice, where two players take
 * 		set a goal and take turns rolling 2 dice. After each roll,
 * 		each players' roll is added to their total. The first player
 * 		to get hit the goal or closest while still less than the 
 * 		goal wins.
 *
 * Lab Partner: Prinn
 * Status: successfully compiled and run on csegrid
*/

#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    int replay = 1, goal, winner;
    while (replay == 1)
    {
        cout << "Enter goal to roll to: ";
        cin >> goal;
        winner = playGame(goal);
        if (winner == 1)
            cout << "Player 1 Wins!" << endl;
        else if (winner == 2)
            cout << "Player 2 Wins!" << endl;
        else
            cout << "Tie Game!" << endl;

        cout << "1. Play again\n2. Quit\n";
        cin >> replay;
    }

    return 0;
}
