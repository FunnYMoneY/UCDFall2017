#include <iostream>
#include "functions.h"
using namespace std;

int main() {
	int *arrayPtr;
	int size = 4, inc = 3;
	arrayPtr = allocateArray(size);
	for (int i = 0; i < size; i++)
		arrayPtr[i] = i;
	listArray(arrayPtr, size);
	arrayPtr = increaseArray(arrayPtr, size, inc);
	listArray(arrayPtr, size);

	return 0;
}