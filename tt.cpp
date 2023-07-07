#include "tt.h"
#include <iostream>
TT::TT(int hashTableSizeMB)
{
    int sizeB = hashTableSizeMB*1000*1000;
    int entrySize = sizeof(TT_Entry);

    numOfEntires = sizeB / entrySize;
    entries = new TT_Entry[numOfEntires];
    entries[200000].pos  = 2;
    std::cout<<entries[200000].pos;
}
TT::~TT()
{
    delete[] entries;
}
void TT::storeHashEntry(uint64_t posHashKey,int depth,int bestMove,int score,int typeOfNode){
    int index = posHashKey%numOfEntires;

    entries[index].pos = posHashKey;
    entries[index].bestMove = bestMove;
    entries[index].depth = depth;
    entries[index].score = score;
    entries[index].typeOfNode = typeOfNode;

};
