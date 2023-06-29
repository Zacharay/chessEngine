#include "board.h"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
Board::Board(string fen)
{
    parseFen(fen);
}
void Board::clearPiece(const int from,const int piece){
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
void Board::movePiece(const int from,const int to,int piece){
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

    movePiece(from,to,board[from]);

    if(capturePiece)
    {
        clearPiece(to,capturePiece);
    }
    if(promotedPiece)
    {

    }



}
void Board::unmakeMove(int move){}


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
        if(parts[2][i]=='K')castlingRights+=8;
        else if(parts[2][i]=='Q')castlingRights+=4;
        else if(parts[2][i]=='k')castlingRights+=2;
        else if(parts[2][i]=='q')castlingRights+=1;
    }

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
