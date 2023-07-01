#pragma once
#include "board.h"
int SearchPosition(Board *board,int depth);
int negaMax(Board *boardObj,int depth,int alpha,int beta);
