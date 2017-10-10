//
// Created by Scott Clay on 10/2/17.
//

#include "Lizard.h"
using std::cout;
using std::cin;
using std::endl;

Lizard::Lizard() {
    readStatus = 0;
}

Lizard::Lizard(string& inName, string& inColor, string& inHab, bool& inProt, int& inWeight) {
    name = inName;
    color = inColor;
    habitat = inHab;
    protect = inProt;
    weight = inWeight;
}

void Lizard::setHabitat(string& in) {
    habitat = in;
}

void Lizard::setProtected(bool& in) {
    protect = in;
}

void Lizard::setWeight(double& in) {
    weight = in;
}

string Lizard::getHabitat() const {
    return habitat;
}

bool Lizard::isProtected() const {
    return protect;
}

int Lizard::getWeight() const {
    return weight;
}

void Lizard::readFile() {
    ifstream infile;
    string protectString, weightString;

    try {
        infile.open("Lizard.txt");
        if (!infile.is_open())
            throw 1;

        getline(infile, name, ',');
        infile.ignore();

        getline(infile, color, ',');
        infile.ignore();

        getline(infile, habitat, ',');
        infile.ignore();

        getline(infile, protectString, ',');
        if (protectString == "yes" || protectString == "Yes")
            protect = true;
        else
            protect = false;

        try {
            getline(infile, weightString);
            weight = static_cast<int>(strtol(weightString.c_str(), NULL, 0));
        }
        catch(int& e) {
            exceptionHandlerNumber(getType(), "weight", weight);
        }

        infile.clear();
    }
    catch (int& e) {
        exceptionHandlerReadFile(getType(), readStatus);
    }
}

void Lizard::print() const {
    cout << getType() << endl;
    cout << "Name: " << name << endl;
    cout << "Color: " << color << endl;
    cout << "Habitat: " << habitat << endl;
    cout << "Wild: ";
    if (protect)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << "Weight: " << weight << " lbs" << endl;
    cout << endl;
}

string Lizard::getType() const{
    return "Lizard";
}