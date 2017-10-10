//
// Created by Scott Clay on 10/2/17.
//

#ifndef CLAYHW4_ANIMAL_H
#define CLAYHW4_ANIMAL_H

#include <iostream>
#include <fstream>
#include <cstdlib>
using std::string;
using std::ifstream;


class Animal {
public:
    Animal();
    Animal(string, string);

    void setName(string);
    void setColor(string);

    string getName();
    string getColor();
    int getReadStatus();

    virtual void readFile();
    virtual void print() const;
    virtual string getType() const;

    void exceptionHandlerReadFile(const string&, int &);
    void exceptionHandlerNumber(const string&,const string&, int&);
    void exceptionHandlerNumber(const string&,const string&, double&);

protected:
    string name;
    string color;
    int readStatus;
};


#endif //CLAYHW4_ANIMAL_H
