#include <iostream>
#include "board.h"
#include "uci.h"
#include "perfit.h"
#include "search.h"
using namespace std;


int main()
{
    Board boardObj;
    int move = SearchPosition(&boardObj,3);
    int from = getMoveFrom(move);
    int to = getMoveTo(move);
    int capture = getMoveCapture(move);
    int dbPawn = getMoveDbPawn(move);
    cout<<from<<" "<<to<<" "<<capture<<" "<<dbPawn<<endl;
    boardObj.makeMove(move);
    boardObj.printBoard();
    ///perfitTest(4,&boardObj);
    //uciLoop();
    return 0;
}
