#include <iostream>
#include <fstream>
#include "Room.h"
using namespace std;

class RoomNode{
public:
    RoomNode(){}
    RoomNode( string name ) { this->name = name; }
    RoomNode* getNorth() const { return north; }
    RoomNode* getSouth() const { return south; }
    RoomNode* getEast() const { return east; }
    RoomNode* getWest() const { return west; }
    string getName() const { return name; }
    void setName( string name ) { this->name = name; }
    void setNorth( RoomNode *link ) { north = link; }
    void setSouth( RoomNode *link ) { south = link; }
    void setEast( RoomNode *link ) { east = link; }
    void setWest( RoomNode *link ) { west = link; }
    void setLink( RoomNode *link ) { this->link = link; }

private:
    string name;
    RoomNode *north, *south, *east, *west, *link;

};
typedef RoomNode* RoomNodePtr;


int main() {
    int numberOfRooms, numberOfPassages;
    string buf;
    ifstream file( "Maze.txt" );
    file >> numberOfRooms;
    file.ignore();
    getline(file, buf);
    file >> numberOfPassages;
    file.ignore();

    string name;
    RoomNodePtr room;
    int count = 0;
    for ( int i = 0; i < numberOfRooms; i++ ) {
        //create room with name
        name = buf[ count ];
        room = new RoomNode( name );
        count += 2;

        //set head
        if ( i == 0 )
            RoomNodePtr head = room;
        else
            room->

        for ( int i = 0; i < numberOfPassages; i++ ){
            string buf2;
            getline(file, buf2, ' ');
            if ( buf2 == name ) {

            }
        }
    }



    return 0;
}