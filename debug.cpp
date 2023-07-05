#include <iostream>
#include "board.h"
#include "perfit.h"
#include "search.h"
#include "bitboards.h"
#include <stdio.h>
using namespace std;
void test()
{
    Board boardObj;
    int move = SearchPosition(&boardObj,5);
    boardObj.makeMove(move);
    cout<<getMoveFrom(move)<<" "<<getMoveTo(move)<<endl;
    printAllBitboards(boardObj.bitboards);

}
