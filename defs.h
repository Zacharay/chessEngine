#pragma once
#include <string>
#include <unordered_map>
using namespace std;

#define DEFAULT_POS std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1")

enum Piece{
    whitePawn,whiteKnight,whiteBishop,whiteRook,whiteQueen,whiteKing,
    blackPawn,blackKnight,blackBishop,blackRook,blackQueen,blackKing,
    None};

static unordered_map<Piece, char> pieceToChar({
{whitePawn, 'P'},{whiteKnight, 'N'},{whiteBishop, 'B'},{whiteRook, 'R'},{whiteQueen, 'Q'},{whiteKing, 'K'},
{blackPawn, 'p'},{blackKnight, 'n'},{blackBishop, 'b'},{blackRook, 'r'},{blackQueen, 'q'},{blackKing, 'k'},
{None, ' '}});

static unordered_map<char, Piece> charToPiece({
{'P', whitePawn},{'N', whiteKnight},{'B', whiteBishop},{'R', whiteRook},{'Q', whiteQueen},{'K', whiteKing},
{'p', blackPawn},{'n', blackKnight},{'b', blackBishop},{'r', blackRook},{'q', blackQueen},{'k', blackKing},
{' ', None}});
