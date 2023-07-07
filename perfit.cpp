#include "perfit.h"
#include "movegen.h"
#include "defs.h"
#include <iostream>
#include <vector>
#include <chrono>
#include "search.h"
#include <fstream>
#include <ctime>

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

void perfitSearch(int depth,bool logToFile,std::string description)
{
    std::ifstream input("test_positions.txt");

    if (!input) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }
    std::string fen[100];
    //opening phase
    for(int i=0;i<100;i++)
    {
        std::getline(input,fen[i]);
    }
    Board boardObj;
    //opening phase(28pieces)
    auto openingStart = std::chrono::high_resolution_clock::now();
    for(int i=0;i<30;i++)
    {
        boardObj.parseFen(fen[i]);
        //int move = SearchPosition(&boardObj,depth);
    }
    auto openingEnd =  std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationOpening = openingEnd - openingStart;
    double timeOpeningMs = durationOpening.count() * 1000.0;

    //middle phase(20 pieces)
    auto middleStart = std::chrono::high_resolution_clock::now();
    for(int i=30;i<60;i++)
    {
        boardObj.parseFen(fen[i]);
        //int move = SearchPosition(&boardObj,depth);
    }
    auto middleEnd  =std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationMiddle = middleEnd - middleStart;
    double timeMiddleMs = durationMiddle.count() * 1000.0;

    //end phase(16 pieces)
    auto endPhaseStart = std::chrono::high_resolution_clock::now();
    for(int i=60;i<100;i++)
    {
        boardObj.parseFen(fen[i]);
        //int move = SearchPosition(&boardObj,depth);
    }
    auto endPhaseEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationEnd = endPhaseEnd - endPhaseStart;
    double timeEndMs = durationEnd.count() * 1000.0;

    std::chrono::duration<double> durationOverall = endPhaseEnd - openingStart;
    double timeOverallMs = durationOverall.count() * 1000.0;
    input.close();





    if(logToFile)
    {
        std::ofstream output("search_logs.txt", std::ios::app);

        if (!output) {
            std::cerr << "Failed to open the file." << std::endl;
        }
        std::time_t currentTime = std::time(nullptr);
        std::string dateString = std::ctime(&currentTime);

        output  << "[DATE] "        <<dateString    <<std::endl;
        output  <<"[DESCRIPTION]    "<<description   <<std::endl;
        output  <<"[DEPTH           "<<depth         <<std::endl;
        output  <<"[OPENING]        "<<timeOpeningMs <<"ms"<<std::endl;
        output  <<"[MIDDLE]         "<<timeMiddleMs  <<"ms"<<std::endl;
        output  <<"[END]            "<<timeEndMs     <<"ms"<<std::endl;
        output  <<"[OVERALL]        "<<timeOverallMs <<"ms"<<std::endl;
        output  <<std::endl         <<std::endl;
        output.close();
    }
    else
    {
        cout<<timeOpeningMs<<endl;
        cout<<timeMiddleMs<<endl;
        cout<<timeEndMs<<endl;
        cout<<timeOverallMs<<endl;
    }
}
