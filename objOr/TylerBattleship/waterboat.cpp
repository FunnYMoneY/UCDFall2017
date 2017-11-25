//
// Created by Tyler Seale on 11/24/17.
//

#include "waterboat.h"


waterboat::waterboat() {
    name = "empty";
    sunk = true;
    length = hitPoints = 0;
}

waterboat::waterboat(string newName) {
    name = newName;
    sunk = false;

    if(newName == "Carrier")
        length = hitPoints = 5;
    else if(newName == "Battleship")
        length = hitPoints = 4;
    else if(newName == "Destroyer")
        length = hitPoints = 3;
    else if(newName == "Submarine")
        length = hitPoints = 3;
    else if(newName == "PT Boat")
        length = hitPoints = 2;
    else if(newName == "Cruiser")
        length = hitPoints = 1;
    else {
        cout << "Unsupported water boat name: " << newName << ".\nDefaulting length to 1\n\n";
        length = hitPoints = 1;
    }
}


void waterboat::decrimentHitPoints() {

    hitPoints--;

    if(hitPoints <= 0)
        sunk = true;
}