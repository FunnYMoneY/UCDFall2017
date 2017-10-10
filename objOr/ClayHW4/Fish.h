//
// Created by Scott Clay on 10/2/17.
//

#ifndef CLAYHW4_FISH_H
#define CLAYHW4_FISH_H

#include "Animal.h"


class Fish : public Animal {
public:
    Fish();
    Fish(string&, string&, string&, bool&, bool&);

    void setHabitat(string&);
    void setFreshwater(bool&);
    void setPredator(bool&);

    string getHabitat() const;
    bool isFreshwater() const;
    bool isPredator() const;

    void readFile();
    void print() const;

    string getType() const;

private:
    string habitat;
    bool freshwater;
    bool predator;

};


#endif //CLAYHW4_FISH_H
