#include <iostream>
using namespace std;

int main()
{
	int const WEEKS = 2, UNION = 10;
	double const TAX = 0.25;
	string lastName, firstName;
	int weekHrs[WEEKS];
	double weekPay[WEEKS];
	double hourlyRate, timePlusHalf, withheld, grossPay, netTake;

	cout << "Enter employee name: ";
	cin >> firstName >> lastName;
	cout << "Enter hourly pay rate: ";
	cin >> hourlyRate;
	for (int i=0; i < WEEKS; i++){
		cout << "Enter hours worked in week "
		     << i + 1 << ": ";
		cin >> weekHrs[i];
	}
	for (int j=0; j < WEEKS; j++){
		if (weekHrs[j] > 40){
			timePlusHalf = (weekHrs[j] - 40) * 1.5;
			weekPay[j] = (40 + timePlusHalf) * hourlyRate;
		} else{
			weekPay[j] = weekHrs[j] * hourlyRate;
		}
	}
	
	for (int k=0; k < WEEKS; k++){
		grossPay += weekPay[k];
	}
	
	withheld = grossPay * TAX;
	netTake = grossPay - withheld;
	
	cout << "Gross Pay: $" << grossPay << endl;
	cout << "Net take home: $" << netTake << endl;
	
	return 0;
}

