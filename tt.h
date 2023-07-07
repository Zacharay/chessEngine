#pragma once
#include <cstdint>
#include <cstddef>
struct TT_Entry
{
    uint64_t pos;
    int depth;
    int bestMove;
    int score;
    int typeOfNode;
};


class TT{
    TT_Entry* entries;
    size_t numOfEntires;
    public:
    TT(int hashTableSizeMB);
    ~TT();
    void storeHashEntry(uint64_t posHashKey,int depth,int bestMove,int score,int typeOfNode);
};
