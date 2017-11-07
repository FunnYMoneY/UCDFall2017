#include "BattleshipFunctions.h"


int main() {
    bool done = false;
    int menu;
    string name;
    while ( !done ) {
        done = true;
        mainMenu();
        cin >> menu;
        system( "clear" );
        switch ( menu ) {
            case 1: {
                cout << "Enter your name: ";
                cin >> name;
                try {
                    Human player1(name);
                    //Computer player2(chooseDifficulty());
                    playRound(player1, player1);
                }
                catch ( string e ) {
                    cout << e;
                }
                break;
            }
            case 2: //TODO
            case 3: //TODO
            case 4: { //TODO
                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                cout << "Please enter a number between 1 and 5";
                done = false;
            }
        }
    }
    return 0;
}

