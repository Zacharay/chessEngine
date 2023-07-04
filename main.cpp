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

         boardObj.makeMove(move);
         boardObj.printBoard();
    }*/
    Board boardObj;
    auto start = std::chrono::high_resolution_clock::now();

    int move = SearchPosition(&boardObj,7);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double milliseconds = duration.count() * 1000.0;
    std::cout<<" Time: "<<milliseconds<<" ms"<<std::endl;
    //perfitTest(5,&boardObj);
    uciLoop();
    return 0;
}
