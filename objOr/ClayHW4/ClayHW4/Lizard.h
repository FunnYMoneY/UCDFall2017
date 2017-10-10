//
// Created by Scott Clay on 10/2/17.
//

#ifndef CLAYHW4_LIZARD_H
#define CLAYHW4_LIZARD_H

#include "Animal.h"


class Lizard : public Animal {
public:
    Lizard();
    Lizard(string&, string&, string&, bool&, int&);

    void setHabitat(string&);
    void setProtected(bool&);
    void setWeight(double&);

    string getHabitat() const;
    bool isProtected() const;
    int getWeight() const;

    void readFile();
    void print() const;

    string getType() const;

private:
    string habitat;
    bool protect;
    double weight;

};


#endif //CLAYHW4_LIZARD_H
