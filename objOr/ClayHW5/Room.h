//
// Created by Scott Clay on 11/8/17.
//

#ifndef ASSIGNMENT5_ROOM_H
#define ASSIGNMENT5_ROOM_H
#include <iostream>

struct Room {
    std::string name;
    Room *north, *south, *east, *west;
};


#endif //ASSIGNMENT5_ROOM_H
