#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	char go, menu = 'z';
	cout << "What is your full name?\n";
	getline(cin, name);
	cout << "\nWould you like to continue (y or n)?\n";
	cin >> go;
	if (go == 'y' || go == 'Y') {
		cout << "A. Print A\n";
		cout << "B. Print B\n";
		cin >> menu;
		switch (menu) {
		case 'a':
			cout << "A";
			break;
		case 'b':
			cout << "B";
			break;
		default:
			cout << "not A or B";
		}
	}
	else
		cout << "Goodbye";

	return 0;
}
