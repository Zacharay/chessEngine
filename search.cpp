#include "board.h"
#include "search.h"
#include "evaluate.h"
#include "movegen.h"
#include "climits"
#include <iostream>
#include <algorithm>

#define INFINITY 10000000

int SearchPosition(Board *boardObj,int depth){
    int bestMove=0;
    int bestEval=-INFINITY;

    vector<S_MOVE>moves;
    generateAllMoves(boardObj,&moves);
    for(int i=0;i<moves.size();i++)
    {
        boardObj->makeMove(moves[i].move);
        int moveScore = -INFINITY;
        if(boardObj->isMoveLegal())
        {
            moveScore = -negaMax(boardObj,depth-1,-INFINITY,INFINITY);
        }
        boardObj->unmakeMove();
        if(moveScore>bestEval)
        {
            bestEval = moveScore;
            bestMove = moves[i].move;
        }
    }
    return bestMove;
}
bool isRepetition(Board *boardObj)
{
    for(int i=0;i<boardObj->historyPly;i++)
    {
        if(boardObj->posHashKey==boardObj->history[i].posKey)
        {
            return true;
        }
    }
    return false;
}
bool compareScoreDescending(const S_MOVE& a, const S_MOVE& b) {
    return a.score > b.score;
}
int negaMax(Board *boardObj,int depth,int alpha,int beta)
{
    if(isRepetition(boardObj))
    {
        return 0;
    }
    int kingIdx = boardObj->turn==white?whiteKing:blackKing;
    bool isInCheck = boardObj->isSquareAttacked(boardObj->pieceList[kingIdx][1],boardObj->turn^1);

    if(depth==0)
    {
        return evaluatePosition(boardObj);
    }

    vector<S_MOVE>moves;
    generateAllMoves(boardObj,&moves);

    std::sort(moves.begin(),moves.end(),compareScoreDescending);
    int legalMoves = 0;
    for(int i=0;i<moves.size();i++)
    {
        boardObj->makeMove(moves[i].move);
        int moveScore = -INFINITY;
        if(boardObj->isMoveLegal())
        {
            legalMoves++;
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
    if(legalMoves==0)
    {
        if(isInCheck)
        {
            return -(INFINITY + depth);
        }
        else return 0;
    }
    return alpha;
}
