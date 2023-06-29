#include <iostream>
#include "defs.h"


struct uciMove{
    int from;
    int to;
    int promotedPiece;
};

uciMove parseMoveString(std::string moveString)
{
    uciMove uMove;

    std::string firstSqName = moveString.substr(0,2);
    std::string secondSqName = moveString.substr(2,2);

    auto it_from = sqNameToNumber.find(firstSqName);
    auto it_to =  sqNameToNumber.find(secondSqName);
    if(it_from==sqNameToNumber.end())
    {
        uMove.from = -1;
    }
    else {
        uMove.from = it_from->second;
    }

    if(it_to==sqNameToNumber.end())
    {
        uMove.to = -1;
    }
    else {
        uMove.to = it_to->second;
    }

    if(moveString.length()==5)
    {
        char promotedPieceChar = moveString[4];
        if(promotedPieceChar=='n')uMove.promotedPiece = 2;
        else if(promotedPieceChar=='b')uMove.promotedPiece = 3;
        else if(promotedPieceChar=='r')uMove.promotedPiece = 4;
        else if(promotedPieceChar=='q')uMove.promotedPiece = 5;
    }

    return uMove;
}

void uciLoop(){
    std::string input;
    while(true)
    {
        getline(std::cin, input);


        if(input.length()==4||input.length()==5)
        {
            uciMove uMove = parseMoveString(input);

            if(uMove.from==-1||uMove.to==-1||uMove.promotedPiece==-1)
            {
                std::cout<<"Invalid move format"<<std::endl;
                continue;
            }


        }
        //Exit on enter
        if (input.empty()) {
            break;
        }
    }

}
