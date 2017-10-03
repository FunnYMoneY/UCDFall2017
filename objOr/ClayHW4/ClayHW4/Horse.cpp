//
// Created by Scott Clay on 10/2/17.
//

#include "Horse.h"

Horse::Horse() {

}

Horse::Horse(string inName, string inColor, int inAge, int inHeight, string inMane) {
    name = inName;
    color = inColor;
    age = inAge;
    height = inHeight;
    maneColor = inMane;
}

void Horse::setAge() {

}

void Horse::setHeight() {

}

void Horse::setManeColor() {

}

int Horse::getAge() {
    return age;
}

int Horse::getHeight() {
    return height;
}

string Horse::getManeColor() {
    return maneColor;
}

void Horse::print() const {
    //TODO
}