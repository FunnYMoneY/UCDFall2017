//
// Created by Scott Clay on 10/2/17.
//

#include "Horse.h"
using std::cout;
using std::cin;
using std::endl;
using std::stoi;

Horse::Horse() {
    readStatus = 0;
}

Horse::Horse(string& inName, string& inColor, int& inAge, int& inHeight, string& inMane) {
    name = inName;
    color = inColor;
    age = inAge;
    height = inHeight;
    maneColor = inMane;
}

void Horse::setAge(int& in) {
    age = in;
}

void Horse::setHeight(int& in) {
    height = in;
}

void Horse::setManeColor(string& in) {
    maneColor = in;
}

int Horse::getAge() const {
    return age;
}

int Horse::getHeight() const {
    return height;
}

string Horse::getManeColor() const {
    return maneColor;
}

void Horse::readFile() {
    ifstream infile;
    string ageString, heightString;

    try {
        infile.open("Horse.txt");
        if (!infile.is_open())
            throw 1;

        getline(infile, name, ',');
        infile.ignore();

        getline(infile, color, ',');
        infile.ignore();

        getline(infile, maneColor, ',');

        try {
            getline(infile, ageString, ',');
            age = stoi(ageString);
        }
        catch(std::invalid_argument&) {
            exceptionHandlerNumber(getType(), "age", age);
        }
        try {
            getline(infile, heightString);
            height = stoi(heightString);
        }
        catch (std::invalid_argument&) {
            exceptionHandlerNumber(getType(), "height", height);
        }

        infile.clear();
    }
    catch (int e) {
        exceptionHandlerReadFile(getType(), readStatus);
    }
}

void Horse::print() const {
    cout << getType() << endl;
    cout << "Name: " << name << endl;
    cout << "Color: " << color << endl;
    cout << "Mane Color: " << maneColor << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << " ft" << endl;
    cout << endl;
}

void Horse::add1() {
    height++;
}

string Horse::getType() const {
    return "Horse";
}