#include <iostream>
#include "defs.h"

uint64_t setMask[64];

void initSetMask()
{
    for(int idx=0;idx<64;idx++)
    {
        setMask[idx]= 1ULL << idx;
    }

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
    initSetMask();

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
uint64_t getFileMask(int fileIdx)
{
    const uint64_t fileA = 0x0101010101010101;
    return fileA <<fileIdx;

}
