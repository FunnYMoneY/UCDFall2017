//
// Created by Scott Clay on 10/2/17.
//

#include "Animal.h"
using std::cout;
using std::cin;
using std::endl;

Animal::Animal() {

}

Animal::Animal(string inName, string inColor) {
    name = inName;
    color = inColor;
}

void Animal::setName(string inName) {
    name = inName;
}

void Animal::setColor(string inColor) {
    color = inColor;
}

string Animal::getName() {
    return name;
}

string Animal::getColor() {
    return color;
}

int Animal::getReadStatus() {
    return readStatus;
}

void Animal::readFile() {
    //Overridden function
}

void Animal::print() const {
    //Overridden function
}

string Animal::getType() const{
    return "Animal";
};

void Animal::exceptionHandler1(const string type, int& status) {
    cout << "Error reading file for " << type << endl;
    status++;
}
