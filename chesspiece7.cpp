#include "chesspiece7.h"
#include"chessmove.h"

chesspiece7::chesspiece7() {}

bool chesspiece7::Canmove(ChessBoard &w,int board_x,int board_y){
    if(board_x<0||board_x>9||board_y<0||board_y>8) return false;
    if(color==0){
        if(w.board[board_x][board_y]==0||w.pieces[board_x][board_y]->color!=color){
            if(this->x>=0&&this->x<=4){
                return ((board_x==this->x+1)&&(board_y==this->y));
            }else{
                int dir[3][2]={{1,0},{0,-1},{0,1}};
                for(int i=0;i<3;i++){
                    int dx=this->x+dir[i][0];
                    int dy=this->y+dir[i][1];
                    if(dx==board_x&&dy==board_y) return true;
                }
                return false;
            }
        }
        return false;
    }else if(color==1){
        if(w.board[board_x][board_y]==0||w.pieces[board_x][board_y]->color!=color){
            if(this->x>=5&&this->x<=9){
                return ((board_x==this->x-1)&&(board_y==this->y));
            }else{
                int dir[3][2]={{-1,0},{0,-1},{0,1}};
                for(int i=0;i<3;i++){
                    int dx=this->x+dir[i][0];
                    int dy=this->y+dir[i][1];
                    if(dx==board_x&&dy==board_y) return true;
                }
                return false;
            }
        }
        return false;
    }
}

void chesspiece7::generate_move(std::vector<moveway>& move,ChessBoard &w){
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    for(int i=0;i<4;i++){
        int dx=this->x+dir[i][0];
        int dy=this->y+dir[i][1];
        if(Canmove(w,dx,dy)) chessmove::moveadd(move,x,y,dx,dy);
    }
}
