#include "grid.h"
#include <iostream>

using namespace std;

int main()
{
	int x, y;

	// get row and col input for grid
	cout << "Enter number of rows: ";
	cin >> x;
	cout << "Enter number of columns: ";
	cin >> y;

	// create grid 1 and 2
	grid grid1(x, y);
	grid grid2(x, y);

	// create grid 3
	grid grid3(grid1, grid2);

	// print grid results
	cout << "\n\n";
        cout << "grid 1:\n";
	grid1.printGrid();
	cout << "\n\n";
	cout << "grid 2:\n";
	grid2.printGrid();
	cout << "\n\n";
        cout << "grid 3:\n";
	grid3.printGrid();

	grid1.deletePointer();
	grid2.deletePointer();
	grid3.deletePointer();

	return 0;
}
