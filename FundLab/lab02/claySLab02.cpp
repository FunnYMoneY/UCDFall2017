/* Name: Scott Clay
 * Class: CSC 1411-004
 * Description: This program takes user input employee pay
 * 		information and calculates the employee's
 * 		gross pay and net pay after overtime and taxes.
 *
 * Lab Partner: Prinn
 * Status: Successfully compiled and run on csegrid.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	string firstName, lastName;
	double week1Hrs, week2Hrs;
	double hourlyPay, grossPay, netPay;

	// Ask first and last name
	cout << "Enter employee first and last name: ";
	cin >> firstName >> lastName;
	
	// Ask hourly pay rate
	cout << "Enter hourly pay rate: ";
	cin >> hourlyPay;

	// Ask hours worked in week 1
	cout << "Enter hours worked in week 1: ";
	cin >> week1Hrs;

	// Ask hours worked in week 2
	cout << "Enter hours worked in week 2: ";
	cin >> week2Hrs;

	// Calculate total hours with potential overtime
	// for each week
	if (week1Hrs > 40) {
		week1Hrs = ((week1Hrs - 40) * 1.5) + 40;
	}
	if (week2Hrs > 40) {
		week2Hrs = ((week2Hrs - 40) * 1.5) + 40;
	}

	// Calculate gross pay	
	grossPay = (week1Hrs + week2Hrs) * hourlyPay;
	
	// Calculate net-take-home
	netPay = grossPay * 0.75;

	// print results
	cout << fixed << setprecision(2);
	cout << "Gross Pay: $" << grossPay << endl;
	cout << "Net Pay: $" << netPay << endl;

	return 0;
}

