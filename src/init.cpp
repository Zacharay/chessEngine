#include "bitboards.h"
#include "movegen.h"

void init()
{
    Bitboards::initBitboardsMasks();
    initMvvLva();
}
