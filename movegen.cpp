#include "movegen.h"
#include "defs.h"
#include <iostream>


void addCaptureMove(vector<S_MOVE> *moves,int move,Board *boardObj)
{
    S_MOVE s_move;
    s_move.move = move;
    s_move.score = 10;
    moves->push_back(s_move);
}

void addQuietMove(vector<S_MOVE> *moves,int move,Board *boardObj)
{
    S_MOVE s_move;
    s_move.move = move;
    s_move.score = 0;
    moves->push_back(s_move);
}


void addWhitePawnMove(Board *boardObj,vector<S_MOVE> *moves,int from,int to,int isCapture)
{
    int rankFrom = from/10;
    if(isCapture)
    {
        //Promotion Moves
        if(rankFrom==3)
        {
            addCaptureMove(moves,setMove(from,to,whiteKnight,0,0,1,0),boardObj);
            addCaptureMove(moves,setMove(from,to,whiteBishop,0,0,1,0),boardObj);
            addCaptureMove(moves,setMove(from,to,whiteRook,0,0,1,0),boardObj);
            addCaptureMove(moves,setMove(from,to,whiteQueen,0,0,1,0),boardObj);
        }
        else{
            addCaptureMove(moves,setMove(from,to,0,0,0,isCapture,0),boardObj);
        }
    }
    else {
        //Promotion Moves
        if(rankFrom==3)
        {
            addQuietMove(moves,setMove(from,to,whiteKnight,0,0,0,0),boardObj);
            addQuietMove(moves,setMove(from,to,whiteBishop,0,0,0,0),boardObj);
            addQuietMove(moves,setMove(from,to,whiteRook,0,0,0,0),boardObj);
            addQuietMove(moves,setMove(from,to,whiteQueen,0,0,0,0),boardObj);
        }
        else{
            addQuietMove(moves,setMove(from,to,0,0,0,0,0),boardObj);
        }
    }
}
void addBlackPawnMove(Board *boardObj,vector<S_MOVE> *moves,int from,int to,int isCapture){
    int rankFrom = from/10;
    if(isCapture)
    {
        //Promotion Moves
        if(rankFrom==8)
        {
            addCaptureMove(moves,setMove(from,to,blackKnight,0,0,1,0),boardObj);
            addCaptureMove(moves,setMove(from,to,blackBishop,0,0,1,0),boardObj);
            addCaptureMove(moves,setMove(from,to,blackRook,0,0,1,0),boardObj);
            addCaptureMove(moves,setMove(from,to,blackQueen,0,0,1,0),boardObj);
        }
        else{
            addCaptureMove(moves,setMove(from,to,0,0,0,isCapture,0),boardObj);
        }
    }
    else {
        //Promotion Moves
        if(rankFrom==8)
        {
            addQuietMove(moves,setMove(from,to,blackKnight,0,0,0,0),boardObj);
            addQuietMove(moves,setMove(from,to,blackBishop,0,0,0,0),boardObj);
            addQuietMove(moves,setMove(from,to,blackRook,0,0,0,0),boardObj);
            addQuietMove(moves,setMove(from,to,blackQueen,0,0,0,0),boardObj);
        }
        else{
            addQuietMove(moves,setMove(from,to,0,0,0,0,0),boardObj);
        }
    }
}


vector<S_MOVE> generateAllMoves(Board *boardObj)
{
    vector<S_MOVE>moves;

    if(boardObj->turn==white)
    {
        int numOfWhitePawns = boardObj->numOfPieces[whitePawn];
        for(int i=1;i<=numOfWhitePawns;i++)
        {
            int pawnPos = boardObj->pieceList[whitePawn][i];
            //One square move
            if(boardObj->board[pawnPos - 10]==Empty)
            {
                addWhitePawnMove(boardObj,&moves,pawnPos,pawnPos - 10,0);
                //two Square move
                if(boardObj->board[pawnPos - 20]==Empty)
                {
                    addQuietMove(&moves,setMove(pawnPos,pawnPos-20,0,0,0,0,1),boardObj);
                }
            }
        }
    }
    else{
        int numOfBlackPawns = boardObj->numOfPieces[blackPawn];
        for(int i=1;i<=numOfBlackPawns;i++)
        {
            int pawnPos = boardObj->pieceList[blackPawn][i];
            //One square move
            if(boardObj->board[pawnPos + 10]==Empty)
            {
                addBlackPawnMove(boardObj,&moves,pawnPos,pawnPos + 10,0);
                //two Square move
                if(boardObj->board[pawnPos + 20]==Empty)
                {
                    addQuietMove(&moves,setMove(pawnPos,pawnPos+20,0,0,0,0,1),boardObj);
                }
            }
        }
    }

    return moves;
}
