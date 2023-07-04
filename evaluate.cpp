#include "defs.h"
#include "board.h"

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

const int MirrorSq[64]={
    56, 57, 58, 59, 60, 61, 62, 63,
    48, 49, 50, 51, 52, 53, 54, 55,
    40, 41, 42, 43, 44, 45, 46, 47,
    32, 33, 34, 35, 36, 37, 38, 39,
    24, 25, 26, 27, 28, 29, 30, 31,
    16, 17, 18, 19, 20, 21, 22, 23,
    8 , 9 , 10, 11, 12, 13, 14, 15,
    0 , 1 , 2 , 3 , 4 , 5 , 6 , 7
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
