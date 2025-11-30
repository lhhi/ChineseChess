#include "chesspiece1.h"
#include"chessboard.h"
#include"chessmove.h"

chesspiece1::chesspiece1() {}

 bool chesspiece1::Canmove(ChessBoard &w,int board_x,int board_y){
     int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
     if(board_x<0||board_x>9||board_y<0||board_y>8) return false;
     if(color==RED){
         if(w.box,y,dx,dy);
             }
         }
     }else{
         for(int i=0;i<3;i++){
             int dx=i;
             int dy=this->y;
             if(w.board[dx][dy]==1){
                 if(Canmove(w,dx,dy)) chessmove::moveadd(move,x,y,dx,dy);
             }
         }
     }
     for(int i=0;i<4;i++){ard[board_x][board_y]==8&&this->y==board_y){
             int flag=1;
             for(int i=this->x+1;i<board_x;i++){
                 if(w.board[i][this->y]!=0) flag=0;
             }
             if(flag==1) return true;
         }
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
         if(w.board[board_x][board_y]==1&&this->y==board_y){
             int flag=1;
             for(int i=this->x-1;i>board_x;i--){
                 if(w.board[i][this->y]!=0) flag=0;
             }
             if(flag==1) return true;
         }
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
         if(color==RED){
             for(int i=0;i<3;i++){
                 int dx=7+i;
                 int dy=this->y;
                 if(w.board[dx][dy]==8){
                     if(Canmove(w,dx,dy)) chessmove::moveadd(move,
         int dx=this->x+dir[i][0];
         int dy=this->y+dir[i][1];
         if(Canmove(w,dx,dy)) chessmove::moveadd(move,x,y,dx,dy);
     }
 }
