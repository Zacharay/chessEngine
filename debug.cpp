#include <iostream>
#include "board.h"
#include "perfit.h"
#include "search.h"
#include "bitboards.h"
#include <stdio.h>
#include "tt.h"
#include "chrono"
using namespace std;
void test()
{
    Board boardObj("8/k7/3p4/p2P1p2/P2P1P2/8/8/K7 w - - 0 1");
    auto openingStart = std::chrono::high_resolution_clock::now();
    int move = SearchPosition(&boardObj,30);
    auto openingEnd =  std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationOpening = openingEnd - openingStart;
    double timeOpeningMs = durationOpening.count() * 1000.0;
    cout<<timeOpeningMs;
    //perfitSearch(5,true,"test with allocated tt");
}
