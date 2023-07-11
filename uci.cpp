#include <iostream>
#include "helpers.h"
#include "board.h"
#include "movegen.h"
#include "search.h"
#include <chrono>
#include <sstream>

int parseMoveString(std::string moveString,Board *boardObj)
{
    int from;
    int to;
    int promotedPiece;

    std::string firstSqName = moveString.substr(0,2);
    std::string secondSqName = moveString.substr(2,2);

    auto it_from = sqNameToNumber.find(firstSqName);
    auto it_to =  sqNameToNumber.find(secondSqName);
    if(it_from==sqNameToNumber.end())
    {
       from = -1;
    }
    else {
        from = it_from->second;
    }

    if(it_to==sqNameToNumber.end())
    {
        to = -1;
    }
    else {
        to = it_to->second;
    }

    promotedPiece=0;

    if(moveString.length()==5)
    {

        int addColorValue = boardObj->turn==white?0:6;
        char promotedPieceChar = moveString[4];

        if(promotedPieceChar=='n')promotedPiece = 2+addColorValue;
        else if(promotedPieceChar=='b')promotedPiece = 3+addColorValue;
        else if(promotedPieceChar=='r')promotedPiece = 4+addColorValue;
        else if(promotedPieceChar=='q')promotedPiece = 5+addColorValue;
        else promotedPiece = -1;
    }

    std::vector<S_MOVE>moves;
    generateAllMoves(boardObj,&moves,false);
    for(S_MOVE smove:moves)
    {
        int move = smove.move;
        if(getMoveFrom(move)==from&&getMoveTo(move)==to)
        {
            if(promotedPiece>0)
            {
                if(getMovePromoted(move)==promotedPiece)
                {
                    return move;
                }
            }
            else{
                return move;
            }

        }
    }
}
std::string convertMoveToString(int bestMove)
{
    int moveFrom = getMoveFrom(bestMove);
    int moveTo = getMoveTo(bestMove);
    int promotedPiece = getMovePromoted(bestMove);

    auto it_first = sqNumberToName.find(moveFrom);
    auto it_second = sqNumberToName.find(moveTo);
    std::string fromSq = it_first->second;
    std::string toSq = it_second->second;

    if(promotedPiece!=0)
    {
        promotedPiece = promotedPiece<blackPawn?promotedPiece+6:promotedPiece;
        auto it_third = pieceToChar.find(promotedPiece);
        char promotedChar = it_third->second;
        std::string ans = fromSq+toSq+promotedChar;
        return ans;
    }
    else{
        std::string ans = fromSq+toSq;
        return ans;
    }



}
void ParsePosition(std::string command,Board *boardObj)
{
    size_t startPos = command.find("startpos");
    size_t fen = command.find("fen");

    if(startPos!=std::string::npos)
    {
        boardObj->parseFen(DEFAULT_POS);
    }
    else if(fen!= std::string::npos)
    {
        std::string temp = command.substr(fen+4);
        std::istringstream iss(temp);
        std::string fenStr="";
        std::string tempStr;
        for(int i=0;i<5;i++)
        {
            iss>>tempStr;
            fenStr+= tempStr+" ";
        }
        iss>>tempStr;
        fenStr+= tempStr;
        boardObj->parseFen(fenStr);
    }

    size_t movesPos = command.find("moves");
    if(movesPos!=std::string::npos)
    {
        std::string allMoves = command.substr(movesPos+6);
        std::istringstream iss(allMoves);
        std::string moveStr;
        while (iss >> moveStr)
        {
            int move = parseMoveString(moveStr,boardObj);
            boardObj->makeMove(move);
        }

    }
}
void ParseGo(std::string command,searchInfo *SearchInfo,Board *boardObj)
{
    int time = -1;
    int inc = 0;
    int movesToGo = 40;

    SearchInfo->depth = 40;
    SearchInfo->timeSet= false;
    SearchInfo->stop = false;

    if(boardObj->turn==white)
    {
        size_t timePos = command.find("wtime");
        if (timePos != std::string::npos) {
            time = stoi(command.substr(timePos + 6));
        }
        size_t incPos = command.find("winc");
        if(incPos != std::string::npos){
            inc = stoi(command.substr(incPos + 5));
        }
    }
    else{
        size_t timePos = command.find("btime");
        if (timePos != std::string::npos) {
            time = stoi(command.substr(timePos + 6));
        }
        size_t incPos = command.find("binc");
        if(incPos != std::string::npos){
            inc = stoi(command.substr(incPos + 5));
        }
    }


    size_t movesToGoPos = command.find("movestogo");
    if(movesToGoPos!= std::string::npos)
    {
        movesToGo = stoi(command.substr(movesToGoPos + 10));
    }
    size_t depthPos = command.find("depth");
    if(depthPos!= std::string::npos)
    {
        SearchInfo->depth = stoi(command.substr(depthPos + 6));
    }


    if(time!=-1)
    {
        time/=movesToGo;
        time -=50;
        auto searchDuration = std::chrono::milliseconds(time+inc);

        SearchInfo->startTime = std::chrono::steady_clock::now();
        SearchInfo->stopTime  = SearchInfo->startTime + searchDuration;
        SearchInfo->timeSet = true;
    }

    int bestMove = SearchPosition(boardObj,SearchInfo);
    std::string bestMoveStr = convertMoveToString(bestMove);
    std::cout<<"bestmove "<<bestMoveStr<<std::endl;
}

void uciLoop(){

    Board boardObj;
    searchInfo SearchInfo;

    std::string command;
    while(true)
    {
            getline(std::cin, command);
            if (command == "uci")
            {
                std::cout << "id name ZacharyChess" << std::endl;
                std::cout << "id author Zachary" << std::endl;

                std::cout << "uciok" << std::endl;
            }
            else if (command == "ucinewgame")
            {
                boardObj.parseFen(DEFAULT_POS);
            }
            else if (command == "isready")
            {
                std::cout << "readyok" << std::endl;
            }
            else if (command.substr(0, 8) == "position")
            {
                ParsePosition(command,&boardObj);
            }
            else if (command.substr(0, 2) == "go")
            {
                ParseGo(command,&SearchInfo,&boardObj);
            }
            else if (command == "stop")
            {
                SearchInfo.stop= true;
            }
            else if (command == "quit") {
                break;
            }
        }

}
