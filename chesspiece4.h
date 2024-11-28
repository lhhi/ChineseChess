#ifndef CHESSPIECE4_H
#define CHESSPIECE4_H
#include"chesspiece.h"

class chesspiece4:public Chesspiece
{
public:
    chesspiece4();
    bool Canmove(ChessBoard&,int ,int);
    void generate_move(std::vector<moveway>&,ChessBoard& w);

};


#endif // CHESSPIECE2_H

