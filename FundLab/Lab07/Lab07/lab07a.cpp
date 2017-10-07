/*

#include <iostream>
#include "Car.h"
#include "CarFunctions.h"
using namespace std;

int main()
{
	cout << "Scott Clay\n\n";
	const int MAXSIZE = 2;
	int currentSize = 0;

	Car car1;
	Car carArray[MAXSIZE];
	int menu;
	bool done = false;
	while (!done)
	{
		cout << "1. Add a new car to the array\n";
		cout << "2. List out cars\n";
		cout << "3. exit\n";
		cin >> menu;
		switch (menu) {
		case 1: car1 = newCar(cin);
			addCar(car1, carArray, currentSize, MAXSIZE);
			break;
		case 2: listCars(cout, carArray, currentSize);
			break;
		case 3: exit(0);
			break;
		default: cout << "Number between 1 and 3\n";
		}//switch
	}//while
}//main


*/



//begin main
	//show menu
	//Ask for choice of menu options
		//if menu option 1
				// read movie data from file
		//if menu option 2
				// add movie data manually
		//if menu option 3
				//list movie data
		//if option 4
				//exit program
		//otherwise
				//output error message to input option 1 - 4
		//end if
	//