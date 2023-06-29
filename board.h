#pragma once

#include "defs.h"
#include <string.h>

using namespace std;

class Board{
private:
    void clearPiece(const int from);
    void addPiece(const int to,const int piece);
    void movePiece(const int from,const int to);
    void clearBoard();

public:
//Square Centric
    int board[120];

    //Piece Lists
    int numOfPieces[13];
    int pieceList[13][12];

    int turn;
    int castlingRights;
    int enPassant;
    int ply;
    int fiftyMove;

    Board(string fen=DEFAULT_POS);
    void parseFen(string fen);

    void makeMove(int move);
    void unmakeMove(int move);

    bool isSquareAttacked(int sq,int bySide) const;

    void printPieceLists();
    void printBoard();
};





