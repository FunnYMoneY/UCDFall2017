//
// Created by Scott Clay on 10/2/17.
//

#ifndef CLAYHW4_MONKEY_H
#define CLAYHW4_MONKEY_H

#include "Animal.h"

class Monkey : public Animal {
public:
    Monkey();
    Monkey(string, string, int, bool, bool, string);

    void setAge();
    void setWild();
    void setEndangered();
    void setHome();

    int getAge();
    bool isWild();
    bool isEndangered();
    string getHome();
    void print() const;

private:
    int age;
    bool wild;
    bool endangered;
    string home;

};


#endif //CLAYHW4_MONKEY_H
