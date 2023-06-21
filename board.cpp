#include "board.h"
#include <iostream>
Board::Board(string fen)
{
    for(int i=0;i<64;i++)board[i]=None;

    int idx = 0;
    for(int i=0;i<fen.length();i++)
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
            uint8_t piece = it->second;
            board[idx]=piece;

            idx++;
        }


    }
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
            int sq = rnk*8+file;
            Piece piece = static_cast<Piece>(board[sq]);
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
