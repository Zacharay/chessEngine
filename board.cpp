#include "board.h"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
Board::Board(string fen)
{
    parseFen(fen);
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
        if(parts[2][i]=='K')castlingRights+=8;
        else if(parts[2][i]=='Q')castlingRights+=4;
        else if(parts[2][i]=='k')castlingRights+=2;
        else if(parts[2][i]=='q')castlingRights+=1;
    }

}
const int * Board::getBoard()const{
    return board;
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
