#include "Maze.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//Prototypes
void printDirections( RoomPtr );


int main() {

    //open file
    ifstream infile( "Maze.txt" );
    if ( !infile.is_open() ) {
        cout << "File Error\n";
        exit(0);
    }

    Maze maze( infile );

    //loop maze until final room reached
    cout << "You may enter q to quit at any time.\n\n";
    bool done = false;
    string direction;
    while( !done ) {
        //prompt
        cout << "You are in Room " << maze.getCurrentRoom()->name
                                   << " in a maze of twisty little passages! ";
        printDirections( maze.getCurrentRoom() );
        cout << "Which way would you like to go?\n";
        cin >> direction;

        //check quit
        if ( direction == "q" || direction == "Q" )
            exit(0);

        //go to chosen room
        goToRoom( maze, direction );

        //check for final room
        if ( maze.getCurrentRoom() == maze.getFinish() ) {
            cout << "You made it! Room " << maze.getCurrentRoom()->name
                 << " is the final room!\n";
            done = true;
        }

    }

}

