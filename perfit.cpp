#include "perfit.h"
#include "movegen.h"
#include "defs.h"
#include <iostream>
#include <vector>

u64 perfit(int depth,Board *boardObj){
    vector<S_MOVE>movesList = generateAllMoves(boardObj);
    u64 nodes=0;

    if(depth==0)
    {
        return 1ULL;
    }

    for(S_MOVE s_move:movesList)
    {
        boardObj->makeMove(s_move.move);
        if (boardObj->isMoveLegal())
        {
            nodes += perfit(depth - 1,boardObj);
        }
        boardObj->unmakeMove();
    }
    return nodes;
};
void perfitTest(int depth,Board *boardObj){

    for(int i=1;i<=depth;i++)
    {
        int numOfMs = 0;
        u64 numOfNodes = perfit(i,boardObj);
        std::cout<<"Depth: "<<i<<" ply  Result: "<<numOfNodes<<" Time: "<<numOfMs<<" ms"<<std::endl;
        boardObj->printBoard();
        boardObj->printPieceLists();
        cout<<endl;
    }
};
