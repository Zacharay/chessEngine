#include "uci.h"
#include <iostream>
#include "init.h"
#include "board.h"
#include "perfit.h"

void test();
int main(int argc, char* argv[])
{
    init();
    //test();
    uciLoop();
    return 0;
}
