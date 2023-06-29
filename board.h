#pragma once

#include "defs.h"
#include <string.h>

using namespace std;

class Board{
private:


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
    void printBoard();
    void parseFen(string fen);
    //Making/Unmaking Move
    void clearPiece(const int from,const int piece);
    void addPiece(const int to,const int piece);
    void movePiece(const int from,const int to,int piece);
    void makeMove(int move);
    void unmakeMove(int move);

    //Debuging
    void printPieceLists();
    void clearBoard();

};





