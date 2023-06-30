#include "board.h"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
Board::Board(string fen)
:ply(0),historyPly(0),enPassantSq(Offboard)
{
    parseFen(fen);
}
bool Board::isSquareAttacked(int sq,int bySide) const{

    //Pawns attacks
    if(bySide==white)
    {
        if(board[sq+9]==whitePawn||board[sq+11]==whitePawn)
        {
            return true;
        }
    }
    else{

        if(board[sq-9]==blackPawn||board[sq-11]==blackPawn)
        {
            return true;
        }
    }

    //Knights
    int knightPiece = bySide==white?whiteKnight:blackKnight;
    for(int offset:knightOffsets)
    {
        int temp_sq = sq+offset;
        if(board[temp_sq]==knightPiece)
        {
            return true;
        }
    }

    //King
    int kingPiece = bySide==white?whiteKing:blackKing;
    for(int offset:kingOffsets)
    {
        int temp_sq = sq+offset;
        if(board[temp_sq]==kingPiece)
        {
            return true;
        }
    }

    //bishop
    int bishopPiece =bySide==white?whiteBishop:blackBishop;
    int queenPiece =bySide==white?whiteQueen:blackQueen;

    for(int offset:bishopOffsets)
    {
        int temp_sq = sq + offset;
        while(board[temp_sq]!=Offboard)
        {
            if(board[temp_sq]!=Empty)
            {
                if(board[temp_sq]==bishopPiece||board[temp_sq]==queenPiece)
                {
                    return true;
                }
                break;
            }
            else{
                temp_sq+=offset;
            }
        }
    }

    //rook
    int rookPiece =bySide==white?whiteRook:blackRook;
    for(int offset:rookOffsets)
    {
        int temp_sq = sq + offset;
        while(board[temp_sq]!=Offboard)
        {
            if(board[temp_sq]!=Empty)
            {
                if(board[temp_sq]==rookPiece||board[temp_sq]==queenPiece)
                {
                    return true;
                }
                break;
            }
            else{
                temp_sq+=offset;
            }
        }
    }

    return false;
}

void Board::clearPiece(const int from){
    int piece = board[from];
    board[from]=Empty;
    for(int i=1;i<=numOfPieces[piece];i++)
    {
        if(pieceList[piece][i]==from)
        {
            pieceList[piece][i]=pieceList[piece][numOfPieces[piece]];
            numOfPieces[piece]--;
        }
    }
}
void Board::addPiece(const int to,const int piece)
{
    board[to]=piece;

    pieceList[piece][++numOfPieces[piece]]=to;

}
void Board::movePiece(const int from,const int to){
    int piece = board[from];

    board[to] = board[from];
    board[from]= Empty;

    for(int i=1;i<=numOfPieces[piece];i++)
    {
        if(pieceList[piece][i]==from)
        {
            pieceList[piece][i] = to;
        }
    }
}

void Board::makeMove(int move){

    const int from = getMoveFrom(move);
    const int to = getMoveTo(move);
    const int enPassant = getMoveEnPassant(move);
    const int castle = getMoveCastle(move);
    const int dbPawn = getMoveDbPawn(move);
    const int capturePiece = getMoveCapture(move);
    const int promotedPiece = getMovePromoted(move);

    history[historyPly].move = move;
    history[historyPly].castlingRights = castlingRights;
    history[historyPly].enPassant = enPassantSq;
    history[historyPly].fiftyMove = fiftyMove;
    history[historyPly].posKey = pos;

    historyPly++;
    ply++;

    castlingRights &= castlePerms[from];
    castlingRights &= castlePerms[to];

    if(castle)
    {
        if(castle&WKCA)
        {
            movePiece(H1,F1);
        }
        else if(castle&WQCA)
        {
            movePiece(A1,D1);
        }
        else if(castle&BKCA)
        {
            movePiece(H8,F8);
        }
        else if(castle&BQCA)
        {
            movePiece(A8,D8);
        }
    }

    if(capturePiece)
    {
        clearPiece(to);
    }

    if(dbPawn)
    {
        if(turn==white)
        {
            enPassantSq = from -10;
        }
        else{
            enPassantSq = from +10;
        }
    }
    else{
        enPassantSq = Offboard;
    }


    if(enPassant)
    {
        if(turn==white)
        {
            clearPiece(to+10);
        }
        else{
            clearPiece(to-10);
        }
    }

    movePiece(from,to);

    if(promotedPiece)
    {
        clearPiece(to);
        addPiece(to,promotedPiece);
    }
    turn=turn==white?black:white;


}
void Board::unmakeMove(){
    historyPly--;
    ply--;

    const int move  = history[historyPly].move;
    const int from = getMoveFrom(move);
    const int to = getMoveTo(move);
    const int enPassant = getMoveEnPassant(move);
    const int castle = getMoveCastle(move);
    const int capturePiece = getMoveCapture(move);
    const int promotedPiece = getMovePromoted(move);



    if(castle)
    {
        if(castle&WKCA)
        {
            movePiece(F1,H1);
        }
        else if(castle&WQCA)
        {
            movePiece(D1,A1);
        }
        else if(castle&BKCA)
        {
            movePiece(F8,H8);
        }
        else if(castle&BQCA)
        {
            movePiece(D8,A8);
        }
    }



    if(promotedPiece)
    {
        clearPiece(to);
        if(turn==white)
        {
            addPiece(to,blackPawn);
        }
        else{
            addPiece(to,whitePawn);
        }
    }
    if(enPassant)
    {
        if(turn==white)
        {
            addPiece(to-10,whitePawn);
        }
        else{
            addPiece(to+10,blackPawn);
        }
    }
    movePiece(to,from);
    if(capturePiece&&!enPassant)
    {
        addPiece(to,capturePiece);
    }

    castlingRights = history[historyPly].castlingRights;
    enPassantSq = history[historyPly].enPassant;
    pos = history[historyPly].posKey;
    fiftyMove = history[historyPly].fiftyMove;


    turn=turn==white?black:white;
}


void Board::printBoard()
{
    for(int i=0;i<8;i++)
    {
        cout<<"+---";
    }
    cout<<"+"<<endl;

    for(int rnk=0;rnk<8;rnk++)
    {

        for(int file=0;file<8;file++)
        {
            int sq120 = fileRankToSq120(file,rnk);

            Piece piece = static_cast<Piece>(board[sq120]);

            char pieceChar = pieceToChar.at(piece);
            cout<<"| "<<pieceChar<<" ";

        }
        cout<<"| "<<8-rnk<<" "<<endl;

        for(int i=0;i<8;i++)
        {
            cout<<"+---";
        }
        cout<<"+"<<endl;
    }
    for(char c= 'a';c<='h';c++)
    {
        cout<<"  "<<c<<" ";
    }
    cout<<endl;
}
void Board::clearBoard()
{
    for(int i=0;i<120;i++)board[i]=121;

    for(int i=0;i<64;i++)
    {
        int sq120 = sq64to120[i];
        board[sq120]= Empty;
    }
    for(int i=Empty;i<=blackKing;i++)numOfPieces[i]=0;
}
void Board::parseFen(string fen)
{
    clearBoard();

    istringstream iss(fen);
    vector<string> parts;
    string part;
    while (std::getline(iss, part, ' ')) {
        parts.push_back(part);
    }

    int idx = 0;
    for(int i=0;i<parts[0].length();i++)
    {
        if(fen[i]==' ')break;

        if(fen[i]=='/')continue;

        auto it = charToPiece.find(fen[i]);
        if(it == charToPiece.end())
        {
            char c = fen[i];
            int temp = int(c-48);
            idx+=temp;
        }
        else {
            int piece = it->second;
            int sq120 = sq64to120[idx];

            board[sq120]=piece;


            pieceList[piece][++numOfPieces[piece]]= sq120;

            idx++;
        }
    }
    turn = parts[1][0]=='w'?white:black;

    //castling rights
    castlingRights = 0;
    for(int i=0;i<parts[2].length();i++)
    {
        if(parts[2][i]=='K')castlingRights+=WKCA;
        else if(parts[2][i]=='Q')castlingRights+=WQCA;
        else if(parts[2][i]=='k')castlingRights+=BKCA;
        else if(parts[2][i]=='q')castlingRights+=BQCA;
    }

    fiftyMove = int(parts[4][0])*2;


}
void Board::printPieceLists(){
     for(int i=1;i<=12;i++)
    {
        for(int j=1;j<=numOfPieces[i];j++)
        {
            cout<<pieceList[i][j]<<" ";
        }
        cout<<endl;
    }
}
