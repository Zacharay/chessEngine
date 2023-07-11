#include <iostream>
#include <bitboards.h>
#include "helpers.h"
#include <climits>


namespace Bitboards
{
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

        for(int rnk=0;rnk<8;rnk++)
        {
            uint64_t whiteForwardMask = LONG_MAX >> (7-rnk+1)*8-1;
            uint64_t blackForwardMask = 0LL;

            if(rnk!=7)blackForwardMask = LONG_MAX<< (rnk+1)*8;;

            for(int file=0;file<8;file++)
            {
                int sq64 = fileRankToSq64(file,rnk);

                uint64_t leftFileMask = fileMask[std::max(0,file-1)];
                uint64_t middleFileMask = fileMask[file];
                uint64_t rightFileMask = fileMask[std::min(7,file+1)];;
                uint64_t trippleFileMask = leftFileMask| middleFileMask|rightFileMask;

                whitePassedPawn[sq64] = trippleFileMask&whiteForwardMask;
                blackPassedPawn[sq64] = trippleFileMask&blackForwardMask;
                isolatedMask[sq64]= leftFileMask!=middleFileMask ? isolatedMask[sq64]|leftFileMask:isolatedMask[sq64];
                isolatedMask[sq64]= rightFileMask!=middleFileMask ? isolatedMask[sq64]|rightFileMask:isolatedMask[sq64];
            }
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
    void setBitboards(uint64_t *bitboards,const int *board)
    {
        for(int i=0;i<13;i++)
        {
            bitboards[i]=0;
        }

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
}


