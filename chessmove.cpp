#include "chessmove.h"
#include"chessboard.h"
#include"chesspiece.h"

chessmove::chessmove() {

}
//添加走法
void chessmove::moveadd(std::vector<moveway> &move,int from_x,int from_y,int to_x,int to_y){
    moveway p(from_x,from_y,to_x,to_y);
    move.insert(move.end(),p);
}
//产生走法
std::vector<moveway> chessmove::createpossiblemove(ChessBoard& w,int side){
    std::vector<moveway> move;
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            if(w.board[i][j]!=0){
                if(w.pieces[i][j]->color!=side) continue;
                w.pieces[i][j]->generate_move(move,w);
            }
        }
    }
    return move;
}
