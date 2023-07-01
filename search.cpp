#include "board.h"
#include "search.h"
#include "evaluate.h"
#include "movegen.h"
#include "climits"
#include <iostream>

int SearchPosition(Board *boardObj,int depth){
    int bestMove=0;
    int bestEval=INT_MIN;
    vector<S_MOVE>moves = generateAllMoves(boardObj);
    for(int i=0;i<moves.size();i++)
    {
        boardObj->makeMove(moves[i].move);
        int moveScore = INT_MIN;
        if(boardObj->isMoveLegal())
        {
            moveScore = -negaMax(boardObj,depth-1,INT_MIN,INT_MAX);
        }
        boardObj->unmakeMove();
        if(moveScore>bestEval)
        {
            std::cout<<"xd";
            bestEval = moveScore;
            bestMove = moves[i].move;
        }
    }
    return bestMove;
}
int negaMax(Board *boardObj,int depth,int alpha,int beta)
{
    if(depth==0)
    {
        int score = evaluatePosition(boardObj);
        cout<<score<<endl;
        return score;
    }

    vector<S_MOVE> moves= generateAllMoves(boardObj);
    for(int i=0;i<moves.size();i++)
    {
        boardObj->makeMove(moves[i].move);
        int moveScore = INT_MIN;
        if(boardObj->isMoveLegal())
        {
            moveScore = -negaMax(boardObj,depth-1,-beta,-alpha);
        }
        boardObj->unmakeMove();
        if(moveScore>=beta)
        {
            return moveScore;
        }
        if(moveScore>alpha)
        {
            alpha=moveScore;
        }
    }
    return alpha;
}
