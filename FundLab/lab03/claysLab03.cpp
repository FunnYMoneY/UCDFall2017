/* Name: Scott Clay
 * Class: CSCI 1410-004
 * Description: This program consucts a game of Rock, Paper, Scissors
 * 		for 2 players. 
 *
 * Lab Partner: Prinn
 * Status: successfully compiled and run on csegrid
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	char player1, player2, replay = 'y';

	//Begin loop
	while(replay == 'y' || replay == 'Y') {
		//Ask user 1 for input
		cout << "Player 1, Rock(R), Paper(P), or Scissors(S)?\n";
		cin >> player1;
		//Ask user 2 for input
		cout << "\nPlayer 2, Rock(R), Paper(P), or Scissors(S)?\n";
		cin >> player2;
 		cout << endl;

		//If user 1 input is R
		if (player1 == 'R' || player1 == 'r') {
			//Begin switch with user 2 input
			switch (player2) {
			//if user 2 input is R then "Tie Game"
			case 'R':
			case 'r':
				cout << "Tie Game!\n";
				break;
			//if user 2 input is P then "Player 2 Wins! Paper covers Rock"
			case 'P':
			case 'p':
				cout << "Player 2 Wins! Paper covers Rock\n";
				break;
			//if user 2 input is S then "Player 1 Wins! Rock breaks Scissors"
			case 'S':
			case 's':
				cout << "Player 1 Wins! Rock breaks Scissors\n";
				break;
			}
		}
		//Or if user 1 input is P
		else if (player1 == 'P' || player1 == 'p') {
			//Begin switch with user 2 input
			switch (player2) {
			//if user 2 input is R then "Player 1 Wins! Paper covers Rock"
			case 'R':
			case 'r':
				cout << "Player 1 Wins! Paper covers Rock\n";
				break;
			//if user 2 input is P then "Tie Game"
			case 'P':
			case 'p':
				cout << "Tie Game!\n";
				break;
			//if user 2 input is S then "Player 2 Wins! Scissors cut Paper"
			case 'S':
			case 's':
				cout << "Player 2 Wins! Scissors cut Paper\n";
				break;
			}
		}
		//Otherwise
		else {
			//Begin switch with user 2 input
			switch (player2) {
			//if user 2 input is R then "Player 2 Wins! Rock breaks Scissors"
			case 'R':
			case 'r':
				cout << "Player 2 Wins! Rock breaks Scissors\n";
				break;
			
			//if user 2 input is P then "Player 1 Wins! Scissors cut Paper"
			case 'P':
			case 'p':
				cout << "Player 1 Wins! Scissors cut Paper\n";
				break;
			
			//if user 2 input is S then "Tie Game"
			case 'S':
			case 's':
				cout << "Tie Game!\n";
				break;
			}
		}
			

		//Ask users to play again?
		cout << "\nWould you like to play again (y/n) ? ";
		cin >> replay;
		cout << endl;
	//End loop
	}
	return 0
}
