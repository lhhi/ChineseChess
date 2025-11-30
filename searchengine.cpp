#include "searchengine.h"
#include"chessboard.h"
#include"chesspiece.h"
#include<cmath>
#include<vector>
#define RED 0
#define BLACK 1

SearchEngine::SearchEngine() {}

Chesspiece* SearchEngine::Makemove(ChessBoard& w,moveway& move){
    Chesspiece *p=w.pieces[move.to_x][move.to_y];
    w.board[move.to_x][move.to_y]=w.board[move.from_x][move.from_y];
    w.pieces[move.to_x][move.to_y]=w.pieces[move.from_x][move.from_y];
    w.pieces[move.to_x][move.to_y]->x = move.to_x;
    w.pieces[move.to_x][move.to_y]->y = move.to_y;
    w.board[move.from_x][move.from_y]=0;
    w.pieces[move.from_x][move.from_y]=NULL;
    return p;
}

void SearchEngine::Unmakemove(ChessBoard& w,moveway& move,Chesspiece *p){
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
    if (isGameover(w)) return isMAX?(ISREDWIN?19990+2*deep:-19990-2*deep):(ISREDWIN?-19990-2*deep:19990+2*deep);
    if(deep==0) return Evalute::evalute(w,!isMAX);
    std::vector<moveway> movelist=chessmove::createpossiblemove(w,!isMAX);
    if(movelist.empty()) return Evalute::evalute(w,!isMAX);
    for(moveway move:movelist){
        Chesspiece*p=Makemove(w,move);
        int eval=-search(w,deep-1,-beta,-alpha,!isMAX);
        Unmakemove(w,move,p);
        alpha=std::max(eval,alpha);
        if(beta<=alpha) break;
    }
    return alpha;
}

moveway SearchEngine::aimode(ChessBoard& w,int deep,int alpha,int beta,bool isMAX){
    std::vector<moveway> movelist=chessmove::createpossiblemove(w,!isMAX);
    moveway bestmove;
    for(moveway move:movelist){
        Chesspiece*p=Makemove(w,move);
        int eval=-search(w,deep-1,-beta,-alpha,!isMAX);
        //int eval=-PVSsearch(w,deep-1,-beta,-alpha,!isMAX);
        Unmakemove(w,move,p);
        if(eval>alpha){
            alpha=eval;
            bestmove=move;
        }
        if(beta<=alpha) break;
    }
    return bestmove;
}

int SearchEngine::PVSsearch(ChessBoard& w,int deep,int alpha,int beta,bool isMAX){
    if (isGameover(w)) return isMAX?(ISREDWIN?19990+2*deep:-19990-2*deep):(ISREDWIN?-19990-2*deep:19990+2*deep);
    if(deep==0) return Evalute::evalute(w,!isMAX);
    std::vector<moveway> movelist=chessmove::createpossiblemove(w,!isMAX);
    if(movelist.empty()) return Evalute::evalute(w,!isMAX);
    int bestEval=-20000,score;
    Chesspiece*p=Makemove(w,movelist[0]);
    bestEval=-PVSsearch(w,deep-1,-beta,-alpha,!isMAX);
    Unmakemove(w,movelist[0],p);
    for(int i=1;i<(int)movelist.size();i++){
        if(bestEval<beta){
            if(bestEval>alpha) alpha=bestEval;
            Chesspiece* p=Makemove(w,movelist[i]);
            score=-PVSsearch(w,deep-1,-alpha-1,-alpha,!isMAX);
            if(score>alpha&&score<beta){
                bestEval=-PVSsearch(w,deep-1,-beta,-score,!isMAX);
            }else if(score>bestEval){
                bestEval=score;
            }
            Unmakemove(w,movelist[i],p);
        }
    }
    return bestEval;
}
