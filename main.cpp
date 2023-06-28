#include <iostream>
#include "board.h"
#include "zobrist.h"
#include "polybook.h"
#include "movegen.h"
using namespace std;


int main()
{
    Board board(TEST_1);
    board.printBoard();
    uint64_t hashKey = getHashKey(&board);

    vector<S_MOVE> ans = generateAllMoves(&board);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        int from = getMoveFrom(ans[i].move);
        int to = getMoveTo(ans[i].move);
        int dbPawn = getMoveDbPawn(ans[i].move);
        int promotedPiece = getMovePromoted(ans[i].move);

        cout<<from<<" "<<to<<" "<<dbPawn<<" "<<promotedPiece<<endl;
    }
    return 0;
}
