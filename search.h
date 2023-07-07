#pragma once
#include "board.h"
#include "chrono"
struct searchInfo{
    std::chrono::steady_clock::time_point  startTime;
    std::chrono::steady_clock::time_point  stopTime;
    bool stop;
};
int SearchPosition(Board *board,searchInfo *SearchInfo);
int negaMax(Board *boardObj,int depth,int alpha,int beta,searchInfo *SearchInfo);
