//
// Created by Scott Clay on 10/2/17.
//

#include "Lizard.h"

Lizard::Lizard() {

}

Lizard::Lizard(string inName, string inColor, string inHab, bool inProt, int inWeight) {
    name = inName;
    color = inColor;
    habitat = inHab;
    protect = inProt;
    weight = inWeight;
}

void Lizard::setHabitat() {
    //TODO
}

void Lizard::setProtected() {
    //TODO
}

void Lizard::setWeight() {
    //TODO
}

string Lizard::getHabitat() {
    return habitat;
}

bool Lizard::isProtected() {
    return protect;
}

int Lizard::getWeight() {
    return weight;
}

void Lizard::print() const {
    //TODO
}