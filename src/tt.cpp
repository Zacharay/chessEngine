#include "tt.h"
#include "helpers.h"
#include <iostream>
TT::TT(int hashTableSizeMB)
{
    newWrites=0;
    overWrites=0;

    int sizeB = hashTableSizeMB*1000*1000;
    int entrySize = sizeof(TT_Entry);

    numOfEntires = sizeB / entrySize;
    entries = new TT_Entry[numOfEntires];
    for(int i=0;i<numOfEntires;i++)
    {
        entries[i].pos = 0;
    }
}
TT::~TT()
{
    delete[] entries;
}
void TT::storeHashEntry(uint64_t posHashKey,int depth,int bestMove,int score,int typeOfNode){
    int index = posHashKey%numOfEntires;

    if(entries[index].pos==0)
    {
        newWrites++;
    }
    else{
        overWrites++;
    }

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
void TT::printState()
{
    std::cout<<"NewWrites: "<<newWrites<<std::endl;
    std::cout<<"OverWrites: "<<overWrites<<std::endl;

    double fillPercentage = double((newWrites-overWrites)/double(numOfEntires)*100);
    std::cout<<"Fill Percentage"<<fillPercentage<<std::endl;
}
