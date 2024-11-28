#include"chesspiece4.h"
#include"chessboard.h"
#include"chessmove.h"

chesspiece4::chesspiece4() {}

bool chesspiece4::Canmove(ChessBoard &w,int board_x,int board_y){
    if(board_x<0||board_x>9||board_y<0||board_y>8) return false;
    if(w.board[board_x][board_y]==0){
        if(board_y==this->y){
            if(this->x<board_x){
                for(int i=this->x+1;i<board_x;i++){
                    if(w.board[i][y]!=0) return false;
                }
            }else{
                for(int i=board_x+1;i<this->x;i++){
                    if(w.board[i][y]!=0) return false;
                }
            }
            return true;
        }else if(board_x==this->x){
            if(this->y<board_y){
                for(int i=this->y+1;i<board_y;i++){
                    if(w.board[x][i]!=0) return false;
                }
            }else{
                for(int i=board_y+1;i<this->y;i++){
                    if(w.board[x][i]!=0) return false;
                }
            }
            return true;
        }
        return false;
    }else if(w.pieces[board_x][board_y]->color!=color){
        int count=0;
        if(board_y==this->y){
            if(this->x<board_x){
                for(int i=this->x+1;i<board_x;i++){
                    if(w.board[i][y]!=0) count++;
                }
            }else{
                for(int i=board_x+1;i<this->x;i++){
                    if(w.board[i][y]!=0) count++;
                }
            }
        }else if(board_x==this->x){
            if(this->y<board_y){
                for(int i=this->y+1;i<board_y;i++){
                    if(w.board[x][i]!=0) count++;
                }
            }else{
                for(int i=board_y+1;i<this->y;i++){
                    if(w.board[x][i]!=0) count++;
                }
            }
        }
        if(count==1) return true;
    }
    return false;
}

void chesspiece4::generate_move(std::vector<moveway>&move,ChessBoard& w){
    int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    for(int i=0;i<4;i++){
        int dx=this->x+dir[i][0];
        int dy=this->y+dir[i][1];
        while (Canmove(w,dx,dy)) {
            chessmove::moveadd(move,x,y,dx,dy);
            dx+=dir[i][0];
            dy+=dir[i][1];
        }
        dx+=dir[i][0];
        dy+=dir[i][1];
        while (Canmove(w,dx,dy)) {
            chessmove::moveadd(move,x,y,dx,dy);
            dx+=dir[i][0];
            dy+=dir[i][1];
        }
    }
}
