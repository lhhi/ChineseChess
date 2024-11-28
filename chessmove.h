#ifndef CHESSMOVE_H
#define CHESSMOVE_H

#include "chessboard.h"
#include <vector>

// 定义 moveway 结构体
typedef struct moveway {
    moveway(){};
    moveway(int x0,int y0,int x1,int y1):from_x(x0),from_y(y0),to_x(x1),to_y(y1){};
    int from_x, from_y;
    int to_x, to_y;
    int score;
} moveway;


//extern moveway Movelist[8][80];

class chessmove {
public:
    chessmove();
    static void moveadd(std::vector<moveway>&,int,int,int,int);
    static std::vector<moveway> createpossiblemove(ChessBoard&,int);
};

#endif // CHESSMOVE_H
