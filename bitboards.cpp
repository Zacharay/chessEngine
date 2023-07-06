#include <iostream>
#include <bitboards.h>
#include "defs.h"
#include <climits>

uint64_t setMask[64];
uint64_t fileMask[8];
uint64_t rankMask[8];

uint64_t whitePassedPawn[64];
uint64_t blackPassedPawn[64];
uint64_t isolatedMask[64];

void initBitboardsMasks()
{
    for(int i=0;i<64;i++)
    {
        setMask[i] = 0ULL<<i;
        whitePassedPawn[i]= 0ULL<<i;
        blackPassedPawn[i]= 0ULL<<i;
        isolatedMask[i]= 0ULL<<i;
        fileMask[i]= 0ULL<<i;
        rankMask[i]=0ULL<<i;
    }

    for(int idx=0;idx<64;idx++)
    {
        setMask[idx]= 1ULL << idx;
    }

    const uint64_t fileA = 0x0101010101010101;
    for(int i=0;i<8;i++)
    {
        fileMask[i]=fileA<<i;
    }

    const uint64_t rankA = 0x00000000000000FF;
    for(int i=0;i<8;i++)
    {
        rankMask[i]=rankA <<(i*8);
    }
    //white passed pawn
    int i = 42;
    int sqRank = 7-getRankFromSq(i);

    uint64_t forwardMask = LONG_MAX >> (sqRank+1)*8-1;

    int sqFile = getFileFromSq(i)-1;
    uint64_t leftFileMask = fileMask[max(0,sqFile-1)];
    uint64_t middleFileMask = fileMask[sqFile];
    uint64_t rightFileMask = fileMask[min(7,sqFile+1)];;

    uint64_t trippleFileMask = leftFileMask| middleFileMask|rightFileMask;
    uint64_t finalMask = trippleFileMask & forwardMask;

    printBitboard(finalMask);

}
void printBitboard(uint64_t bitboard)
{
    for(int rnk=0;rnk<8;rnk++)
    {
        for(int file=0;file<8;file++)
        {
            int sq64 = fileRankToSq64(file,rnk);
            if((1ULL<<sq64)&bitboard)
            {
                std::cout<<" x ";
            }
            else{
                std::cout<<" - ";
            }
        }
        std::cout<<std::endl;
    }
}
void printAllBitboards(uint64_t *bitboards)
{
    for(int i=whitePawn;i<=blackKing;i++)
    {

        printBitboard(bitboards[i]);
        std::cout<<std::endl;
    }
}
void initBitboards(uint64_t *bitboards,const int *board)
{
    for(int i=0;i<13;i++)
    {
        bitboards[i]=0;
    }
    initBitboardsMasks();

    for(int i=0;i<120;i++)
    {
        if(board[i]==Offboard)continue;

        int sq64 = sq120to64[i];
        int piece = board[i];

        bitboards[piece]|= setMask[sq64];

    }
}
void setBit(int idx,uint64_t &bitboard)
{
    bitboard|= setMask[idx];
}
void clearBit(int bitIdx,uint64_t &bitboard)
{
    bitboard &= ~(1ULL << bitIdx);
}
/*
0000000100000001000000010000000100000001000000010000000100000001
*/
