//
// Created by Scott Clay on 11/7/17.
//

#include "Maze.h"
#include <iostream>
using namespace std;

typedef Room* RoomPtr;

Maze::Maze() {

}

Maze::Maze( ifstream& infile ) {

    initializeRooms( infile );
    currentRoom = head;

}

//Function to create rooms
void Maze::initializeRooms( std::ifstream& infile ) {

    int numberOfRooms, numberOfPassages;
    infile >> numberOfRooms;
    infile.ignore();
    RoomPtr roomArray[ numberOfRooms ];

    //create rooms based on file number of rooms and names
    for ( int i = 0; i < numberOfRooms; i++ ) {
        roomArray[i] = new Room;
        if ( i == numberOfRooms-1 ) {
            getline(infile, roomArray[i]->name);
            finish = roomArray[i];
        } else
            getline( infile, roomArray[i]->name, ' ' );
        roomArray[i]->north = NULL;
        roomArray[i]->south = NULL;
        roomArray[i]->east = NULL;
        roomArray[i]->west = NULL;
    }
    head = roomArray[0];

    //link rooms based on file
    infile >> numberOfPassages;
    infile.ignore();
    for ( int i = 0; i < numberOfPassages; i++ ) {
        createPassage( infile, roomArray );
    }

}

//Function to link two rooms together
void Maze::createPassage( std::ifstream& infile, RoomPtr roomArray[] ) {

    string room1, room2, direction;
    getline( infile, room1, ' ' );
    getline( infile, room2, ' ' );
    getline( infile, direction );
    linkRoom( findRoom( roomArray, room1 ), findRoom( roomArray, room2 ), direction );

}

//Function to set links based on direction
void Maze::linkRoom( RoomPtr room1, RoomPtr room2, string direction ) {

    if ( direction == "n" ) {
        room1->north = room2;
        room2->south = room1;
    }
    else if ( direction == "s" ) {
        room1->south = room2;
        room2->north = room1;
    }
    else if ( direction == "e" ) {
        room1->east = room2;
        room2->west = room1;
    }
    else if ( direction == "w" ) {
        room1->west = room2;
        room2->east = room1;
    }
    else {
        cout << "File Configuration Error: Invalid Direction for Linking";
        exit(0);
    }

}

//Function to find a room in roomArray by name
RoomPtr Maze::findRoom( RoomPtr roomArray[], string name ) {

    bool found = false;
    int i = 0;
    for ( i = 0; i < 12; i++ ) {
        if ( roomArray[i]->name == name ) {
            found = true;
            break;
        }
    }
    if ( found )
        return roomArray[i];
    else {
        cout << "File Configuration Error: Room Not Found for Linking" << endl;
        exit(0);
    }

}