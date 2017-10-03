#include <iostream>
#include "Dog.h"
#include "Fish.h"
#include "Horse.h"
#include "Monkey.h"
#include "Lizard.h"
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    
    try {

    }
    catch(int e) {

    }

    return 0;
}

void readFile(Animal obj, ifstream infile) {
    obj.readFile(infile);
}