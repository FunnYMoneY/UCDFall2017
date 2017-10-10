//
// Created by Scott Clay on 10/2/17.
//

#include "Fish.h"
using std::cout;
using std::cin;
using std::endl;
using std::stoi;

Fish::Fish() {
    readStatus = 0;
}

Fish::Fish(string& inName, string& inColor, string& inHabitat, bool& inFresh, bool& inPred) {
    name = inName;
    color = inColor;
    habitat = inHabitat;
    freshwater = inFresh;
    predator = inPred;
}

void Fish::setHabitat(string& in) {
    habitat = in;
}

void Fish::setFreshwater(bool& in) {
    freshwater = in;
}

void Fish::setPredator(bool& in) {
    predator = in;
}

string Fish::getHabitat() const {
    return habitat;
}

bool Fish::isFreshwater() const {
    return freshwater;
}

bool Fish::isPredator() const {
    return predator;
}

void Fish::readFile() {
    ifstream infile;
    string freshwaterString, predatorString;

    try {
        infile.open("Fish.txt");
        if (!infile.is_open())
            throw 1;

        getline(infile, name, ',');
        infile.ignore();

        getline(infile, color, ',');
        infile.ignore();

        getline(infile, freshwaterString, ',');
        if (freshwaterString == "yes" || freshwaterString == "Yes")
            freshwater = true;
        else
            freshwater = false;
        infile.ignore();

        getline(infile, habitat, ',');
        infile.ignore();

        getline(infile, predatorString);
        if (predatorString == "yes" || predatorString == "Yes")
            predator = true;
        else
            predator = false;

        infile.clear();
    }
    catch (int e) {
        exceptionHandlerReadFile(getType(), readStatus);
    }
}

void Fish::print() const {
    cout << getType() << endl;
    cout << "Name: " << name << endl;
    cout << "Color: " << color << endl;
    cout << "Freshwater: ";
    if (freshwater)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << "Habitat: " << habitat << endl;
    cout << "Predator: ";
    if (predator)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << endl;
}

string Fish::getType() const{
    return "Fish";
}