//
// Created by Scott Clay on 10/2/17.
// Main function for ClayHW4
//

#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Fish.h"
#include "Horse.h"
#include "Monkey.h"
#include "Lizard.h"
using std::cout;
using std::cin;
using std::endl;

//Prototypes
void read(Animal&);
void print(Animal&);

int main() {
    Dog dog1;
    Fish fish1;
    Horse horse1;
    Monkey monkey1;
    Lizard lizard1;

    read(dog1);
    read(fish1);
    read(horse1);
    read(monkey1);
    read(lizard1);

    dog1.subtract10();
    horse1.add1();
    monkey1.changeEndangered();

    //print objects
    print(dog1);
    print(fish1);
    print(horse1);
    print(monkey1);
    print(lizard1);

    return 0;
}

void read(Animal& obj) {
    obj.readFile();
}

void print(Animal& obj) {
    if (obj.getReadStatus() > 0)
        cout << "No data input for "
             << obj.getType() << endl << endl;
    else
        obj.print();
}