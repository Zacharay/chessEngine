#include "tt.h"
#include "defs.h"
#include <iostream>
TT::TT(int hashTableSizeMB)
{
    int sizeB = hashTableSizeMB*1000*1000;
    int entrySize = sizeof(TT_Entry);

    numOfEntires = sizeB / entrySize;
    entries = new TT_Entry[numOfEntires];
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
bool TT::getHashEntry(uint64_t posHashKey,int depth,int &bestMove,int &score,int alpha,int beta)
{
    int index = posHashKey%numOfEntires;
    if(entries[index].pos==posHashKey)
    {
        bestMove = entries[index].bestMove;
        if(depth<=entries[index].depth)
        {
            score = entries[index].score;
            if(entries[index].typeOfNode==hashFlagAlpha && score<=alpha)
            {
                score = alpha;
                return true;
            }
            else if(entries[index].typeOfNode==hashFlagBeta&& score>=beta)
            {
                score = beta;
                return true;
            }
            else if(entries[index].typeOfNode==hashFlagExact)
            {
                return true;
            }
        }
    }
    return false;
};
