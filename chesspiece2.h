#ifndef CHESSPIECE2_H
#define CHESSPIECE2_H
#include"chesspiece.h"

class chesspiece2:public Chesspiece
{
public:
    chesspiece2();
    bool Canmove(ChessBoard&,int ,int);
    void generate_move(std::vector<moveway>&,ChessBoard& w);
};


#endif // CHESSPIECE2_H
