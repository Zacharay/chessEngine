#pragma once

#include <string>
#include <unordered_map>
using namespace std;

#define DEFAULT_POS std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1")
#define TEST_1  std::string("r3k2r/ppp3pp/8/8/8/8/PPP3PP/R3K2R b KQkq - 0 1")


/*
    Move Format
    0000 0000 0000 0000 0000 0111 1111 from              0X7F
    0000 0000 0000 0011 1111 1000 0000 to                0X3F80
    0000 0000 0011 1100 0000 0000 0000 promotedPiece     0X3C000
    0000 0000 0100 0000 0000 0000 0000 enPassant         0X40000
    0000 0000 1000 0000 0000 0000 0000 doublePawn=       0X80000
    0000 1111 0000 0000 0000 0000 0000 capturePiece      0XF0000
    1111 0000 0000 0000 0000 0000 0000 castle            0XF00000

*/
inline constexpr int setMove(int fromSq,int toSq,int promotedPiece,
int enPassant,int castle,int capturePiece,int dbPawn)
{
    return (fromSq|(toSq<<7)|(promotedPiece<<14)|(enPassant<<18)
    |(dbPawn<<19)|(capturePiece<<20)|(castle<<24));
}
inline constexpr int getMoveFrom(int move){return move&0X7F;}
inline constexpr int getMoveTo(int move){return (move>>7)&0X7F;}
inline constexpr int getMovePromoted(int move){return (move>>14)&0xF;}
inline constexpr int getMoveEnPassant(int move){return (move>>18)&0X1;}
inline constexpr int getMoveDbPawn(int move){return (move>>19)&0X1;}
inline constexpr int getMoveCapture(int move){return (move>>20)&0XF;}
inline constexpr int getMoveCastle(int move){return (move>>24)&0XF;}



enum Piece{
    Empty,whitePawn,whiteKnight,whiteBishop,whiteRook,whiteQueen,whiteKing,
    blackPawn,blackKnight,blackBishop,blackRook,blackQueen,blackKing,Offboard=121};
enum Side{black,white};
enum CastlePerms{WKCA=8,WQCA=4,BKCA=2,BQCA=1};
enum {
  A1 = 91, B1, C1, D1, E1, F1, G1, H1,
  A2 = 81, B2, C2, D2, E2, F2, G2, H2,
  A3 = 71, B3, C3, D3, E3, F3, G3, H3,
  A4 = 61, B4, C4, D4, E4, F4, G4, H4,
  A5 = 51, B5, C5, D5, E5, F5, G5, H5,
  A6 = 41, B6, C6, D6, E6, F6, G6, H6,
  A7 = 31, B7, C7, D7, E7, F7, G7, H7,
  A8 = 21, B8, C8, D8, E8, F8, G8, H8};

extern unordered_map<Piece, char> pieceToChar;
extern unordered_map<char, Piece> charToPiece;
extern unordered_map<string,int> sqNameToNumber;
extern unordered_map<int,string> sqNumberToName;

extern int sq120to64[120];
extern int sq64to120[64];
extern int pieceColor[13];
extern const int castlePerms[120];
extern int knightOffsets[8];
extern int kingOffsets[8];
extern int bishopOffsets[4];
extern int rookOffsets[4];

inline constexpr int fileRankToSq120(int file,int rnk){return 21+10*rnk+file;};

typedef struct{
    int move;
    int score;
}S_MOVE;
typedef struct{
    int move;
    int castlingRights;
    int enPassant;
    uint64_t posKey;
    int fiftyMove;

}S_UNDO;

