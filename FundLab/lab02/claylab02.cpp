#include <iostream>
#include <string>
using namespace std;

int main()
{
	double celcius, fahren;
	int count;
	string firstName, lastName;

	cout << "What is your first name?" << endl;
	cin >> firstName;
	cout << "What is your last name?" << endl;
	cin >> lastName;
	cout << "What is the fahrenheit temperature?\n";
	cin >> fahren;
	celcius = (fahren - 32) * (5.0 / 9.0);
	cout << firstName << " " << lastName
		<< ", the Celcius temperature is "
		<< celcius << endl;

	return 0;
}

