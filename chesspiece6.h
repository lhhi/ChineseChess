#ifndef CHESSPIECE6_H
#define CHESSPIECE6_H
#include"chesspiece.h"

class chesspiece6:public Chesspiece
{
public:
    chesspiece6();
    bool Canmove(ChessBoard&,int ,int);
    void generate_move(std::vector<moveway>&,ChessBoard& w);

};


#endif // CHESSPIECE6_H
