#include "chesspiece1.h"
#include"chessboard.h"
#include"chessmove.h"

chesspiece1::chesspiece1() {}

 bool chesspiece1::Canmove(ChessBoard &w,int board_x,int board_y){
     int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
     if(board_x<0||board_x>9||board_y<0||board_y>8) return false;
     if(color==0){
         if(board_x<0||board_x>2||board_y<3||board_y>5) return false;
         if(w.board[board_x][board_y]==0||w.pieces[board_x][board_y]->color!=color){
             for(int i=0;i<4;i++){
                 int dx=this->x+dir[i][0];
                 int dy=this->y+dir[i][1];
                 if(dx==board_x&&dy==board_y) return true;
             }
         }
         return false;
     }else if(color==1){
         if(board_x<7||board_x>9||board_y<3||board_y>5) return false;
         if(w.board[board_x][board_y]==0||w.pieces[board_x][board_y]->color!=color){
             for(int i=0;i<4;i++){
                 int dx=this->x+dir[i][0];
                 int dy=this->y+dir[i][1];
                 if(dx==board_x&&dy==board_y) return true;
             }
         }
         return false;
     }
}

 void chesspiece1::generate_move(std::vector<moveway>& move,ChessBoard& w){
     int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
     for(int i=0;i<4;i++){
         int dx=this->x+dir[i][0];
         int dy=this->y+dir[i][1];
         if(Canmove(w,dx,dx)) chessmove::moveadd(move,x,y,dx,dy);
     }
 }
