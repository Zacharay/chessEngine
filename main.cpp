#include <iostream>
#include "board.h"
#include "zobrist.h"
#include "polybook.h"
#include "movegen.h"
#include "uci.h"
using namespace std;


int main()
{
    uciLoop();
    return 0;
}
