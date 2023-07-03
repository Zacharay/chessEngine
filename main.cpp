#include <iostream>
#include "board.h"
#include "uci.h"
#include "perfit.h"
#include "search.h"
#include <chrono>
using namespace std;


int main()
{
    /*Board boardObj("rnbqkbnr/ppp1p1pp/8/3pPp2/8/8/PPPP1PPP/RNBQKBNR w KQkq f6 0 3");
    cout<<hex<<boardObj.posHashKey;
    /*for(int i=0;i<10;i++)
    {
         int move = SearchPosition(&boardObj,3);
         boardObj.makeMove(move);
         boardObj.printBoard();
    }*/



    //perfitTest(4,&boardObj);
    uciLoop();
    return 0;
}
