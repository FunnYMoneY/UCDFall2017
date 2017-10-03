//
// Created by Scott Clay on 10/2/17.
//

#include "Animal.h"

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

