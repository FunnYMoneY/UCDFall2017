#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main() {
	int numOfRand, maxRand, randNum, total = 0, avg;

	//Ask how many numbers and the max for random
	cout << "Enter how many random numbers? ";
	cin >> numOfRand;
	cout << "Enter the maximum number: ";
	cin >> maxRand;
	cout << endl;

	//seed rand
	srand((unsigned)time(NULL));

	//loop for number of numbers to generate random number
	for (int i = 0; i < numOfRand; i++) {
		randNum = rand() % (maxRand - 1);
		//add each generated number to total for avg calculation
		total += randNum;
		cout << randNum << endl;
	}

	//calculate average of generated numbers
	avg = total / numOfRand;
	cout << "Average of numbers is: " << avg << endl;
	
	return 0;
}
