/* Name: Scott Clay
Class: CSCI 1411-004
Description: [fill in description]
Lab Partner:Prinn
Status: successfully compiled and run in VS 15.
*/

#include <iostream>
using namespace std;

//Prototypes
int* allocateArray(int size);
int averageScore(int* arrayPtr, int& size);
void sortArray(int* arrayPtr, int size);

//Implementations
int* allocateArray(int size) {
	int *arrayPtr;
	arrayPtr = new int[size];
	return arrayPtr;
}

int averageScore(int* arrayPtr, int& size) {
	int average = 0;
	for (int i = 0; i < size; i++)
		average += arrayPtr[i];
	average = (average / size);
	return average;
}

void sortArray(int* arrayPtr, int size) {

}

int main() {
	int *arrayPtr;
	int size = 0;
	cout << "Enter hwo many scores you would like to input: ";
	cin >> size;
	arrayPtr = allocateArray(size);
	
	for (int i = 0; i < size; i++) {
		
		bool done = false;
		while (!done) {
			cout << "Enter score " << i + 1 << ": ";
			cin >> arrayPtr[i];
			if (arrayPtr[i] < 0) {
				cout << "Enter a positive score"
			}
		}
	}
	cout << "\nAverage score: ";
	cout << averageScore(arrayPtr, size) << endl << endl;
}