//
// Created by Scott Clay on 10/2/17.
//

#include "Monkey.h"

Monkey::Monkey() {

}

Monkey::Monkey(string inName, string inColor, int inAge, bool inWild, bool inEndang, string inHome) {
    name = inName;
    color = inColor;
    age = inAge;
    wild = inWild;
    endangered = inEndang;
    home = inHome;
}

void Monkey::setAge() {
    //TODO
}

void Monkey::setWild() {
    //TODO
}

void Monkey::setEndangered() {
    //TODO
}

void Monkey::setHome() {
    //TODO
}

int Monkey::getAge() {
    return age;
}

bool Monkey::isWild() {
    return wild;
}

bool Monkey::isEndangered() {
    return endangered;
}

string Monkey::getHome() {
    return home;
}

void Monkey::print() const {
    //TODO
}