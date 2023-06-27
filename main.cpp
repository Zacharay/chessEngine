#include <iostream>
#include "board.h"
#include "zobrist.h"
#include "polybook.h"
#include "movegen.h"
using namespace std;


int main()
{
    Board board;
    board.printBoard();
    uint64_t hashKey = getHashKey(&board);

    vector<S_MOVE> ans = generateAllMoves(&board);
    return 0;
}
