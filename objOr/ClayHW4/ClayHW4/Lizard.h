//
// Created by Scott Clay on 10/2/17.
//

#ifndef CLAYHW4_LIZARD_H
#define CLAYHW4_LIZARD_H

#include "Animal.h"


class Lizard : public Animal {
public:
    Lizard();
    Lizard(string, string, string, bool, int);

    void setHabitat();
    void setProtected();
    void setWeight();

    string getHabitat();
    bool isProtected();
    int getWeight();
    void print() const;

private:
    string habitat;
    bool protect;
    int weight;

};


#endif //CLAYHW4_LIZARD_H
