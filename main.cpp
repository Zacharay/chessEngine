#include <iostream>
#include "board.h"

using namespace std;

int main()
{
    Board board;
    board.printBoard();
    /*int move = setMove(85,65,12,1,1,1,1);

    int from = getMoveFrom(move);
    int to = getMoveTo(move);
    int promotedPiece = getMovePromoted(move);
    int enPassant = getMoveEnPassant(move);
    int capture = getMoveCapture(move);
    int castle = getMoveCastle(move);
    int dbPawn = getMoveDbPawn(move);
    cout<<move<<endl;
    cout<<from<<endl;
    cout<<to<<endl;
    cout<<promotedPiece<<endl;
    cout<<enPassant<<endl;
    cout<<capture<<endl;
    cout<<castle<<endl;
    cout<<dbPawn<<endl;*/
    return 0;
}
