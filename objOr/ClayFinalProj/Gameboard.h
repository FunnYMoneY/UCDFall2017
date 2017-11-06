//
// Created by Scott Clay on 10/11/17.
//

#ifndef CLAYFINALPROJ_GAMEBOARD_H
#define CLAYFINALPROJ_GAMEBOARD_H


class Gameboard {
public:
    Gameboard(); //creates blank 10x10 gameboard
    int getRows() const;
    int getCols()const;
    void printBoard() const;

private:
    char** grid;
    static const int ROWS = 10;
    static const int COLS = 10;

};


#endif //CLAYFINALPROJ_GAMEBOARD_H
