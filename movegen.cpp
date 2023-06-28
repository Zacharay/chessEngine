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

    //Pawns
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
                if(boardObj->board[pawnPos - 20]==Empty&&pawnPos/10==8)
                {
                    addQuietMove(&moves,setMove(pawnPos,pawnPos-20,0,0,0,0,1),boardObj);
                }
            }

            if(boardObj-> board[pawnPos - 11]>=blackPawn&&boardObj-> board[pawnPos - 11]<blackKing)
            {
                addWhitePawnMove(boardObj,&moves,pawnPos,pawnPos-11,1);
            }
            if(boardObj-> board[pawnPos -9]>=blackPawn&&boardObj-> board[pawnPos - 9]<blackKing)
            {
                addWhitePawnMove(boardObj,&moves,pawnPos,pawnPos-9,1);
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
                if(boardObj->board[pawnPos + 20]==Empty&&pawnPos/10==3)
                {
                    addQuietMove(&moves,setMove(pawnPos,pawnPos+20,0,0,0,0,1),boardObj);
                }
            }
            //captures
            if(boardObj-> board[pawnPos + 11]>=whitePawn&&boardObj-> board[pawnPos + 11]<whiteKing)
            {
                addBlackPawnMove(boardObj,&moves,pawnPos,pawnPos+ 11,1);
            }
            if(boardObj-> board[pawnPos +9]>=whitePawn&&boardObj-> board[pawnPos + 9]<whiteKing)
            {
                addBlackPawnMove(boardObj,&moves,pawnPos,pawnPos+9,1);
            }
        }
    }

    //Knights
    int knight = boardObj->turn==white?whiteKnight:blackKnight;
    int numOfKnights = boardObj->numOfPieces[knight];
    for(int i=1;i<=numOfKnights;i++)
    {
        int knightPos = boardObj->pieceList[knight][i];
        for(int offset:knightOffsets)
        {
            int newKnightPos = knightPos + offset;

            if(boardObj->board[newKnightPos]==Offboard)continue;

            if(boardObj->board[newKnightPos]==Empty)
            {
                addQuietMove(&moves,setMove(knightPos,newKnightPos,0,0,0,0,0),boardObj);
            }
            else if(pieceColor[boardObj->board[newKnightPos]]!=pieceColor[boardObj->board[knightPos]])
            {
                addCaptureMove(&moves,setMove(knightPos,newKnightPos,0,0,0,1,0),boardObj);
            }
        }
    }

    //King
    int king = boardObj->turn==white?whiteKing:blackKing;
    int kingPos = boardObj->pieceList[king][1];

    for(int offset:kingOffsets)
    {
        int newKingPos = kingPos + offset;
        if(boardObj->board[newKingPos]==Offboard)continue;

        if(boardObj->board[newKingPos]==Empty)
        {
            addQuietMove(&moves,setMove(kingPos,newKingPos,0,0,0,0,0),boardObj);
        }
        else if(pieceColor[boardObj->board[newKingPos]]!=pieceColor[king])
        {
            addCaptureMove(&moves,setMove(kingPos,newKingPos,0,0,0,1,0),boardObj);
        }
    }
    //Bishop
    int bishop = boardObj->turn==white?whiteBishop:blackBishop;
    int numOfBishops = boardObj->numOfPieces[bishop];
    for(int i=1;i<=numOfBishops;i++)
    {
        int bishopPos = boardObj->pieceList[bishop][i];
        for(int offset:bishopOffsets)
        {
            int newBishopPos = bishopPos + offset;
            while(boardObj->board[newBishopPos]!=Offboard)
            {
                if(boardObj->board[newBishopPos]!=Empty)
                {
                    if(pieceColor[boardObj->board[newBishopPos]]!=pieceColor[bishop])
                    {
                        addCaptureMove(&moves,setMove(bishopPos,newBishopPos,0,0,0,1,0),boardObj);
                    }
                    break;
                }
                else if(boardObj->board[newBishopPos]==Empty)
                {
                    addQuietMove(&moves,setMove(bishopPos,newBishopPos,0,0,0,0,0),boardObj);
                    newBishopPos+=offset;
                }
            }
        }
    }

    //Rook

    int rook = boardObj->turn==white?whiteRook:blackRook;
    int numOfRooks = boardObj->numOfPieces[rook];
    for(int i=1;i<=numOfRooks;i++)
    {
        int rookPos = boardObj->pieceList[rook][i];
        for(int offset:rookOffsets)
        {
            int newRookPos = rookPos + offset;
            while(boardObj->board[newRookPos]!=Offboard)
            {
                if(boardObj->board[newRookPos]!=Empty)
                {
                    if(pieceColor[boardObj->board[newRookPos]]!=pieceColor[rook])
                    {
                        addCaptureMove(&moves,setMove(rookPos,newRookPos,0,0,0,1,0),boardObj);
                    }
                    break;
                }
                else if(boardObj->board[newRookPos]==Empty)
                {
                    addQuietMove(&moves,setMove(rookPos,newRookPos,0,0,0,0,0),boardObj);
                    newRookPos+=offset;
                }
            }
        }
    }

    //Queen
    int queen = boardObj->turn==white?whiteQueen:blackQueen;
    int numOfQueens = boardObj->numOfPieces[queen];
    for(int i=1;i<=numOfQueens;i++)
    {
        int queenPos = boardObj->pieceList[queen][i];
        //Diagonal
        for(int offset:bishopOffsets)
        {
            int newQueenPos = queenPos + offset;
            while(boardObj->board[newQueenPos]!=Offboard)
            {
                if(boardObj->board[newQueenPos]!=Empty)
                {
                    if(pieceColor[boardObj->board[newQueenPos]]!=pieceColor[queen])
                    {
                        addCaptureMove(&moves,setMove(queenPos,newQueenPos,0,0,0,1,0),boardObj);
                    }
                    break;
                }
                else if(boardObj->board[newQueenPos]==Empty)
                {
                    addQuietMove(&moves,setMove(queenPos,newQueenPos,0,0,0,0,0),boardObj);
                    newQueenPos+=offset;
                }
            }
        }
        //horizontal and vertical
        for(int offset:rookOffsets)
        {
            int newQueenPos = queenPos + offset;
            while(boardObj->board[newQueenPos]!=Offboard)
            {
                if(boardObj->board[newQueenPos]!=Empty)
                {
                    if(pieceColor[boardObj->board[newQueenPos]]!=pieceColor[queen])
                    {
                        addCaptureMove(&moves,setMove(queenPos,newQueenPos,0,0,0,1,0),boardObj);
                    }
                    break;
                }
                else if(boardObj->board[newQueenPos]==Empty)
                {
                    addQuietMove(&moves,setMove(queenPos,newQueenPos,0,0,0,0,0),boardObj);
                    newQueenPos+=offset;
                }
            }
        }
    }
    return moves;
}
