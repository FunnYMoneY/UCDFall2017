/*Name: Scott Clay
Class: CSCI 1411-004
Description: This is a console application that organizes movies. The user can choose to read
			movie data from a file, enter movie data manually, or print a list of the movies 
			in the console.

Lab Partner: Prinn
Status: Succesfully compiled and run in Visual Studio 2017 and csegrid
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct MovieData {
	string title;
	int releaseYear;
	int runTime;
	int rating;
};

//Function Prototypes
void readMovieData(MovieData movieArray[], int &currentSize, const int MAXSIZE);
MovieData newMovieData(ifstream &in);
MovieData newMovieData(istream &in);
bool addMovieData(MovieData movieToAdd, MovieData movieArray[], int &currentSize, const int MAXSIZE);
void listMovieData(ostream &out, MovieData movieArray[], int &currentSize);

//Function Implementations
void readMovieData(MovieData movieArray[], int &currentSize, const int MAXSIZE) {
	ifstream infile;
	infile.open("movies.txt");
	MovieData newMovie;
	while (!infile.eof()) {
		newMovie = newMovieData(infile);
		addMovieData(newMovie, movieArray, currentSize, MAXSIZE);
	}
}

MovieData newMovieData(ifstream &in) {
	MovieData newMovie;
	getline(in, newMovie.title);
	in >> newMovie.releaseYear;
	in >> newMovie.runTime;
	in >> newMovie.rating;
	in.ignore();
	return newMovie;
}

MovieData newMovieData(istream &in) {
	MovieData newMovie;
	cout << "Title: ";
	in.ignore();
	getline(in, newMovie.title);
	cout << "\nRelease Year: ";
	in >> newMovie.releaseYear;
	cout << "\nRunning Time (mins): ";
	in >> newMovie.runTime;
	cout << "\nRating (%): ";
	in >> newMovie.rating;
	return newMovie;
}

bool addMovieData(MovieData movieToAdd, MovieData movieArray[], int &currentSize, const int MAXSIZE) {
	if (currentSize < MAXSIZE) {
		movieArray[currentSize] = movieToAdd;
		currentSize++;
		return true; //successful add
	}
	else {
		return false;
	}
}

void listMovieData(ostream &out, MovieData movieArray[], int &currentSize) {
	for (int i = 0; i < currentSize; i++) {
		cout << "Movie " << i + 1 << endl;
		cout << movieArray[i].title << endl;
		cout << movieArray[i].releaseYear << endl;
		cout << movieArray[i].runTime << " mins" << endl;
		cout << movieArray[i].rating << "%" << endl << endl;
	}
}


int main()
{
	const int MAXSIZE = 100;
	int currentSize = 0;

	MovieData newMovie;
	MovieData movieArray[MAXSIZE];

	int menu;
	bool done = false;
	while (!done) {
		cout << "1. Read in Movies\n";
		cout << "2. Add Movies\n";
		cout << "3. List Movies\n";
		cout << "4. Exit\n";
		cin >> menu;
		switch (menu) {
		case 1: readMovieData(movieArray, currentSize, MAXSIZE);
			break;
		case 2: newMovie = newMovieData(cin);
			addMovieData(newMovie, movieArray, currentSize, MAXSIZE);
			break;
		case 3: listMovieData(cout, movieArray, currentSize);
			break;
		case 4: exit(0);
			break;
		default: cout << "Number between 1 and 4\n";
		}//switch
	}//while
}//main
