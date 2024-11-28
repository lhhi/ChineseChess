#include "chesspiece6.h"
#include"chessboard.h"
#include"chessmove.h"

chesspiece6::chesspiece6() {}

bool chesspiece6::Canmove(ChessBoard &w,int board_x,int board_y){
    if(board_x<0||board_x>9||board_y<0||board_y>8) return false;
    int dir[4][2] = { {2,2},{2,-2},{-2,2},{-2,-2} };
    int block[4][2]={ {1,1},{1,-1},{-1,1},{-1,-1} };
    if(color==0){
        if(board_x>4) return false;
        if(w.board[board_x][board_y]==0||w.pieces[board_x][board_y]->color!=color){
            for(int i=0;i<4;i++){
                int dx=this->x+dir[i][0];
                int dy=this->y+dir[i][1];
                int block_x=this->x+block[i][0];
                int block_y=this->y+block[i][1];
                if((dx==board_x&&dy==board_y)&&(w.board[block_x][block_y]==0)) return true;
            }
            return false;
        }
        return false;
    }else if(color==1){
        if(board_x<5) return false;
        if(w.board[board_x][board_y]==0||w.pieces[board_x][board_y]->color!=color){
            for(int i=0;i<4;i++){
                int dx=this->x+dir[i][0];
                int dy=this->y+dir[i][1];
                int block_x=this->x+block[i][0];
                int block_y=this->y+block[i][1];
                if((dx==board_x&&dy==board_y)&&(w.board[block_x][block_y]==0)) return true;
            }
            return false;
        }
        return false;
    }
}

void chesspiece6::generate_move(std::vector<moveway>& move,ChessBoard &w){
    int dir[4][2] = { {2,2},{2,-2},{-2,2},{-2,-2} };
    for(int i=0;i<4;i++){
        int dx=this->x+dir[i][0];
        int dy=this->y+dir[i][1];
        if(Canmove(w,dx,dx)) chessmove::moveadd(move,x,y,dx,dy);
    }
}
