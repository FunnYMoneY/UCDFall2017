//
// Created by Scott Clay on 10/2/17.
//

#ifndef CLAYHW4_ANIMAL_H
#define CLAYHW4_ANIMAL_H

#include <iostream>
#include <fstream>
using std::string;
using std::ifstream;


class Animal {
public:
    Animal();
    Animal(string, string);

    void setName(string);
    void setColor(string);
    virtual void readFile(ifstream) const;

    string getName();
    string getColor();
    virtual void print() const;

protected:
    string name;
    string color;

};


#endif //CLAYHW4_ANIMAL_H
