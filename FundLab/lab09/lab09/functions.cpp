#include "functions.h"
#include <iostream>
using namespace std;

int* allocateArray(int arraySize) {
	int *arrayPtr;
	arrayPtr = new int[arraySize];
	return arrayPtr;
}

int* increaseArray(int* arrayPtr, int& currentSize, int increaseBy) {
	int *newPtr;
	//create new array of larger size
	newPtr = new int[currentSize + increaseBy];
	//copy old contents
	for (int i = 0; i < currentSize; i++)
		newPtr[i] = arrayPtr[i];
	//initialize additional cells to -1
	for (int i = currentSize; i < (currentSize + increaseBy); i++)
		newPtr[i] = -1;
	currentSize += increaseBy;
	delete[] arrayPtr;
	return newPtr;
}

void listArray(int array[], int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}