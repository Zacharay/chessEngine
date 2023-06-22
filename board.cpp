#include "board.h"
#include <iostream>
Board::Board(string fen)
{
    for(int i=0;i<120;i++)board[i]=121;

    for(int i=0;i<64;i++)
    {
        int sq120 = sq64to120[i];
        board[sq120]= Empty;
    }

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
            int sq120 = sq64to120[idx];
            board[sq120]=piece;

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
