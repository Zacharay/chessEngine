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
    int newWrites;
    int overWrites;
    TT(int hashTableSizeMB);
    ~TT();
    void storeHashEntry(uint64_t posHashKey,int depth,int bestMove,int score,int typeOfNode);
    void printState();
    bool getHashEntry(uint64_t posHashKey,int depth,int &bestMove,int &score,int alpha,int beta);
};
