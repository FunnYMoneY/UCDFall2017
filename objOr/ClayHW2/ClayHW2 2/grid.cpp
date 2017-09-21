#include "grid.h"
#include <iostream>
#include <ctime>

using namespace std;

grid::grid(){

}

grid::grid(int numRows, int numCols){
	rows = numRows;
	cols = numCols;
	grid::initializeGrid();
	grid::randomizeGrid();
}

grid::grid(grid& grid1, grid& grid2){

	rows = grid1.getRowSize();
	cols = grid1.getColSize();

	// set up grid
	initializeGrid();

	// set 1s where grid1 and grid2 are both 1
	intersectGrids(grid1, grid2);
}

int grid::getRowSize() {
	return rows;
}

int grid::getColSize() {
	return cols;
}

void grid::initializeGrid(){
	gridArr = new int*[rows];
        for(int i = 0; i < rows; i++){
                gridArr[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			gridArr[i][j] = 0;
	        }
	}
}

void grid::randomizeGrid() {
	int area = rows * cols;
	int remainingOnes = area / 3;
	while (remainingOnes != 0) {
		for(int i = 0; i < rows; ++i){
     			for(int j = 0; j < cols; j++){
				if (gridArr[i][j] != 1){
					srand((unsigned)time(NULL));
					gridArr[i][j] = rand() % 2;
					if (gridArr[i][j] == 1)
						remainingOnes--;
				}

				if (remainingOnes == 0)
					break;
			}

			if (remainingOnes == 0)
				break;
		}
	}
}

void grid::intersectGrids(grid& grid1, grid& grid2) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid1.getPosVal(i,j) == 1 && grid2.getPosVal(i,j) == 1)
				gridArr[i][j] = 1;
			else
				gridArr[i][j] = 0;
		}
	}
}

int grid::getPosVal(int i, int j) {
	return gridArr[i][j];
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
