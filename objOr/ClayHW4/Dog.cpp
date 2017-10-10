//
// Created by Scott Clay on 10/2/17.
//

#include "Dog.h"
using std::cout;
using std::cin;
using std::endl;
using std::stoi;

Dog::Dog() {
}

Dog::Dog(string& inName, string& inColor, string& inBreed, int& inAge, int& inWeight) {
    name = inName;
    color = inColor;
    breed = inBreed;
    age = inAge;
    weight = inAge;
}

void Dog::setBreed(string& in) {
    breed = in;
}

void Dog::setAge(int& in) {
    age = in;
}

void Dog::setWeight(int& in) {
    weight = in;
}

string Dog::getBreed() const {
    return breed;
}

int Dog::getAge() const {
    return age;
}

int Dog::getWeight() const {
    return weight;
}

void Dog::readFile() {
    ifstream infile;
    string ageString, weightString;

    try {
        infile.open("Dog.txt");
        if (!infile.is_open())
            throw 1;

        getline(infile, name, ',');
        infile.ignore();

        getline(infile, breed, ',');
        try {
            getline(infile, ageString, ',');
            age = stoi(ageString);
        }
        catch(std::invalid_argument&) {
            exceptionHandlerNumber(getType(), "age", age);
        }

        infile.ignore();
        getline(infile, color, ',');

        try {
            getline(infile, weightString);
            weight = stoi(weightString);
        }
        catch (std::invalid_argument&) {
            exceptionHandlerNumber(getType(), "weight", weight);
        }

        infile.clear();
    }
    catch(int e) {
        exceptionHandlerReadFile(getType(), readStatus);
    }
}

void Dog::print() const {
    cout << getType() << endl;
    cout << "Name: " << name << endl;
    cout << "Color: " << color << endl;
    cout << "Breed: " << breed << endl;
    cout << "Age: " << age << endl;
    cout << "Weight: " << weight << " lbs" << endl << endl;
}

void Dog::subtract10() {
    weight -= 10;
}

string Dog::getType() const{
    return "Dog";
}
