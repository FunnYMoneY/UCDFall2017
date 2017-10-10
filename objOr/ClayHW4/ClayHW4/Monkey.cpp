//
// Created by Scott Clay on 10/2/17.
//

#include "Monkey.h"
using std::cout;
using std::cin;
using std::endl;
using std::stoi;

Monkey::Monkey() = default;

Monkey::Monkey(string& inName, string& inColor, int& inAge, bool& inWild, bool& inEndang, string& inHome) {
    name = inName;
    color = inColor;
    age = inAge;
    wild = inWild;
    endangered = inEndang;
    home = inHome;
}

void Monkey::setAge(int& in) {
    age = in;
}

void Monkey::setWild(bool& in) {
    wild = in;
}

void Monkey::setEndangered(bool& in) {
    endangered = in;
}

void Monkey::setHome(string& in) {
    home = in;
}

int Monkey::getAge() const {
    return age;
}

bool Monkey::isWild() const {
    return wild;
}

bool Monkey::isEndangered() const {
    return endangered;
}

string Monkey::getHome() const {
    return home;
}

void Monkey::readFile() {
    ifstream infile;
    string ageString, wildString, endangString;

    try {
        infile.open("Mnkey.txt");
        if (!infile.is_open())
            throw 1;

        getline(infile, name, ',');
        infile.ignore();

        getline(infile, color, ',');

        getline(infile, ageString, ',');
        age = stoi(ageString);
        infile.ignore();

        getline(infile, wildString, ',');
        if (wildString == "yes" || wildString == "Yes")
            wild = true;
        else
            wild = false;
        infile.ignore();

        getline(infile, home, ',');
        infile.ignore();

        getline(infile, endangString);
        if (endangString == "yes" || endangString == "Yes")
            endangered = true;
        else
            endangered = false;

        infile.clear();
    }
    catch (int e) {
        exceptionHandler1(getType(), readStatus);
    }
}

void Monkey::print() const {
    cout << getType() << endl;
    cout << "Name: " << name << endl;
    cout << "Color: " << color << endl;
    cout << "Age: " << age << endl;
    cout << "Wild: ";
    if (wild)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << "Home: " << home << endl;
    cout << "Endangered: ";
    if (endangered)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << endl;
}

void Monkey::changeEndangered() {
    endangered = !endangered;
}

string Monkey::getType() const{
    return "Monkey";
}