//
// Created by Scott Clay on 10/2/17.
//

#ifndef CLAYHW4_FISH_H
#define CLAYHW4_FISH_H

#include "Animal.h"


class Fish : public Animal {
public:
    Fish();
    Fish(string, string, string, bool, bool);

    void setHabitat();
    void setFreshwater();
    void setPredator();

    string getHabitat();
    bool isFreshwater();
    bool isPredator();
    void print() const;

private:
    string habitat;
    bool freshwater;
    bool predator;

};


#endif //CLAYHW4_FISH_H
