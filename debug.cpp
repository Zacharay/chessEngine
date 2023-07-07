#include <iostream>
#include "board.h"
#include "perfit.h"
#include "search.h"
#include "bitboards.h"
#include <stdio.h>
using namespace std;
void test()
{
    //perfitSearch(5,true,"Changed way of calculating heuristicts in movegen");
    Board boardObj("6R1/8/3K4/8/7k/8/R7/8 b - - 21 11");
    boardObj.printBoard();
    int move = SearchPosition(&boardObj,5);
    cout<<move<<endl;
    boardObj.makeMove(move);
    boardObj.printBoard();
}
