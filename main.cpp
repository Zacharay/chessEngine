#include <iostream>
#include "board.h"
#include "zobrist.h"
#include "polybook.h"
#include "movegen.h"
#include "uci.h"
using namespace std;


int main()
{
    Board board(TEST_1);
    board.printBoard();
    uint64_t hashKey = getHashKey(&board);

    vector<S_MOVE>moves = generateAllMoves(&board);


    for(S_MOVE move_s:moves)
    {
        int move = move_s.move;
        int from = getMoveFrom(move);
        int to = getMoveTo(move);
        int enPassant = getMoveEnPassant(move);
        int castle = getMoveCastle(move);
        int dbPawn = getMoveDbPawn(move);
        int capture = getMoveCapture(move);
        int promotedPiece = getMovePromoted(move);

        //cout<<from<<" "<<to<<" "<<capture<<" "<<dbPawn<<" "<<castle<<" "<<enPassant<<" "<<promotedPiece<<endl;
    }
    //int move = moves[11].move;
    //board.makeMove(move);
    //cout<<endl<<endl;
    //board.printBoard();
    ///board.printPieceLists();
    uciLoop();
    return 0;
}
