//
// Created by Scott Clay on 11/7/17.
//

#include <iostream>
#include <fstream>
#include "Maze.h"
using namespace std;


//Function to print valid passages for the current room
void printDirections( RoomPtr currentRoom ) {
    int count = 0;
    cout << "You can go";
    if ( currentRoom->north != NULL ) {
        cout << " North";
        count++;
    }
    if ( currentRoom->south != NULL ) {
        if (count > 0)
            cout << " or South";
        else
            cout << " South";
        count++;
    }
    if ( currentRoom->east != NULL ) {
        if ( count > 0 )
            cout << " or East";
        else
            cout << " East";
        count++;
    }
    if ( currentRoom->west != NULL ) {
        if ( count > 0 )
            cout << " or West";
        else
            cout << " West";
        count++;
    }
    cout << ".\n";
    if ( count == 1 )
        cout << "It appears to be a dead end...\n";
    else if ( count < 1 )
        cout << "Room Error\n";
}

//Function to move to a room based on user input
void goToRoom( Maze& maze, string& direction ) {
    if ( direction == "n" || direction == "N" ) {
        if ( maze.getCurrentRoom()->north != NULL ) {
            maze.setCurrentRoom( maze.getCurrentRoom()->north );
            system("clear");
        } else {
            system("clear");
            cout << "SMACK! Ouch, You ran straight into a wall!\n";
        }
    }
    else if ( direction == "s" || direction == "S" ) {
        if ( maze.getCurrentRoom()->south != NULL ) {
            maze.setCurrentRoom( maze.getCurrentRoom()->south );
            system("clear");
        } else {
            system("clear");
            cout << "SMACK! Ouch, You ran straight into a wall!\n";
        }
    }
    else if ( direction == "e" || direction == "E" ) {
        if ( maze.getCurrentRoom()->east != NULL ) {
            maze.setCurrentRoom( maze.getCurrentRoom()->east );
            system("clear");
        } else {
            system("clear");
            cout << "SMACK! Ouch, You ran straight into a wall!\n";
        }
    }
    else if ( direction == "w" || direction == "W" ) {
        if ( maze.getCurrentRoom()->west != NULL ) {
            maze.setCurrentRoom( maze.getCurrentRoom()->west );
            system("clear");
        } else {
            system("clear");
            cout << "SMACK! Ouch, You ran straight into a wall!\n";
        }
    }
    else {
        system( "clear" );
        cout << "Please Enter a Valid Direction (n, s, e, w)";
    }
}