//
// Created by Scott Clay on 10/2/17.
//

#ifndef CLAYHW4_DOG_H
#define CLAYHW4_DOG_H

#include "Animal.h"


class Dog : public Animal {
public:
    Dog();
    Dog(string&, string&, string&, int&, int&);

    void setBreed(string&);
    void setAge(int&);
    void setWeight(int&);


    string getBreed() const;
    int getAge() const;
    int getWeight() const;

    void readFile();
    void print() const;

    void subtract10(); //subtracts 10 from weight

    string getType() const;

private:
    string breed;
    int age;
    int weight;

};


#endif //CLAYHW4_DOG_H
