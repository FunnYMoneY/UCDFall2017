#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main() {
	int numOfRand, maxRand, randNum, total = 0, avg;

	cout << "Enter how many random numbers? ";
	cin >> numOfRand;
	cout << "Enter the maximum number: ";
	cin >> maxRand;
	cout << endl;

	//seed rand
	srand((unsigned)time(NULL));

	for (int i = 0; i < numOfRand; i++) {
		randNum = rand() % (maxRand - 1);
		total += randNum;
		cout << randNum << endl;
	}

	avg = total / numOfRand;
	cout << "Average of numbers is: " << avg << endl;
	
	return 0;
}
