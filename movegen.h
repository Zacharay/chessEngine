#pragma once
#include <vector>
#include <helpers.h>
#include <board.h>

void generateAllMoves(Board *boardObj,std::vector<S_MOVE>*moves,bool onlyCaptures);
void initMvvLva();
