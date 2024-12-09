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

/*int SearchEngine::search(ChessBoard& w,int deep,int alpha,int beta,bool isMAX){
    int score=hash.query(deep,isMAX);
    if(score!=UNVALID) return score;
    if (isGameover(w)) return isMAX?(ISREDWIN?20000:-20000):(ISREDWIN?-20000:20000);
    if(deep==0){
        score=Evalute::evalute(w,!isMAX);
        hash.insert(score,deep,isMAX);
        return score;
    }
    std::vector<moveway> movelist=chessmove::createpossiblemove(w,!isMAX);
    if(movelist.empty()) return Evalute::evalute(w,!isMAX);
    for(moveway move:movelist){
        int target=hash.makehash(w,move);
        Chesspiece*p=Makemove(w,move,!isMAX);
        int eval=-PVSsearch(w,deep-1,-beta,-alpha,!isMAX);
        hash.insert(eval,deep,isMAX);
        hash.unmakehash(w,move,target);
        Unmakemove(w,move,p,!isMAX);
        alpha=std::max(eval,alpha);
        if(beta<=alpha) break;
    }
    return alpha;
}*/
