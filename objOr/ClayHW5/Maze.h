//
// Created by Scott Clay on 11/7/17.
//

#ifndef ASSIGNMENT5_MAZE_H
#define ASSIGNMENT5_MAZE_H
#include <fstream>
#include "Room.h"

typedef Room* RoomPtr;


class Maze {
public:
    //constructors
    Maze();
    Maze( std::ifstream& infile );
    //setters
    void setCurrentRoom( RoomPtr nextRoom ) { currentRoom = nextRoom; }
    //getters
    RoomPtr getHead() { return head; }
    RoomPtr getCurrentRoom() { return currentRoom; }
    RoomPtr getFinish() { return finish; }
    //functions
    void initializeRooms( std::ifstream& );
    void createPassage( std::ifstream&, RoomPtr[] );
    void linkRoom( RoomPtr, RoomPtr, std::string );
    RoomPtr findRoom( RoomPtr[], std::string );

private:
    Room *head, *currentRoom, *finish;
};


#endif //ASSIGNMENT5_MAZE_H
