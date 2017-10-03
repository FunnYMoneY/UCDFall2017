//
// Created by Scott Clay on 10/2/17.
//

#ifndef CLAYHW4_DOG_H
#define CLAYHW4_DOG_H

#include "Animal.h"


class Dog : public Animal {
public:
    Dog();
    Dog(string, string, string, int, int);

    void setBreed();
    void setAge();
    void setWeight();


    string getBreed();
    int getAge();
    int getWeight();
    void print() const;

private:
    string breed;
    int age;
    int weight;

};


#endif //CLAYHW4_DOG_H
