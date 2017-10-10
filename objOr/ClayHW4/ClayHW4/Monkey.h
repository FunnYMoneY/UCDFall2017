//
// Created by Scott Clay on 10/2/17.
//

#ifndef CLAYHW4_MONKEY_H
#define CLAYHW4_MONKEY_H

#include "Animal.h"

class Monkey : public Animal {
public:
    Monkey();
    Monkey(string&, string&, int&, bool&, bool&, string&);

    void setAge(int&);
    void setWild(bool&);
    void setEndangered(bool&);
    void setHome(string&);

    int getAge() const;
    bool isWild() const;
    bool isEndangered() const;
    string getHome() const;

    void readFile();
    void print() const;

    void changeEndangered(); //switches endangered

    string getType() const;

private:
    int age;
    bool wild;
    bool endangered;
    string home;

};


#endif //CLAYHW4_MONKEY_H
