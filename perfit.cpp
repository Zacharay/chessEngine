#include "perfit.h"
#include "movegen.h"
#include "defs.h"
#include <iostream>
#include <vector>
#include <chrono>


u64 perfit(int depth,Board *boardObj){
    vector<S_MOVE>movesList;
    generateAllMoves(boardObj,&movesList);

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
        auto start = std::chrono::high_resolution_clock::now();

        u64 numOfNodes = perfit(i,boardObj);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        double milliseconds = duration.count() * 1000.0;
        std::cout<<"Depth: "<<i<<" ply  Result: "<<numOfNodes<<" Time: "<<milliseconds<<" ms"<<std::endl;
    }
};
