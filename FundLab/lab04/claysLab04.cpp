/* Name: Scott Clay
 * Class: CSCI 1411-004
 * Description: Program calculates approximate value of pi using a series
 *
 * Lab Partner: Prinn
 * Status: successfully compiled and run on csegrid
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int numValue;
	bool done = false;
	double pi;
	string choice;

	while(!done)
	{
		//Get number of values
		cout << "Enter number of values: ";
		cin >> numValue;

		//Run sequence for input number of values to get pi/4
		for (int i = 0; i < numValue; i++)
			pi += (pow(-1.0,i)/(2*i+1));

		//Multiply by 4 to get pi
		pi *= 4;

		//output pi
		cout << setprecision(10) << pi << endl;
		
		//Ask to try again
		cout << "Try a new number of values? (y/n)";
		cin >> choice;
		if (choice == "n") 
			done = true;
		pi = 0;
	}
}
