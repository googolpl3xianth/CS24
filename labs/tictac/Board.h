#ifndef BOARD_H
#define BOARD_H

#include "Move.h"
#include <iostream>

class Board{
    const int numCol = 3, numRow = 3;
    int turnNum;
    char turn;
    char grid[3][3]; // (col, row)

    public:
        Board();
        char getTurn();
        void printGrid();
        void checkState();
        void addMove(Move newMove);
    private:
        char checkWin();
};

#endif
