#ifndef ASSIGNMENT3_GRID_H
#define ASSIGNMENT3_GRID_H
#include <iostream>

class grid {
public:
	grid();
	grid(int,int);
	grid(grid&, grid&);
	int getRowSize(); //gets number of rows
	int getColSize(); //gets number of columns
	void initializeGrid(); //initializes a blank grid
	void randomizeShots(); //produces random shots on grid
	bool hasX(grid &, int, int); //compares grids for matching value 'x'
	std::string getPosVal(int, int); //gets value at grid position (row, col)
	void setPointX(int, int); //sets position value to 'x'
	void setPointO(int, int); //sets position value to 'o'
	void printGrid();
	void deletePointer();
private:
	int rows;
	int cols;
	std::string** gridArr;
};

#endif //ASSIGNMENT3_GRID_H

