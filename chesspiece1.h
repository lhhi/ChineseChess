#ifndef CHESSPIECE1_H
#define CHESSPIECE1_H
#include"chesspiece.h"

class chesspiece1:public Chesspiece
{
public:
    chesspiece1();
    bool Canmove(ChessBoard&,int ,int);
    void generate_move(std::vector<moveway>&,ChessBoard& w);
};

#endif // CHESSPIECE1_H
