//
// Created by Scott Clay on 10/2/17.
//

#ifndef CLAYHW4_HORSE_H
#define CLAYHW4_HORSE_H

#include "Animal.h"

class Horse : public Animal {
public:
    Horse();
    Horse(string&, string&, int&, int&, string&);

    void setAge(int&);
    void setHeight(int&);
    void setManeColor(string&);

    int getAge() const;
    int getHeight() const;
    string getManeColor() const;

    void readFile();
    void print() const;

    void add1(); //adds 1 to height

    string getType() const;

private:
    int age;
    int height;
    string maneColor;

};


#endif //CLAYHW4_HORSE_H
