#include <iostream>
#include "defs.h"
#include "board.h"
#include "movegen.h"
#include "search.h"
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

    vector<S_MOVE>moves;
    generateAllMoves(boardObj,&moves);
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
string convertMoveToString(int bestMove)
{
    int moveFrom = getMoveFrom(bestMove);
    int moveTo = getMoveTo(bestMove);
    int promotedPiece = getMovePromoted(bestMove);

    auto it_first = sqNumberToName.find(moveFrom);
    auto it_second = sqNumberToName.find(moveTo);
    string fromSq = it_first->second;
    string toSq = it_second->second;

    if(promotedPiece!=0)
    {
        promotedPiece = promotedPiece<blackPawn?promotedPiece+6:promotedPiece;
        auto it_third = pieceToChar.find(promotedPiece);
        char promotedChar = it_third->second;
        string ans = fromSq+toSq+promotedChar;
        return ans;
    }
    else{
        string ans = fromSq+toSq;
        return ans;
    }



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
        size_t startPos = command.find("startpos");
        size_t fen = command.find("fen");

        if(startPos!=string::npos)
        {
            boardObj->parseFen(DEFAULT_POS);
        }
        else if(fen!= string::npos)
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
        if(movesPos!=string::npos)
        {
            std::string allMoves = command.substr(movesPos+6);
            std::istringstream iss(allMoves);
            std::string moveStr;
            while (iss >> moveStr) {

                int move = parseMoveString(moveStr,boardObj);
                boardObj->makeMove(move);
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

        int bestMove = SearchPosition(boardObj,7);
        std::string bestMoveStr = convertMoveToString(bestMove);
        std::cout<<"bestmove "<<bestMoveStr<<std::endl;
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
