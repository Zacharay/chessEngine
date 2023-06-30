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


void addWhitePawnMove(Board *boardObj,vector<S_MOVE> *moves,int from,int to,int capturedPiece)
{
    int rankFrom = from/10;
    if(capturedPiece)
    {
        //Promotion Moves
        if(rankFrom==3)
        {
            addCaptureMove(moves,setMove(from,to,whiteKnight,0,0,capturedPiece,0),boardObj);
            addCaptureMove(moves,setMove(from,to,whiteBishop,0,0,capturedPiece,0),boardObj);
            addCaptureMove(moves,setMove(from,to,whiteRook,0,0,capturedPiece,0),boardObj);
            addCaptureMove(moves,setMove(from,to,whiteQueen,0,0,capturedPiece,0),boardObj);
        }
        else{
            addCaptureMove(moves,setMove(from,to,0,0,0,capturedPiece,0),boardObj);
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
void addBlackPawnMove(Board *boardObj,vector<S_MOVE> *moves,int from,int to,int capturedPiece){
    int rankFrom = from/10;
    if(capturedPiece)
    {
        //Promotion Moves
        if(rankFrom==8)
        {
            addCaptureMove(moves,setMove(from,to,blackKnight,0,0,capturedPiece,0),boardObj);
            addCaptureMove(moves,setMove(from,to,blackBishop,0,0,capturedPiece,0),boardObj);
            addCaptureMove(moves,setMove(from,to,blackRook,0,0,capturedPiece,0),boardObj);
            addCaptureMove(moves,setMove(from,to,blackQueen,0,0,capturedPiece,0),boardObj);
        }
        else{
            addCaptureMove(moves,setMove(from,to,0,0,0,capturedPiece,0),boardObj);
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
        //Pawns
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
                int capturedPiece = boardObj->board[pawnPos -11];
                addWhitePawnMove(boardObj,&moves,pawnPos,pawnPos-11,capturedPiece);
            }
            if(boardObj-> board[pawnPos -9]>=blackPawn&&boardObj-> board[pawnPos - 9]<blackKing)
            {
                int capturedPiece = boardObj->board[pawnPos -9];
                addWhitePawnMove(boardObj,&moves,pawnPos,pawnPos-9,capturedPiece);
            }
        }


        //castling
        int kingPos = boardObj->pieceList[whiteKing][1];
        if(!boardObj->isSquareAttacked(kingPos,black))
        {
            if(boardObj->castlingRights&WKCA)
            {
                bool isKingSideEmpty = boardObj->board[F1]==Empty&&boardObj->board[G1]==Empty;
                if(isKingSideEmpty&&!boardObj->isSquareAttacked(F1,black)&&!boardObj->isSquareAttacked(G1,black))
                {
                    addQuietMove(&moves,setMove(E1,G1,0,0,WKCA,0,0),boardObj);
                }
            }
            if(boardObj->castlingRights&WQCA)
            {
                bool isQueenSideEmpty = boardObj->board[D1]==Empty&&boardObj->board[C1]==Empty&&boardObj->board[B1]==Empty;
                if(isQueenSideEmpty&&!boardObj->isSquareAttacked(D1,black)&&!boardObj->isSquareAttacked(C1,black)&&!boardObj->isSquareAttacked(B1,black))
                {
                    addQuietMove(&moves,setMove(E1,C1,0,0,WQCA,0,0),boardObj);
                }
            }
        }
        //enPassant
        int enPassantSq = boardObj->enPassantSq;
        if(enPassantSq!=Offboard)
        {
            if(boardObj->board[enPassantSq+9]==whitePawn)
            {
                addCaptureMove(&moves,setMove(enPassantSq+9,enPassantSq,0,1,0,1,0),boardObj);
            }
            if(boardObj->board[boardObj->enPassantSq+11]==whitePawn)
            {
                addCaptureMove(&moves,setMove(enPassantSq+11,enPassantSq,0,1,0,1,0),boardObj);
            }
        }

    }
    else{
        //Pawns
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
                int capturedPiece = boardObj->board[pawnPos +11];
                addBlackPawnMove(boardObj,&moves,pawnPos,pawnPos+ 11,capturedPiece);
            }
            if(boardObj-> board[pawnPos +9]>=whitePawn&&boardObj-> board[pawnPos + 9]<whiteKing)
            {
                int capturedPiece = boardObj->board[pawnPos +9];
                addBlackPawnMove(boardObj,&moves,pawnPos,pawnPos+9,capturedPiece);
            }
        }
        //castling
        int kingPos = boardObj->pieceList[blackKing][1];
        if(!boardObj->isSquareAttacked(kingPos,white))
        {
            if(boardObj->castlingRights&BKCA)
            {
                bool isKingSideEmpty = boardObj->board[F8]==Empty&&boardObj->board[G8]==Empty;
                if(isKingSideEmpty&&!boardObj->isSquareAttacked(F8,white)&&!boardObj->isSquareAttacked(G8,white))
                {
                    addQuietMove(&moves,setMove(E8,G8,0,0,BKCA,0,0),boardObj);
                }
            }
            if(boardObj->castlingRights&BQCA)
            {
                bool isQueenSideEmpty = boardObj->board[D8]==Empty&&boardObj->board[C8]==Empty&&boardObj->board[B8]==Empty;
                if(isQueenSideEmpty&&!boardObj->isSquareAttacked(D8,white)&&!boardObj->isSquareAttacked(C8,white)&&!boardObj->isSquareAttacked(B8,white))
                {
                    addQuietMove(&moves,setMove(E8,C8,0,0,BQCA,0,0),boardObj);
                }
            }
        }
        //enPassant
        int enPassantSq = boardObj->enPassantSq;
        if(enPassantSq!=Offboard)
        {

            if(boardObj->board[enPassantSq-9]==blackPawn)
            {
                addCaptureMove(&moves,setMove(enPassantSq-9,enPassantSq,0,1,0,1,0),boardObj);
            }
            if(boardObj->board[enPassantSq-11]==blackPawn)
            {
                addCaptureMove(&moves,setMove(enPassantSq-11,enPassantSq,0,1,0,1,0),boardObj);
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
                int capturedPiece = boardObj->board[newKnightPos];
                addCaptureMove(&moves,setMove(knightPos,newKnightPos,0,0,0,capturedPiece,0),boardObj);
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
            int capturedPiece = boardObj->board[newKingPos];
            addCaptureMove(&moves,setMove(kingPos,newKingPos,0,0,0,capturedPiece,0),boardObj);
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
                        int capturedPiece = boardObj->board[newBishopPos];
                        addCaptureMove(&moves,setMove(bishopPos,newBishopPos,0,0,0,capturedPiece,0),boardObj);
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
                        int capturedPiece = boardObj->board[newRookPos];
                        addCaptureMove(&moves,setMove(rookPos,newRookPos,0,0,0,capturedPiece,0),boardObj);
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
                        int capturedPiece = boardObj->board[newQueenPos];
                        addCaptureMove(&moves,setMove(queenPos,newQueenPos,0,0,0,capturedPiece,0),boardObj);
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
                        int capturedPiece = boardObj->board[newQueenPos];
                        addCaptureMove(&moves,setMove(queenPos,newQueenPos,0,0,0,capturedPiece,0),boardObj);
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
