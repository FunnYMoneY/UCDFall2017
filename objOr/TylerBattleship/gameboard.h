//
// Created by Tyler Seale on 11/24/17.
//

#ifndef BATTLESHIP_GAMEBOARD_H
#define BATTLESHIP_GAMEBOARD_H

#include "waterboat.h"

using std::ifstream;

class gameboard {

public:
    // ---------- constructors ----------
    gameboard();
    // take a filePath to place boats on the board
    gameboard(string);
    // ------ constructor helpers -------
    void initializeShotBoard();
    void nullBoatBoard();
    // randomize all boat positions
    void randomizeBoard();
    /*
     * randomize starting x/y and direction (V/H)
     * if it cannot be placed, re-randomize until valid placement is found
     */
    void randomizeBoatPlacement(waterboat*);
    /*
     * Construct boat and place on board for a line in a file
     * line structure = "boatName, startingCoord, orientation"
     */
    bool initializeBoat(waterboat*, ifstream&);
    /*
     * takes boat, x and y coords, and 'V' or 'H'
     * place boat starting at x/y and extend vertical or horizontal
     * if placed, return true; else, return false
     */
    bool placeBoat(waterboat*, int, int, char);
    /*
     * takes boat, x and y coords
     * place boat starting at x/y and extend direction
     * if placed, return true; else, return false
     */
    bool placeBoatNorth(waterboat*, int, int);
    bool placeBoatSouth(waterboat*, int, int);
    bool placeBoatEast(waterboat*, int, int);
    bool placeBoatWest(waterboat*, int, int);
    // ---------- coordinate ------------
    bool shoot(string);
    bool validShot(int, int);
    // --------- convert input ----------
    int* convertCoordInput(string);
    int convertYChar(char);
    int convertXChar(char);
    bool charIsInt(char);
    // ------------ display -------------
    void displayBoatBoard();
    void displayShotBoard();
    void displayShotsOverBoats();

private:
    waterboat* boatBoard[10][10];
    string shotBoard[10][10];
    waterboat *boat1, *boat2, *boat3, *boat4, *boat5, *boat6;

};


#endif //BATTLESHIP_GAMEBOARD_H
