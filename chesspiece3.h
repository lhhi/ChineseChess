#ifndef CHESSPIECE3_H
#define CHESSPIECE3_H
#include"chesspiece.h"

class chesspiece3:public Chesspiece
{
public:
    chesspiece3();
    bool Canmove(ChessBoard&,int ,int);
    void generate_move(std::vector<moveway>&,ChessBoard& w);
};


#endif // CHESSPIECE2_H

