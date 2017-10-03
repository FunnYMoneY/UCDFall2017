//
// Created by Scott Clay on 10/2/17.
//

#ifndef CLAYHW4_HORSE_H
#define CLAYHW4_HORSE_H

#include "Animal.h"

class Horse : public Animal {
public:
    Horse();
    Horse(string, string, int, int, string);

    void setAge();
    void setHeight();
    void setManeColor();

    int getAge();
    int getHeight();
    string getManeColor();
    void print() const;

private:
    int age;
    int height;
    string maneColor;

};


#endif //CLAYHW4_HORSE_H
