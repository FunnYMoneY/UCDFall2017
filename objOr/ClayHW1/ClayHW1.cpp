#include <iostream>
using namespace std;

int main()
{
	int availablePlants = 0, totalSales = 0;
	int temp[7], plantsSold[7];
	
	cout << "Enter number of plants available int store: \n";
	cin >> availablePlants;
	for (int i = 0; i < 7; i++) {
		cout << "Enter average temperature for day "
		     << i+1  << ": \n";
		cin >> temp[i];
	}
	for (int j = 0; j < 7; j++) {
		if(temp[j] < 40){
			plantsSold[j] = availablePlants * 0.10;
		}
		else if (temp[j] >= 40 && temp[j] < 60){
			plantsSold[j] = availablePlants * 0.30;
		}
		else if (temp[j] >= 60 && temp[j] < 70){
			plantsSold[j] = availablePlants * 0.50;
		}
		else if (temp[j] >= 70 && temp[j] < 80){
			plantsSold[j] = availablePlants * 0.60;
		}
		else{
			plantsSold[j] = availablePlants * 0.40;
		}
		availablePlants -= plantsSold[j];
		totalSales += plantsSold[j];
	}
	
	cout << "Estimated total sale is " << totalSales
	     << " plants\n";
	
	return 0;
}
