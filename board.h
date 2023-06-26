#pragma once

#include "defs.h"
#include <string.h>

using namespace std;

class Board{
private:

    //others
    int turn;
    int castlingRights;
    int enPassant;

    //Square Centric
    int board[120];

    //Piece Lists
    int numOfPieces[13];
    int pieceList[13][12];

public:

    Board(string fen=DEFAULT_POS);

    void printBoard();
    void parseFen(string fen);
    //Getters
    const int * getBoard()const;

    //Setters
    //Debuging
    void printPieceLists();
};





