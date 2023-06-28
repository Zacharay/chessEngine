#pragma once

#include <string>
#include <unordered_map>
using namespace std;

#define DEFAULT_POS std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1")


/*
    Move Format
    0000 0000 0000 0000 0111 1111 from              0X7F
    0000 0000 0011 1111 1000 0000 to                0X3F80
    0000 0011 1100 0000 0000 0000 promotedPiece     0X3C000
    0000 0100 0000 0000 0000 0000 enPassant         0X40000
    0000 1000 0000 0000 0000 0000 castle            0X80000
    0001 0000 0000 0000 0000 0000 capture           0X100000
    0010 0000 0000 0000 0000 0000 doublePawn=       0X200000
*/
inline constexpr int setMove(int fromSq,int toSq,int promotedPiece,
int enPassant,int castle,int capture,int dbPawn)
{
    return (fromSq|(toSq<<7)|(promotedPiece<<14)|(enPassant<<18)
    |(castle<<19)|(capture<<20)|(dbPawn<<21));
}
inline constexpr int getMoveFrom(int move){return move&0X7F;}
inline constexpr int getMoveTo(int move){return (move>>7)&0X7F;}
inline constexpr int getMovePromoted(int move){return (move>>14)&0xF;}
inline constexpr int getMoveEnPassant(int move){return (move>>18)&0X1;}
inline constexpr int getMoveCastle(int move){return (move>>19)&0X1;}
inline constexpr int getMoveCapture(int move){return (move>>20)&0X1;}
inline constexpr int getMoveDbPawn(int move){return (move>>21)&0X1;}

enum Piece{
    Empty,whitePawn,whiteKnight,whiteBishop,whiteRook,whiteQueen,whiteKing,
    blackPawn,blackKnight,blackBishop,blackRook,blackQueen,blackKing,Offboard=121};
enum Side{black,white};

static unordered_map<Piece, char> pieceToChar({
{whitePawn, 'P'},{whiteKnight, 'N'},{whiteBishop, 'B'},{whiteRook, 'R'},{whiteQueen, 'Q'},{whiteKing, 'K'},
{blackPawn, 'p'},{blackKnight, 'n'},{blackBishop, 'b'},{blackRook, 'r'},{blackQueen, 'q'},{blackKing, 'k'},
{Empty, ' '}});

static unordered_map<char, Piece> charToPiece({
{'P', whitePawn},{'N', whiteKnight},{'B', whiteBishop},{'R', whiteRook},{'Q', whiteQueen},{'K', whiteKing},
{'p', blackPawn},{'n', blackKnight},{'b', blackBishop},{'r', blackRook},{'q', blackQueen},{'k', blackKing},
{' ', Empty}});

extern int sq120to64[120];
extern int pieceColor[13];
extern int sq64to120[64];
extern int knightOffsets[8];
extern int kingOffsets[8];
extern int bishopOffsets[4];
extern int rookOffsets[4];

inline constexpr int fileRankToSq120(int file,int rnk){return 21+10*rnk+file;};

typedef struct{
    int move;
    int score;
}S_MOVE;


