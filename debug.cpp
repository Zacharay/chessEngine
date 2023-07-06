#include <iostream>
#include "board.h"
#include "perfit.h"
#include "search.h"
#include "bitboards.h"
#include <stdio.h>
using namespace std;
void test()
{
    Board boardObj("3K4/8/3k4/8/2q5/6q1/8/8 b - - 55 117");
    int move = SearchPosition(&boardObj,6);
    boardObj.makeMove(move);
    uint64_t mask = rankMask[7];
    //printBitboard(mask);



}
