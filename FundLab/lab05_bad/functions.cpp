#include "functions.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//function to simulate dice roll, returns result integer
int rollDice(int sides) {
	srand(time(NULL));
	int roll = rand() % sides + 1;
	return roll;
}

//function to play game until winner is decided, returns winner value
int playGame(int goal) {
	int player1 = 0, player2 = 0;
	int sides;

	
	while(player1 <= goal && player2 <= goal) {
		player1 += rollDice(sides);
		cout << "Player 1's roll total: " << player1;

		player2 += rollDice(sides);
		cout << "Player 2's roll total: " << player2;
	}
	if ((goal-player1) <= (goal-player2)) {
		cout << "Player 1 is closer, Player 2 gets the final roll..."
		     << endl;
		player2 += rollDice(sides);
		cout << "Player 2's total is " << player2;
		if (player2 > goal)
			cout << "Player 2 bust.\nPlayer 1 Wins!\n";
		else if (player2 = goal)
			cout << "Player 2 hit goal.\nPlayer 2 Wins!\n";
		else
			cout << "Player 2 is closer to goal.\nPlayer 2 Wins!\n";
	}
	else {
		cout << "Player 2 is closer, Player 1 gets the final roll..."
		     << endl;
		player1 += rollDice(sides);
		cout << "Player 1's total is " << player1;
		if (player1 > goal)
			cout << "Player 1 bust.\nPlayer 2 Wins!\n";
		else if (player1 = goal)
			cout << "Player 1 hit goal.\nPlayer 1 Wins!\n";
		else
			cout << "Player 1 is closer to goal.\nPlayer 1 Wins!\n";
	}
	cout << endl;
}
