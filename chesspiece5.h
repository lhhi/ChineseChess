#ifndef CHESSPIECE5_H
#define CHESSPIECE5_H
#include"chesspiece.h"


class chesspiece5:public Chesspiece
{
public:
    chesspiece5();
    bool Canmove(ChessBoard&,int ,int);
    void generate_move(std::vector<moveway>&,ChessBoard& w);

};

#endif // CHESSPIECE5_H
