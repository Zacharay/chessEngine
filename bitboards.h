#pragma once

void initBitboards(uint64_t *bitboards,const int *board);
void setBit(int idx,uint64_t &bitboard);
void clearBit(int bitIdx,uint64_t &bitboard);
void printBitboard(uint64_t bitboard);
void printAllBitboards(uint64_t *bitboards);
uint64_t getFileMask(int fileIdx);
