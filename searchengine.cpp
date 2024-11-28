#include "searchengine.h"
#include"chessboard.h"
#include"chesspiece.h"
#include<cmath>
#include<vector>
#define RED 0
#define BLACK 1

SearchEngine::SearchEngine() {}

void SearchEngine::addpiece(ChessBoard& w,int id,int x,int y,int turn){
    if(id<=7) w.redvalue+=positionvalue[id][x][y]+(!turn)*3;
    else       w.blackvalue+=positionvalue[id][x][y]+turn*3;
}

void SearchEngine::delpiece(ChessBoard& w,int id,int x,int y,int turn){
    if(id<=7) w.redvalue-=positionvalue[id][x][y]-(!turn)*3;
    else      w.blackvalue-=positionvalue[id][x][y]-turn*3;
}

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
    return !(redlive&&blacklive);
}

int SearchEngine::evaluate(ChessBoard &w,int turn){
    int redvalue=0,blackvalue=0;
    if(turn==RED) redvalue+=3;
    else blackvalue+=3;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 9; j++){
            if(w.board[i][j]==0) continue;
            int id=w.pieces[i][j]->id;
            if(id<=7) redvalue+=values[id]+positionvalue[id][i][j];
            else blackvalue+=values[id]+positionvalue[id][i][j];
        }
    }
    return redvalue-blackvalue;
}

int SearchEngine::search(ChessBoard& w,int deep,int alpha,int beta,bool isMAX){
    if(deep==0||isGameover(w)) return evaluate(w,!isMAX);
    std::vector<moveway> movelist=chessmove::createpossiblemove(w,!isMAX);
    if(movelist.empty()) return evaluate(w,!isMAX);
    if(isMAX){
        int maxEval=INT_MIN;
        for(moveway move:movelist){
            Chesspiece*p=Makemove(w,move);
            int eval=search(w,deep-1,alpha,beta,false);
            Unmakemove(w,move,p);
            maxEval=std::max(maxEval,eval);
            alpha=std::max(eval,alpha);
            if(beta<=alpha) break;
        }
        return maxEval;
    }else{
        int minEval=INT_MAX;
        for(moveway move:movelist){
            Chesspiece*p=Makemove(w,move);
            int eval=search(w,deep-1,alpha,beta,true);
            Unmakemove(w,move,p);
            minEval=std::min(minEval,eval);
            beta=std::min(eval,beta);
            if(beta<=alpha) break;
        }
        return minEval;
    }
}

moveway SearchEngine::aimode(ChessBoard& w,int deep){
    int bestscore=INT_MIN;
    moveway bestmove;
    std::vector<moveway> moves=chessmove::createpossiblemove(w,RED);
    for(moveway move:moves){
        Chesspiece* p=Makemove(w,move);
        int score=search(w,deep-1,INT_MIN,INT_MAX,false);
        Unmakemove(w,move,p);
        if(score>bestscore){
            bestscore=score;
            bestmove=move;
        }
    }
    return bestmove;
}
