#include "evalute.h"
#include<cstring>
#define RED_KING 1
#define BLA_KING 8
Evalute::Evalute() {}

int Evalute::evalute(ChessBoard& w,int turn){
    memset(unattack,0,sizeof(unattack));
    memset(unguared,0,sizeof(unguared));
    memset(chessval,0,sizeof(chessval));
    memset(positval,0,sizeof(positval));
    int id,target;
    //初始化
    for(int i = 0;i < 10; i++){
        for(int j = 0;j < 9; j++){
            if(w.board[i][j]==0) continue;
            id=w.pieces[i][j]->id;
            std::vector<moveway> points;
            w.pieces[i][j]->generate_move(points,w);
            for(moveway point:points){
                target=w.board[point.to_x][point.to_y];
                if(w.board[point.to_x][point.to_y]==0){
                    positval[i][j]++;
                }else{
                    if(w.pieces[point.to_x][point.to_y]->color==w.pieces[i][j]->color){
                        unguared[point.to_x][point.to_y]++;
                    }else{
                        unattack[point.to_x][point.to_y]++;
                        positval[i][j]++;
                        switch(target){
                            case RED_KING:
                                if(turn==BLACK) return 18888;
                                break;
                            case BLA_KING:
                                if(turn==RED) return 18888;
                                break;
                            default:
                                unattack[point.to_x][point.to_y]+=
                                (30+(values[target]-values[id])/10)/10;
                                break;
                        }
                    }
                }
            }
        }
    }//

    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            if(w.board[i][j]==0) continue;
            id=w.board[i][j];
            chessval[i][j]++;
            chessval[i][j]+=mobilityvalues[id]*positval[i][j];
            if(id==7) chessval[i][j]+=positionvalue[RED][i][j];
            if(id==14)chessval[i][j]+=positionvalue[BLACK][i][j];
        }
    }//

    int halfvalue;
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            if(w.board[i][j]==0) continue;
            id=w.board[i][j];
            halfvalue=values[id]/16;
            chessval[i][j]+=values[id];
            if(id<=7){
                if(unattack[i][j]){
                    if(turn==RED){
                        if(id==RED_KING) chessval[i][j]-=20;
                        else{
                            chessval[i][j]-=2*halfvalue;
                            if(unguared[i][j]) chessval[i][j]+=halfvalue;
                        }
                    }else{
                        if(id==RED_KING) return 18888;
                        chessval[i][j]-=10*halfvalue;
                        if(unguared[i][j]) chessval[i][j]+=9*halfvalue;
                    }
                    chessval[i][j]-=unattack[i][j];
                }else{
                    if(unguared[i][j]) chessval[i][j]+=5;
                }
            }else{
                if(unattack[i][j]){
                    if(turn==BLACK){
                        if(id==BLA_KING) chessval[i][j]-=20;
                        else{
                            chessval[i][j]-=2*halfvalue;
                            if(unguared[i][j]) chessval[i][j]+=halfvalue;
                         }
                    }else{
                        if(id==BLA_KING) return 18888;
                        chessval[i][j]-=10*halfvalue;
                        if(unguared[i][j]) chessval[i][j]+=9*halfvalue;
                    }
                    chessval[i][j]-=unattack[i][j];
                }else{
                    if(unguared[i][j]) chessval[i][j]+=5;
                }
            }
        }
    }//

    int redvalue=0,blackvalue=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            if(w.board[i][j]==0) continue;
            id=w.board[i][j];
            if(id<=7) redvalue+=chessval[i][j];
            else blackvalue+=chessval[i][j];
        }
    }
    if(turn==RED)  return redvalue-blackvalue;
    if(turn==BLACK)return blackvalue-redvalue;
}
