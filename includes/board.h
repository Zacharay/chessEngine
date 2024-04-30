#pragma once

#include "helpers.h"
#include <string.h>
#include "bitboards.h"
#include "tt.h"

class Board{
private:
    void clearPiece(const int from);
    void addPiece(const int to,const int piece);
    void movePiece(const int from,const int to);
    void clearBoard();
    bool isEnPassantPossible();

public:
    int board[120];

    int numOfPieces[13];
    int pieceList[13][12];

    int turn;
    int castlingRights;
    int enPassantSq;

    uint64_t posHashKey;
    uint64_t bitboards[13];

    int fiftyMove;
    int ply;
    int historyPly;
    S_UNDO history[2047];
    TT transpositionTable;
    int killerMoves[2][2047];
    int historyHeuristic[13][120];

    Board(std::string fen=DEFAULT_POS);
    void parseFen(std::string fen);

    void makeMove(int move);
    void unmakeMove();

    bool isSquareAttacked(int sq,int bySide) const;
    bool isMoveLegal();
    void printPieceLists();
    void printBoard();
};





