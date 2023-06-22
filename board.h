#pragma once

#include "defs.h"
#include <string.h>

using namespace std;

class Board{

    public:
    uint8_t board[120];
    Board(string fen=DEFAULT_POS);

    void printBoard();

};





