#ifndef NEGMAXENGINE_H
#define NEGMAXENGINE_H
#include"searchengine.h"
#include"chessboard.h"

class Negmaxengine:public SearchEngine
{
public:
    Negmaxengine();
    void SearchaGoodmove();
    int NegaMAx(int);
};

#endif // NEGMAXENGINE_H
