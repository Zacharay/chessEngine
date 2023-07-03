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
    int enPassantSq;

    uint64_t posHashKey;

    int fiftyMove;
    int ply;
    int historyPly;
    S_UNDO history[2047];

    Board(string fen=DEFAULT_POS);
    void parseFen(string fen);

    void makeMove(int move);
    void unmakeMove();

    bool isSquareAttacked(int sq,int bySide) const;
    bool isMoveLegal();
    void printPieceLists();
    void printBoard();
};





