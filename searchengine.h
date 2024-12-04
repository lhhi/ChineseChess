#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H
class ChessBoard;
class Chesspiece;
#include"chessmove.h"
#include"evalute.h"

class SearchEngine
{
public:
    SearchEngine();
    bool ISREDWIN=false;
    Chesspiece *Makemove(ChessBoard&,moveway& move,int);
    void Unmakemove(ChessBoard&,moveway& move,Chesspiece*,int);
    bool isGameover(ChessBoard&);
    int evaluate(ChessBoard&,int);
    int search(ChessBoard& w,int deep,int alpha,int beta,bool isMAX);
    int search1(ChessBoard& w,int deep,int alpha,int beta,bool isMAX);
    moveway aimode(ChessBoard& w,int deep,int,int,bool);
    void addpiece(ChessBoard& w,int id,int x,int y,int turn);
    void delpiece(ChessBoard& w,int id,int x,int y,int turn);
};

#endif // SEARCHENGINE_H
