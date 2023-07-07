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
    searchInfo s_info;
    s_info.startTime = std::chrono::steady_clock::now();
    auto stopDuration = std::chrono::milliseconds(2000);
    s_info.stopTime = std::chrono::steady_clock::now()+stopDuration;

    while(true)
    {
        cout<<"xd"<<endl;
        if(s_info.stopTime<=std::chrono::steady_clock::now())
        {
            break;
        }
    }
    //perfitSearch(5,true,"test with allocated tt");
}
