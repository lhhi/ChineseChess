#include "searchengine.h"
#include"chessboard.h"
#include"chesspiece.h"
#include"hashtable.h"
#include<cmath>
#include<vector>
#define RED 0
#define BLACK 1
#define UNVALID 66666
SearchEngine::SearchEngine() {}

Chesspiece* SearchEngine::Makemove(ChessBoard& w,moveway& move,int turn){
    Chesspiece *p=w.pieces[move.to_x][move.to_y];
    w.board[move.to_x][move.to_y]=w.board[move.from_x][move.from_y];
    w.pieces[move.to_x][move.to_y]=w.pieces[move.from_x][move.from_y];
    w.pieces[move.to_x][move.to_y]->x = move.to_x;
    w.pieces[move.to_x][move.to_y]->y = move.to_y;
    w.board[move.from_x][move.from_y]=0;
    w.pieces[move.from_x][move.from_y]=NULL;
    return p;
}

void SearchEngine::Unmakemove(ChessBoard& w,moveway& move,Chesspiece *p,int turn){
    w.board[move.from_x][move.from_y]=w.board[move.to_x][move.to_y];
    w.pieces[move.from_x][move.from_y]=w.pieces[move.to_x][move.to_y];
    w.pieces[move.from_x][move.from_y]->x = move.from_x;
    w.pieces[move.from_x][move.from_y]->y = move.from_y;
    if(p){
        w.board[move.to_x][move.to_y]=p->id;
        w.pieces[move.to_x][move.to_y]=p;
        p->x=move.to_x; p->y=move.to_y;
    }else{
        w.board[move.to_x][move.to_y]=0;
        w.pieces[move.to_x][move.to_y]=NULL;
    }
}

bool SearchEngine::isGameover(ChessBoard& w){
    bool redlive=false,blacklive=false;
    for(int i=0;i<3;i++){
        for(int j=3;j<=5;j++){
            if(w.board[i][j]==1) redlive=true;
            if(w.board[i][j]==8) blacklive=true;
        }
    }
    for(int i=7;i<=9;i++){
        for(int j=3;j<=5;j++){
            if(w.board[i][j]==1) redlive=true;
            if(w.board[i][j]==8) blacklive=true;
        }
    }
    if(redlive==false)   ISREDWIN=false;
    if(blacklive==false) ISREDWIN=true;
    return !(redlive&&blacklive);
}

int SearchEngine::search(ChessBoard& w,int deep,int alpha,int beta,bool isMAX){
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
}

moveway SearchEngine::aimode(ChessBoard& w,int deep,int alpha,int beta,bool isMAX){
    std::vector<moveway> movelist=chessmove::createpossiblemove(w,!isMAX);
    moveway bestmove;
    for(moveway move:movelist){
        Chesspiece*p=Makemove(w,move,!isMAX);
        int eval=-search(w,deep-1,-beta,-alpha,!isMAX);
        Unmakemove(w,move,p,!isMAX);
        if(eval>alpha){
            alpha=eval;
            bestmove=move;
        }
        if(beta<=alpha) break;
    }
    return bestmove;
}

int SearchEngine::PVSsearch(ChessBoard& w,int deep,int alpha,int beta,bool isMAX){
    if (isGameover(w)) return isMAX?(ISREDWIN?20000:-20000):(ISREDWIN?-20000:20000);
    if(deep==0) return Evalute::evalute(w,!isMAX);
    std::vector<moveway> movelist=chessmove::createpossiblemove(w,!isMAX);
    if(movelist.empty()) return Evalute::evalute(w,!isMAX);
    int bestEval=-20000,score;
    Chesspiece*p=Makemove(w,movelist[0],!isMAX);
    bestEval=-PVSsearch(w,deep-1,-beta,-alpha,!isMAX);
    Unmakemove(w,movelist[0],p,!isMAX);
    for(int i=1;i<(int)movelist.size();i++){
        if(bestEval<beta){
            if(bestEval>alpha) alpha=bestEval;
            Chesspiece* p=Makemove(w,movelist[i],!isMAX);
            score=-PVSsearch(w,deep-1,-alpha-1,-alpha,!isMAX);
            if(score>alpha&&score<beta){
                bestEval=-PVSsearch(w,deep-1,-beta,-score,!isMAX);
            }else if(score>bestEval){
                bestEval=score;
            }
            Unmakemove(w,movelist[i],p,!isMAX);
        }
    }
    return bestEval;
}
