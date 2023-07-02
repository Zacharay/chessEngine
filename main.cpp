#include <iostream>
#include "board.h"
#include "uci.h"
#include "perfit.h"
#include "search.h"
#include <chrono>
using namespace std;


int main()
{
    /*Board boardObj;

    for(int i=0;i<10;i++)
    {
         int move = SearchPosition(&boardObj,3);
         boardObj.makeMove(move);
         boardObj.printBoard();
    }*/



    ///perfitTest(4,&boardObj);
    uciLoop();
    return 0;
}
