#ifndef CHESSPIECE7_H
#define CHESSPIECE7_H
#include"chesspiece.h"

class chesspiece7:public Chesspiece
{
public:
    chesspiece7();
    bool Canmove(ChessBoard&,int ,int);
    void generate_move(std::vector<moveway>&,ChessBoard& w);
};

#endif // CHESSPIECE7_H
