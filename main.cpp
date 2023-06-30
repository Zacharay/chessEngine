#include <iostream>
#include "board.h"
#include "zobrist.h"
#include "polybook.h"
#include "movegen.h"
#include "uci.h"
#include "perfit.h"
using namespace std;


int main()
{
    Board boardObj;
    boardObj.printBoard();
    perfitTest(5,&boardObj);
    //uciLoop();
    return 0;
}
