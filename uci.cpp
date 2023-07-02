#include <iostream>
#include "defs.h"
#include "board.h"
#include "movegen.h"
#include "search.h"
#include <sstream>

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

    uMove.promotedPiece=0;

    if(moveString.length()==5)
    {
        char promotedPieceChar = moveString[4];
        if(promotedPieceChar=='n')uMove.promotedPiece = 2;
        else if(promotedPieceChar=='b')uMove.promotedPiece = 3;
        else if(promotedPieceChar=='r')uMove.promotedPiece = 4;
        else if(promotedPieceChar=='q')uMove.promotedPiece = 5;
        else uMove.promotedPiece = -1;
    }

    return uMove;
}
void handleUCICommand(const string& command,Board *boardObj) {
    if (command == "uci")
    {
        std::cout << "id name ZacharyChessEngine" << std::endl;
        std::cout << "id author Zachary" << std::endl;

        std::cout << "uciok" << std::endl;
    }
    else if (command == "isready")
    {
        std::cout << "readyok" << std::endl;
    }
    else if (command.substr(0, 8) == "position")
    {
        size_t pos = command.find("startpos");

        if(pos!=string::npos)
        {
            boardObj->parseFen(DEFAULT_POS);
        }

        size_t movesPos = command.find("moves");
        if(movesPos!=string::npos)
        {
            std::string allMoves = command.substr(movesPos+6);
            std::istringstream iss(allMoves);
            std::string word;
            while (iss >> word) {
                // Output each word
                std::cout << "Word: " << word << std::endl;
            }
        }

    }
    else if (command.substr(0, 2) == "go")
    {

        size_t pos = command.find("wtime");
        if (pos != string::npos) {
            int wtime = stoi(command.substr(pos + 6));
        }

        pos = command.find("btime");
        if (pos != string::npos) {

            int btime = stoi(command.substr(pos + 6));

        }
        int bestMove = SearchPosition(boardObj,6);
    }
    else if (command == "stop")
    {

    }
    else if (command == "quit") {

        exit(0);
    }
    else{
        return;
    }
}

void uciLoop(){

    Board boardObj;


    std::string command;
    while(true)
    {
        getline(std::cin, command);


        handleUCICommand(command,&boardObj);
        /*
        if(input.length()==4||input.length()==5)
        {
            uciMove uMove = parseMoveString(input);

            if(uMove.from==-1||uMove.to==-1||uMove.promotedPiece==-1)
            {
                std::cout<<"Invalid move format"<<std::endl;
                continue;
            }

            if(uMove.promotedPiece)
            {
                uMove.promotedPiece = boardObj.turn==black?uMove.promotedPiece+6:uMove.promotedPiece;
            }
            vector<S_MOVE>moves = generateAllMoves(&boardObj);


            int playerMove=0;
            for(S_MOVE s_move:moves)
            {
                int moveFrom = getMoveFrom(s_move.move);
                int moveTo = getMoveTo(s_move.move);
                int movePromotedPiece = getMovePromoted(s_move.move);

                if(uMove.from==moveFrom&&uMove.to ==moveTo &&movePromotedPiece==uMove.promotedPiece)
                {
                    playerMove = s_move.move;
                }
            }
            if(playerMove==0)
            {
                std::cout<<"Invalid move"<<std::endl;
                continue;
            }
            boardObj.makeMove(playerMove);
            boardObj.printBoard();
            cout<<endl;


        }*/
    }

}
