#include "Battleship.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main() {
    bool exit = false;
    int menu = 0;

    while(!exit) {
        cout << "BattleShip! " << endl << endl;
        cout << "1. Play Game\n"
             << "2. Exit\n";
        cin >> menu;
        switch(menu) {
            case 1:
                Battleship game1;
                game1.printBoard();
                break;
            case 2:
                exit = true;
                break;
        }
    }

    return 0;
}