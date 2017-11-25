#include "grid.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

grid::grid(){
	rows = 10;
	cols = 10;
	grid::initializeGrid();
}

grid::grid(int numRows, int numCols){
	rows = numRows;
	cols = numCols;
	grid::initializeGrid();
    grid::randomizeShots();
}

grid::grid(grid& grid1, grid& grid2){

	rows = grid1.getRowSize();
	cols = grid1.getColSize();

	// set up grid
	initializeGrid();

	// set 1s where grid1 and grid2 are both 1
	//intersectGrids(grid1, grid2);
}

int grid::getRowSize() {
	return rows;
}

int grid::getColSize() {
	return cols;
}

void grid::initializeGrid(){
	gridArr = new char*[rows];
        for(int i = 0; i < rows; i++){
                gridArr[i] = new char[cols];
		for (int j = 0; j < cols; j++) {
			gridArr[i][j] = ' ';
	        }
	}
}

void grid::randomizeShots() {
	int hit = 0;
    //int area = rows * cols;
	int remainingOnes = 15; //area / 3;
	while (remainingOnes != 0) {
		for(int i = 0; i < rows; ++i){
     			for(int j = 0; j < cols; j++){
				if (gridArr[i][j] != 'x') {
                    srand((unsigned)time(NULL));
                    hit = rand() % 2;
                    if (hit == 1) {
                        gridArr[i][j] = 'x';
                        remainingOnes--;
                    }
				}
                    if (remainingOnes == 0)
					break;
			}

			if (remainingOnes == 0)
				break;
		}
	}
}

bool grid::hasX(grid &grid2, int i, int j) {
    if (gridArr[i][j] == 'x' && grid2.getPosVal(i,j) == 'x')
        return true;
    else
        return false;
}

char grid::getPosVal(int i, int j) {
	return gridArr[i][j];
}

void grid::setPointX(int x, int y) {
    gridArr[x][y] = 'x';
}

void grid::setPointO(int x, int y) {
    gridArr[x][y] = 'o';
}

void grid::printGrid() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "[ " << gridArr[i][j] << " ] ";
		}
		cout << endl;
	}
}

void grid::deletePointer() {
	for (int i = 0; i < rows; i++) {
		delete[] gridArr[i];
	}
	delete gridArr;
}
