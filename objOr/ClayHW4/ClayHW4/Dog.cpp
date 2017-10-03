//
// Created by Scott Clay on 10/2/17.
//

#include "Dog.h"

Dog::Dog() {

}

Dog::Dog(string inName, string inColor, string inBreed, int inAge, int inWeight) {
    name = inName;
    color = inColor;
    breed = inBreed;
    age = inAge;
    weight = inAge;
}

void Dog::setBreed() {

} //TODO

void Dog::setAge() {

} //TODO

void Dog::setWeight() {

} //TODO

string Dog::getBreed() {
    return breed;
}

int Dog::getAge() {
    return age;
}

int Dog::getWeight() {
    return weight;
}

void Dog::print() const {
    //TODO
}