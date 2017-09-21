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
	int replay = 1, goal;
	while (replay == 1)
	{
		//Ask for goal
		cout << "Enter goal to roll to: ";
		cin >> goal;

		//Play game
		playGame(goal);

		//Ask to play again
		cout << "1. Play again\n2. Quit\n";
		cin >> replay;
	}

	return 0;
}
