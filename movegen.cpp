#include "movegen.h"
#include "defs.h"
#include <iostream>
vector<S_MOVE> generateAllMoves(Board *boardObj)
{
    vector<S_MOVE>moves;

    if(boardObj->turn==white)
    {
        cout<<"test";
        int numOfWhitePawns = boardObj->numOfPieces[whitePawn];
        for(int i=1;i<=numOfWhitePawns;i++)
        {
            cout<<boardObj->pieceList[whitePawn][i]<<endl;
        }
    }
    return moves;
}
