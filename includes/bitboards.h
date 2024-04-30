#pragma once
#include "cstdint"

namespace Bitboards{
    void setBitboards(uint64_t *bitboards,const int *board);
    void initBitboardsMasks();
    void setBit(int idx,uint64_t &bitboard);
    void clearBit(int bitIdx,uint64_t &bitboard);
    void printBitboard(uint64_t bitboard);
    void printAllBitboards(uint64_t *bitboards);
    uint64_t getFileMask(int fileIdx);

    extern uint64_t fileMask[8];
    extern uint64_t rankMask[8];

    extern uint64_t whitePassedPawn[64];
    extern uint64_t blackPassedPawn[64];
    extern uint64_t isolatedMask[64];
}


