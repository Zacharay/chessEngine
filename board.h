#pragma once
#include "defs.h"
#include <string.h>

using namespace std;

class Board{

    public:
    int board[64];
    Board(string fen=DEFAULT_POS);

    void printBoard();

};
