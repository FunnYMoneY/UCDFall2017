#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Room.h"
using namespace std;

class RoomNode{
public:
    RoomNode(){}
    RoomNode( string& name ) { this->name = name; this->setNorth(NULL);
                                this->setSouth(NULL); this->setEast(NULL);
                                this->setWest(NULL); }
    RoomNode* getNorth() const { return north; }
    RoomNode* getSouth() const { return south; }
    RoomNode* getEast() const { return east; }
    RoomNode* getWest() const { return west; }
    RoomNode* getLink() const { return link; }
    string getName() const { return name; }
    int getNumberOfLinks() {
        int count = 4;
        if ( this->getNorth() == NULL )
            count--;
        if ( this->getSouth() == NULL )
            count--;
        if ( this->getEast() == NULL )
            count--;
        if ( this->getWest() == NULL )
        count --;
        return count;
    }
    void setName( string& name ) { this->name = name; }
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


RoomNodePtr searchName(RoomNodePtr here, string& name) {

    while ( here->getName() != name && here->getLink() != NULL )
        here = here->getLink();
    if ( here->getName() == name )
        return here;
    else
        return NULL;
}

int main() {
    int numberOfRooms, numberOfPassages;
    string name;
    RoomNodePtr head = NULL, here = NULL, nextRoom = NULL, previousRoom = NULL;

    ifstream file( "Maze.txt" );
    if ( !file.is_open() ) {
        cout << "File Error\n";
        exit(0);
    }
    file >> numberOfRooms;
    file.ignore();

    getline(file, name, ' ' );
    head = new RoomNode( name );
    here = head;

    for ( int i = 0; i < numberOfRooms-2; i++ ) {
        previousRoom = here;
        getline( file, name, ' ' );
        here->setLink( new RoomNode( name ) );
        here = here->getLink();
    }
    getline( file, name );
    here->setLink( new RoomNode( name ) );
    here = here->getLink();
    here->setLink( NULL );

    //cout << here->getName() << endl;

    file >> numberOfPassages;
    file.ignore();

    //cout << numberOfPassages;

    string buf, direction;
    RoomNodePtr temp = NULL;

    for ( int i = 0; i < numberOfPassages; i++ ) {
        getline( file, buf, ' ' );

        temp = searchName( head, buf );
        previousRoom = temp;

        if ( temp->getLink() == NULL )
            cout << "File Error\n";
        else {
            getline( file, buf, ' ' );
            getline( file, direction );

            if ( direction == "N" || direction == "n" ) {
                temp->setNorth(searchName(head, buf));
                temp = temp->getNorth();
                temp->setSouth(previousRoom);
            }
            else if ( direction == "S" || direction == "s"  ) {
                temp->setSouth(searchName(head, buf));
                temp = temp->getSouth();
                temp->setNorth(previousRoom);
            }
            else if ( direction == "E" || direction == "e"  ) {
                temp->setEast(searchName(head, buf));
                temp = temp->getEast();
                temp->setWest(previousRoom);
            }
            else if ( direction == "W" || direction == "w"  ) {
                temp->setWest(searchName(head, buf));
                temp = temp->getWest();
                temp->setEast(previousRoom);
            }
            else
                cout << "File error";
        }
        //file.ignore();
    }

    RoomNodePtr room = head;
    char choice;
    if ( room->getLink() == NULL )
        cout << "link error";
    while ( room->getLink() != NULL ) {
        cout << "You are in room " << room->getName() << ". ";
        if ( room->getNumberOfLinks() < 2 ) {
            cout << "Dead End.\n";
        }
        if ( room->getNorth() != NULL ) {
            nextRoom = room->getNorth();
            cout << "Room " << nextRoom->getName() << " is to the North. ";
        }
        if ( room->getSouth() != NULL ) {
            nextRoom = room->getSouth();
            cout << "Room " << nextRoom->getName() << " is to the South. ";
        }
        if ( room->getEast() != NULL ) {
            nextRoom = room->getEast();
            cout << "Room " << nextRoom->getName() << " is to the East. ";
        }
        if ( room->getWest() != NULL ) {
            nextRoom = room->getWest();
            cout << "Room " << nextRoom->getName() << " is to the West. ";
        }

        cout << "\nWhich way would you like to go? ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            if (room->getNorth() != NULL)
                room = room->getNorth();
            else
                cout << "Can't go that way\n";
        }
        else if (choice == 's' || choice == 'S') {
            if (room->getSouth() != NULL)
                room = room->getSouth();
            else
                cout << "Can't go that way\n";
        }
        else if (choice == 'e' || choice == 'E') {
            if (room->getEast() != NULL)
                room = room->getEast();
            else
                cout << "Can't go that way\n";
        }
        else if (choice == 'w' || choice == 'W') {
            if (room->getWest() != NULL)
                room = room->getWest();
            else
                cout << "Can't go that way\n";
        }
        else {
            cout << "Please enter a direction n, s, e, w" << endl << endl;
        }

    }
    cout << "You made it! Room " << room->getName() << " is the final room"
                                                    << "\nYou get treasure.. or something...";

    return 0;
}