#include "board.h"
#include "search.h"
#include "evaluate.h"
#include "movegen.h"
#include <climits>
#include <iostream>
#include <algorithm>

#define INFINITY 10000000
#define MATE 9000000

void pickNextMove(int moveNum,std::vector<S_MOVE>&moves)
{
    int bestScore = -INFINITY;
    int bestMove = 0;

    for(int i=moveNum;i<moves.size();i++)
    {
        if(moves[i].score>bestScore)
        {
            bestMove = i;
            bestScore = moves[i].score;
        }
    }

    S_MOVE temp = moves[moveNum];
    moves[moveNum] = moves[bestMove];
    moves[bestMove] =temp;

}

int SearchPosition(Board *boardObj,searchInfo *SearchInfo){
    int bestMove=0;
    int bestEval=-INFINITY;

    for(int depth=1;depth<SearchInfo->depth;depth++)
    {
        std::vector<S_MOVE>moves;
        generateAllMoves(boardObj,&moves,false);
        for(int i=0;i<moves.size();i++)
        {
            pickNextMove(i,moves);
            boardObj->makeMove(moves[i].move);
            int moveScore = -INFINITY;
            if(boardObj->isMoveLegal())
            {
                moveScore = -negaMax(boardObj,depth-1,-INFINITY,INFINITY,SearchInfo);
            }
            boardObj->unmakeMove();
            if(SearchInfo->stop==true)
            {
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
    if(SearchInfo->stopTime<=std::chrono::steady_clock::now()&&SearchInfo->timeSet==true)
    {
        SearchInfo->stop= true;
    }
}

int Quiescence(int alpha,int beta,Board *boardObj, searchInfo *SearchInfo)
{
    isTimeForSearchEnded(SearchInfo);
    if(isRepetition(boardObj))
    {
        return 0;
    }
    int Score = evaluatePosition(boardObj);

    if(Score>=beta)
    {
        return beta;
    }
    if(Score>alpha)
    {
        alpha = Score;
    }
    std::vector<S_MOVE>moves;
    generateAllMoves(boardObj,&moves,true);


    int legalMoves = 0;
    Score = -INFINITY;
    for(int i=0;i<moves.size();i++)
    {
        if(SearchInfo->stop==true)
        {
            return 0;
        }

        pickNextMove(i,moves);

        boardObj->makeMove(moves[i].move);
        if(boardObj->isMoveLegal())
        {
            legalMoves++;
            Score = -Quiescence(-beta,-alpha,boardObj,SearchInfo);
        }
        boardObj->unmakeMove();

        if(Score>alpha)
        {
            if(Score>=beta)
            {
                return beta;
            }
            alpha = Score;
        }
    }
    return alpha;
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

    if(isInCheck)
    {
        depth++;
    }

    if(depth==0)
    {
        return Quiescence(alpha,beta,boardObj,SearchInfo);
    }
    int moveScore = -INFINITY;
    int pvMove = 0;
    if(boardObj->transpositionTable.getHashEntry(boardObj->posHashKey,depth,pvMove,moveScore,alpha,beta))
    {
        return moveScore;
    }

    std::vector<S_MOVE>moves;
    generateAllMoves(boardObj,&moves,false);

    if(pvMove!=0)
    {
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i].move==pvMove)
            {

                moves[i].score = 2000000;
            }
        }
    }

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

        pickNextMove(i,moves);

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


                    if(!(getMoveCapture(moves[i].move)))
                    {
                        boardObj->killerMoves[1][boardObj->ply] = boardObj->killerMoves[0][boardObj->ply];
                        boardObj->killerMoves[0][boardObj->ply] = moves[i].move;
                    }

                    return beta;
                }
                if(!(getMoveCapture(moves[i].move)))
                {
                    boardObj->historyHeuristic[boardObj->board[getMoveFrom(moves[i].move)]][getMoveTo(moves[i].move)]+=depth;
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

