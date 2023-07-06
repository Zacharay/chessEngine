#include "defs.h"
#include "board.h"
#include "bitboards.h"

const int PawnTable[64]={
    0,  0 ,  0,  0,  0,  0,  0,  0,
    50, 50, 50, 50, 50, 50, 50, 50,
    10, 10, 20, 30, 30, 20, 10, 10,
    5 ,  5, 10, 25, 25, 10,  5,  5,
    0,  0 ,  0, 20, 20,  0,  0,  0,
    5, -5 ,-10,  0,  0,-10, -5,  5,
    5, 10 , 10,-20,-20, 10, 10,  5,
    0,  0 ,  0,  0,  0,  0,  0,  0
};

const int KnightTable[64]={
    -50,-40,-30,-30,-30,-30,-40,-50,
    -40,-20,  0,  0,  0,  0,-20,-40,
    -30,  0, 10, 15, 15, 10,  0,-30,
    -30,  5, 15, 20, 20, 15,  5,-30,
    -30,  0, 15, 20, 20, 15,  0,-30,
    -30,  5, 10, 15, 15, 10,  5,-30,
    -40,-20,  0,  5,  5,  0,-20,-40,
    -50,-40,-30,-30,-30,-30,-40,-50,
};
const int BishopTable[64]={
    -20,-10,-10,-10,-10,-10,-10,-20,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -10,  0,  5, 10, 10,  5,  0,-10,
    -10,  5,  5, 10, 10,  5,  5,-10,
    -10,  0, 10, 10, 10, 10,  0,-10,
    -10, 10, 10, 10, 10, 10, 10,-10,
    -10,  5,  0,  0,  0,  0,  5,-10,
    -20,-10,-10,-10,-10,-10,-10,-20
};
const int RookTable[64]={
    0 ,  0,  0,  0,  0,  0,  0,  0,
    5 , 10, 10, 10, 10, 10, 10,  5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    0 ,  0,  0,  5,  5,  0,  0,  0
};

const int QueenTable[64] = {
    -20,-10,-10, -5, -5,-10,-10,-20,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -10,  0,  5,  5,  5,  5,  0,-10,
     -5,  0,  5,  5,  5,  5,  0, -5,
      0,  0,  5,  5,  5,  5,  0, -5,
    -10,  5,  5,  5,  5,  5,  0,-10,
    -10,  0,  5,  0,  0,  0,  0,-10,
    -20,-10,-10, -5, -5,-10,-10,-20
};


const int KingTableOpening[64]={
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -20,-30,-30,-40,-40,-30,-30,-20,
    -10,-20,-20,-20,-20,-20,-20,-10,
     20, 20,  0,  0,  0,  0, 20, 20,
     20, 30, 10,  0,  0, 10, 30, 20
};
const int KingTableEndgame[64]={
    -50,-40,-30,-20,-20,-30,-40,-50,
    -30,-20,-10,  0,  0,-10,-20,-30,
    -30,-10, 20, 30, 30, 20,-10,-30,
    -30,-10, 30, 40, 40, 30,-10,-30,
    -30,-10, 30, 40, 40, 30,-10,-30,
    -30,-10, 20, 30, 30, 20,-10,-30,
    -30,-30,  0,  0,  0,  0,-30,-30,
    -50,-30,-30,-30,-30,-30,-30,-50
};
const int PawnPassedBonus[8] = { 0, 5, 10, 20, 35, 60, 100, 200 };
const int PawnIsolated = -10;
const int RookOpenBonus = 10;
const int RookSemiOpenBonus = 5;
const int BishopPairBonus = 30;
const int EndGameThreshold = 20000+500+200+640;

int evaluatePosition(Board *boardObj){
    int score=0;
    int materialWhite=0;
    int materialBlack=0;

    //whitePawns
    for(int i=1;i<=boardObj->numOfPieces[whitePawn];i++)
    {
        materialWhite+= PieceValue[whitePawn];
        int pawnPos = boardObj->pieceList[whitePawn][i];
        score+=PawnTable[sq120to64[pawnPos]];

        int pawnPos64 = sq120to64[pawnPos];
        //passedPawn
        if(!(whitePassedPawn[pawnPos64]&boardObj->bitboards[blackPawn]))
        {
            int pawnRank = 7-getRankFromSq(pawnPos);
            score+=PawnPassedBonus[pawnRank];
        }
        //isolatedPawn
        if(!(isolatedMask[pawnPos64]&boardObj->bitboards[whitePawn]))
        {
            score+=PawnIsolated;
        }

    }

    //whiteKnight
    for(int i=1;i<=boardObj->numOfPieces[whiteKnight];i++)
    {
        materialWhite+= PieceValue[whiteKnight];
        int knightPos = boardObj->pieceList[whiteKnight][i];
        score+=KnightTable[sq120to64[knightPos]];
    }

    //whiteBishop
    for(int i=1;i<=boardObj->numOfPieces[whiteBishop];i++)
    {
        materialWhite+= PieceValue[whiteBishop];
        int bishopPos = boardObj->pieceList[whiteBishop][i];
        score+=BishopTable[sq120to64[bishopPos]];
    }

    //white Rook
    for(int i=1;i<=boardObj->numOfPieces[whiteRook];i++)
    {
        materialWhite+= PieceValue[whiteRook];
        int rookPos = boardObj->pieceList[whiteRook][i];
        score+=RookTable[sq120to64[rookPos]];
        uint64_t rookFileMask = fileMask[getFileFromSq(rookPos)-1];
        if(!(rookFileMask&boardObj->bitboards[whitePawn])&&!(rookFileMask&boardObj->bitboards[blackPawn]))
        {
            score+=RookOpenBonus;
        }
        else if(!(rookFileMask&boardObj->bitboards[whitePawn]))
        {
            score+=RookSemiOpenBonus;
        }
    }

    //white Queen
    for(int i=1;i<=boardObj->numOfPieces[whiteQueen];i++)
    {
        materialWhite+= PieceValue[whiteQueen];
        int queenPos = boardObj->pieceList[whiteQueen][i];
        score+=QueenTable[sq120to64[queenPos]];
    }

    //black Pawns
    for(int i=1;i<=boardObj->numOfPieces[blackPawn];i++)
    {
        materialBlack += PieceValue[blackPawn];
        int pawnPos = boardObj->pieceList[blackPawn][i];
        score-=PawnTable[MirrorSq[sq120to64[pawnPos]]];

        //passedPawn
        int pawnPos64 = sq120to64[pawnPos];
        if(!(blackPassedPawn[pawnPos64]&boardObj->bitboards[whitePawn]))
        {
            int pawnRank = getRankFromSq(pawnPos);
            score-=PawnPassedBonus[pawnRank];
        }
        //isolatedPawn
        if(!(isolatedMask[pawnPos64]&boardObj->bitboards[blackPawn]))
        {
            score-=PawnIsolated;
        }

    }

    //black knight
    for(int i=1;i<=boardObj->numOfPieces[blackKnight];i++)
    {
        materialBlack += PieceValue[blackKnight];
        int knightPos = boardObj->pieceList[blackKnight][i];
        score-=KnightTable[MirrorSq[sq120to64[knightPos]]];
    }

    //black Bishop
    for(int i=1;i<=boardObj->numOfPieces[blackBishop];i++)
    {
        materialBlack += PieceValue[blackBishop];
        int bishopPos = boardObj->pieceList[blackBishop][i];
        score-=BishopTable[MirrorSq[sq120to64[bishopPos]]];
    }

    //black Rook
    for(int i=1;i<=boardObj->numOfPieces[blackRook];i++)
    {
        materialBlack += PieceValue[blackRook];
        int rookPos = boardObj->pieceList[blackRook][i];
        score-=RookTable[MirrorSq[sq120to64[rookPos]]];

        uint64_t rookFileMask = fileMask[getFileFromSq(rookPos)-1];
        if(!(rookFileMask&boardObj->bitboards[whitePawn])&&!(rookFileMask&boardObj->bitboards[blackPawn]))
        {
            score-=RookOpenBonus;
        }
        else if(!(rookFileMask&boardObj->bitboards[blackPawn]))
        {
            score-=RookSemiOpenBonus;
        }

    }

    //black Queen
    for(int i=1;i<=boardObj->numOfPieces[blackQueen];i++)
    {
        materialBlack += PieceValue[blackQueen];
        int queenPos = boardObj->pieceList[blackQueen][i];
        score-=QueenTable[MirrorSq[sq120to64[queenPos]]];
    }

    //Kings
    materialWhite += PieceValue[whiteKing];
    materialBlack += PieceValue[blackKing];

    //white king
    int whiteKingPos = boardObj->pieceList[whiteKing][1];
    if(materialBlack<=EndGameThreshold)
    {
        score+= KingTableEndgame[sq120to64[whiteKingPos]];
    }
    else{
        score+= KingTableOpening[sq120to64[whiteKingPos]];
    }
    //black king
    int blackKingPos = boardObj->pieceList[blackKing][1];
    if(materialWhite<=EndGameThreshold)
    {
        score-= KingTableEndgame[MirrorSq[sq120to64[blackKingPos]]];
    }
    else{
        score-= KingTableOpening[MirrorSq[sq120to64[blackKingPos]]];
    }

    //Bishop Pair bonuses
    if(boardObj->numOfPieces[whiteBishop]>=2)
    {
        score+=BishopPairBonus;
    }
    if(boardObj->numOfPieces[blackBishop]>=2)
    {
        score-=BishopPairBonus;
    }
    score+=(materialWhite-materialBlack);
    if(boardObj->turn==white)return score;
    else return -score;

};

int evaluateGameOver(Board *boardObj){
    int kingIdx = boardObj->turn==white?whiteKing:blackKing;
    int kingPiecePos = boardObj->pieceList[kingIdx][1];
    if(boardObj->isSquareAttacked(kingPiecePos,!boardObj->turn))
    {
        if(boardObj->turn==white)
        {
            return 900000;
        }
        else{
            return -900000;
        }
    }
    else{
        return 0;
    }
}
