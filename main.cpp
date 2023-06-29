#include <iostream>
#include "board.h"
#include "zobrist.h"
#include "polybook.h"
#include "movegen.h"
using namespace std;


int main()
{
    Board board;
    board.printBoard();
    uint64_t hashKey = getHashKey(&board);

    vector<S_MOVE>moves = generateAllMoves(&board);
    int move = moves[0].move;



    int from = getMoveFrom(move);
    int to = getMoveTo(move);
    int enPassant = getMoveEnPassant(move);
    int castle = getMoveCastle(move);
    int dbPawn = getMoveDbPawn(move);
    int capture = getMoveCapture(move);
    int promotedPiece = getMovePromoted(move);

    //cout<<from<<" "<<to<<" "<<capture<<" "<<dbPawn<<" "<<castle<<" "<<enPassant<<" "<<promotedPiece<<endl;
    board.makeMove(move);
    cout<<endl<<endl;
    board.printBoard();
    board.printPieceLists();
    return 0;
}
