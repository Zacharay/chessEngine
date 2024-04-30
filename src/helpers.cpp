#include "helpers.h"
std::unordered_map<int, char> pieceToChar({
{whitePawn, 'P'},{whiteKnight, 'N'},{whiteBishop, 'B'},{whiteRook, 'R'},{whiteQueen, 'Q'},{whiteKing, 'K'},
{blackPawn, 'p'},{blackKnight, 'n'},{blackBishop, 'b'},{blackRook, 'r'},{blackQueen, 'q'},{blackKing, 'k'},
{Empty, ' '}});

std::unordered_map<char, int> charToPiece({
{'P', whitePawn},{'N', whiteKnight},{'B', whiteBishop},{'R', whiteRook},{'Q', whiteQueen},{'K', whiteKing},
{'p', blackPawn},{'n', blackKnight},{'b', blackBishop},{'r', blackRook},{'q', blackQueen},{'k', blackKing},
{' ', Empty}});

std::unordered_map<std::string,int> sqNameToNumber({
    {"a1",A1},{"b1",B1},{"c1",C1},{"d1",D1},{"e1",E1},{"f1",F1},{"g1",G1},{"h1",H1},
    {"a2",A2},{"b2",B2},{"c2",C2},{"d2",D2},{"e2",E2},{"f2",F2},{"g2",G2},{"h2",H2},
    {"a3",A3},{"b3",B3},{"c3",C3},{"d3",D3},{"e3",E3},{"f3",F3},{"g3",G3},{"h3",H3},
    {"a4",A4},{"b4",B4},{"c4",C4},{"d4",D4},{"e4",E4},{"f4",F4},{"g4",G4},{"h4",H4},
    {"a5",A5},{"b5",B5},{"c5",C5},{"d5",D5},{"e5",E5},{"f5",F5},{"g5",G5},{"h5",H5},
    {"a6",A6},{"b6",B6},{"c6",C6},{"d6",D6},{"e6",E6},{"f6",F6},{"g6",G6},{"h6",H6},
    {"a7",A7},{"b7",B7},{"c7",C7},{"d7",D7},{"e7",E7},{"f7",F7},{"g7",G7},{"h7",H7},
    {"a8",A8},{"b8",B8},{"c8",C8},{"d8",D8},{"e8",E8},{"f8",F8},{"g8",G8},{"h8",H8},
});

std::unordered_map<int, std::string> sqNumberToName({
    {A1, "a1"}, {B1, "b1"}, {C1, "c1"}, {D1, "d1"}, {E1, "e1"}, {F1, "f1"}, {G1, "g1"}, {H1, "h1"},
    {A2, "a2"}, {B2, "b2"}, {C2, "c2"}, {D2, "d2"}, {E2, "e2"}, {F2, "f2"}, {G2, "g2"}, {H2, "h2"},
    {A3, "a3"}, {B3, "b3"}, {C3, "c3"}, {D3, "d3"}, {E3, "e3"}, {F3, "f3"}, {G3, "g3"}, {H3, "h3"},
    {A4, "a4"}, {B4, "b4"}, {C4, "c4"}, {D4, "d4"}, {E4, "e4"}, {F4, "f4"}, {G4, "g4"}, {H4, "h4"},
    {A5, "a5"}, {B5, "b5"}, {C5, "c5"}, {D5, "d5"}, {E5, "e5"}, {F5, "f5"}, {G5, "g5"}, {H5, "h5"},
    {A6, "a6"}, {B6, "b6"}, {C6, "c6"}, {D6, "d6"}, {E6, "e6"}, {F6, "f6"}, {G6, "g6"}, {H6, "h6"},
    {A7, "a7"}, {B7, "b7"}, {C7, "c7"}, {D7, "d7"}, {E7, "e7"}, {F7, "f7"}, {G7, "g7"}, {H7, "h7"},
    {A8, "a8"}, {B8, "b8"}, {C8, "c8"}, {D8, "d8"}, {E8, "e8"}, {F8, "f8"}, {G8, "g8"}, {H8, "h8"}
});

int sq120to64[120] = {
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1,  0,  1,  2,  3,  4,  5,  6,  7, -1,
     -1,  8,  9, 10, 11, 12, 13, 14, 15, -1,
     -1, 16, 17, 18, 19, 20, 21, 22, 23, -1,
     -1, 24, 25, 26, 27, 28, 29, 30, 31, -1,
     -1, 32, 33, 34, 35, 36, 37, 38, 39, -1,
     -1, 40, 41, 42, 43, 44, 45, 46, 47, -1,
     -1, 48, 49, 50, 51, 52, 53, 54, 55, -1,
     -1, 56, 57, 58, 59, 60, 61, 62, 63, -1,
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};
int sq64to120[64] = {
    21, 22, 23, 24, 25, 26, 27, 28,
    31, 32, 33, 34, 35, 36, 37, 38,
    41, 42, 43, 44, 45, 46, 47, 48,
    51, 52, 53, 54, 55, 56, 57, 58,
    61, 62, 63, 64, 65, 66, 67, 68,
    71, 72, 73, 74, 75, 76, 77, 78,
    81, 82, 83, 84, 85, 86, 87, 88,
    91, 92, 93, 94, 95, 96, 97, 98
};
const int castlePerms[120] = {
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 14, 15, 15, 15, 12, 15, 15, 13, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 11, 15, 15, 15,  3, 15, 15, 7, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15
};
const int MirrorSq[64]={
    56, 57, 58, 59, 60, 61, 62, 63,
    48, 49, 50, 51, 52, 53, 54, 55,
    40, 41, 42, 43, 44, 45, 46, 47,
    32, 33, 34, 35, 36, 37, 38, 39,
    24, 25, 26, 27, 28, 29, 30, 31,
    16, 17, 18, 19, 20, 21, 22, 23,
    8 , 9 , 10, 11, 12, 13, 14, 15,
    0 , 1 , 2 , 3 , 4 , 5 , 6 , 7
};
int pieceColor[13]={
    -1,white,white,white,white,white,white,black,black,black,black,black,black
};
const int PieceValue[13]= {
    0,100,320,330,500,900,20000,100,320,330,500,900,20000
};
int knightOffsets[8]={-21,-12,-19,-8,21,12,19,8};
int kingOffsets[8]={-1,1,-10,10,-11,11,-9,9};
int bishopOffsets[4]={-11,11,-9,9};
int rookOffsets[4]={-10,10,-1,1};