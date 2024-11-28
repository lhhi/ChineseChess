#include"chesspiece3.h"
#include"chessboard.h"
#include"chessmove.h"

chesspiece3::chesspiece3() {}

bool chesspiece3::Canmove(ChessBoard &w,int board_x,int board_y){
    if(board_x<0||board_x>9||board_y<0||board_y>8) return false;
    int dir[8][2] = { {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2} };
    int block[8][2]={ {1,0},{1,0},{-1,0},{-1,0},{0,1},{0,1},{0,-1},{0,-1} };
    if(w.board[board_x][board_y]==0||w.pieces[board_x][board_y]->color!=color){
        for(int i=0;i<8;i++){
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

void chesspiece3::generate_move(std::vector<moveway>& move,ChessBoard& w){
    int dir[8][2] = { {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2} };
    for(int i=0;i<8;i++){
        int dx=this->x+dir[i][0];
        int dy=this->y+dir[i][1];
        if(Canmove(w,dx,dy)) chessmove::moveadd(move,this->x,this->y,dx,dy);
    }
}
