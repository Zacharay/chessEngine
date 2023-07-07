#include "board.h"
#include "search.h"
#include "evaluate.h"
#include "movegen.h"
#include "climits"
#include <iostream>
#include <algorithm>

#define INFINITY 10000000
#define MATE 9000000

int SearchPosition(Board *boardObj,searchInfo *SearchInfo){
    int bestMove=0;
    int bestEval=-INFINITY;

    for(int depth=1;depth<40;depth++)
    {
        vector<S_MOVE>moves;
        generateAllMoves(boardObj,&moves);
        for(int i=0;i<moves.size();i++)
        {

            boardObj->makeMove(moves[i].move);
            int moveScore = -INFINITY;
            if(boardObj->isMoveLegal())
            {

                moveScore = -negaMax(boardObj,depth-1,-INFINITY,INFINITY,SearchInfo);
            }
            boardObj->unmakeMove();
            if(SearchInfo->stop==true)
            {
                cout<<depth<<endl;
                return bestMove;
            }

            if(moveScore>bestEval)
            {
                bestEval = moveScore;
                bestMove = moves[i].move;
            }
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
void isTimeForSearchEnded(searchInfo *SearchInfo)
{
    if(SearchInfo->stopTime<=std::chrono::steady_clock::now())
    {
        SearchInfo->stop= true;
    }
}
bool compareScoreDescending(const S_MOVE& a, const S_MOVE& b) {
    return a.score > b.score;
}
int negaMax(Board *boardObj,int depth,int alpha,int beta,searchInfo *SearchInfo)
{
    isTimeForSearchEnded(SearchInfo);
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
    int moveScore = -INFINITY;
    int pvMove = 0;
    if(boardObj->transpositionTable.getHashEntry(boardObj->posHashKey,depth,pvMove,moveScore,alpha,beta))
    {
        return moveScore;
    }

    vector<S_MOVE>moves;
    generateAllMoves(boardObj,&moves);

    if(pvMove!=0)
    {
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i].move==pvMove)
            {

                moves[i].score = 999999;
            }
        }
    }
    std::sort(moves.begin(),moves.end(),compareScoreDescending);

    moveScore = -INFINITY;

    int legalMoves = 0;
    int oldAlpha = alpha;
    int bestScore = -INFINITY;
    int bestMove = 0;
    for(int i=0;i<moves.size();i++)
    {
        if(SearchInfo->stop==true)
        {
            return 0;
        }

        boardObj->makeMove(moves[i].move);

        if(boardObj->isMoveLegal())
        {
            legalMoves++;
            moveScore = -negaMax(boardObj,depth-1,-beta,-alpha,SearchInfo);
        }
        boardObj->unmakeMove();
        if(moveScore> bestScore)
        {
            bestScore = moveScore;
            bestMove = moves[i].move;
            if(moveScore>alpha)
            {
                if(moveScore>=beta)
                {
                    boardObj->transpositionTable.storeHashEntry(boardObj->posHashKey,depth,bestMove,beta,hashFlagBeta);
                    return beta;
                }

                alpha=moveScore;
            }


        }

    }
    if(legalMoves==0)
    {
        if(isInCheck)
        {
            return -(MATE + depth);
        }
        else return 0;
    }
    if(alpha!=oldAlpha)
    {
       boardObj->transpositionTable.storeHashEntry(boardObj->posHashKey,depth,bestMove,bestScore,hashFlagExact);
    }
    else{
        boardObj->transpositionTable.storeHashEntry(boardObj->posHashKey,depth,bestMove,alpha,hashFlagAlpha);
    }
    return alpha;
}
