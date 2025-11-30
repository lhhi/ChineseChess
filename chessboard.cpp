#include "chessboard.h"
#include<QPaintEvent>
#include<QPainter>
#include<QDir>
#include "chessmove.h"
#include"chesspiece1.h"
#include"chesspiece2.h"
#include"chesspiece3.h"
#include"chesspiece4.h"
#include"chesspiece5.h"
#include"chesspiece6.h"
#include"chesspiece7.h"
#include"searchengine.h"


ChessBoard::ChessBoard(QWidget *parent)
    : QMainWindow{parent}
{
    this->resize(530,600);//设置显示区域的大小
    init();//初始化棋盘
}

void ChessBoard::init(){
    ai_pre=true;
    for(int i=0;i<10;i++)
    for(int j=0;j<9;j++)
    board[i][j]=board_1[i][j];
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            int id=board[i][j];
            if(id==0){ pieces[i][j]=NULL;continue; }
            pieces[i][j]=getpiece(id);
            pieces[i][j]->x=i;
            pieces[i][j]->y=j;
            pieces[i][j]->id=id;
            if(id>0&&id<=7) pieces[i][j]->color=RED;
            if(id>7&&id<=14) pieces[i][j]->color=BLACK;//获取棋子并设置初始值
        }
    }
}//棋盘的初始化

//上锁
inline void ChessBoard::unlock(){ flag=0; selected_piece=NULL;}

//解锁
inline void ChessBoard::lock(Chesspiece* p){ selected_piece=p; flag=1;}

//获取棋子函数
Chesspiece *ChessBoard::getpiece(int id){
    Chesspiece *p=NULL;
    switch (id) {
    case 8:
    case 1: p= new chesspiece1; break;
    case 9:
    case 2: p= new chesspiece2; break;
    case 10:
    case 3: p= new chesspiece3; break;
    case 11:
    case 4: p= new chesspiece4; break;
    case 12:
    case 5: p= new chesspiece5; break;
    case 13:
    case 6: p= new chesspiece6; break;
    case 14:
    case 7: p= new chesspiece7; break;
    }
    return p;
}

//绘制事件
void ChessBoard::paintEvent(QPaintEvent  *ev){
    QPainter painter(this);
    drawBoard(painter);
    drawChess(painter);
}

//绘制棋盘
void ChessBoard::drawBoard(QPainter &painter){
    QString path = QDir::currentPath() + "/images/WOOD.JPG";
    painter.drawPixmap(0,20,521,577,QPixmap(path));
}

//绘制棋子
void ChessBoard::drawChess(QPainter &painter){
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            int x=start_x+j*57;
            int y=start_y+i*57;
            if(board[i][j]>0){
                //1-7 为红 8-14为黑
                switch (board[i][j]) {
                case 8:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RK.GIF"));
                    break;
                case 9:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RR.GIF"));
                    break;
                case 10:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RN.GIF"));
                    break;
                case 11:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RC.GIF"));
                    break;
                case 12:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RA.GIF"));
                    break;
                case 13:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RB.GIF"));
                    break;
                case 14:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RP.GIF"));
                    break;
                case 1:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BK.GIF"));
                    break;
                case 2:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BR.GIF"));
                    break;
                case 3:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BN.GIF"));
                    break;
                case 4:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BC.GIF"));
                    break;
                case 5:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BA.GIF"));
                    break;
                case 6:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BB.GIF"));
                    break;
                case 7:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BP.GIF"));
                    break;
                case 22:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RKS.GIF"));
                    break;
                case 23:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RRS.GIF"));
                    break;
                case 24:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RNS.GIF"));
                    break;
                case 25:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RCS.GIF"));
                    break;
                case 26:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RAS.GIF"));
                    break;
                case 27:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RBS.GIF"));
                    break;
                case 28:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/RPS.GIF"));
                    break;
                case 15:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BKS.GIF"));
                    break;
                case 16:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BRS.GIF"));
                    break;
                case 17:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BNS.GIF"));
                    break;
                case 18:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BCS.GIF"));
                    break;
                case 19:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BAS.GIF"));
                    break;
                case 20:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BBS.GIF"));
                    break;
                case 21:
                    painter.drawPixmap(x,y,radius*2,radius*2,QPixmap(QDir::currentPath()+"/images/WOOD/BPS.GIF"));
                    break;

                }
            }
       }
    }
}

//鼠标点击事件
void ChessBoard::mousePressEvent(QMouseEvent *event){
    SearchEngine ai;
    int real_x=event->x(),real_y=event->y();
    int board_y=(real_x-start_x)/57,board_x=(real_y-start_y)/57;
    if(ai_pre){
        moveway bestmove=ai.aimode(*this,3,-20000,20000,true);
        move(pieces[bestmove.from_x][bestmove.from_y],bestmove.to_x,bestmove.to_y);
        ai_pre=false;
    }else{
        if(flag==1&&pieces[board_x][board_y]!=selected_piece){
            if(move(selected_piece,board_x,board_y)){
                unlock();
                if(ai.isGameover(*this)){ init(); update(); return ; }
                moveway bestmove=ai.aimode(*this,3,-20000,20000,true);
                move(pieces[bestmove.from_x][bestmove.from_y],bestmove.to_x,bestmove.to_y);
                if(ai.isGameover(*this)){ init(); update(); return ; }
            }
            return ;
        }else if(board[board_x][board_y]>0&&pieces[board_x][board_y]->color==BLACK){
            if(board[board_x][board_y]<=14) {
                board[board_x][board_y]+=14;
                lock(pieces[board_x][board_y]);
            }else if(board[board_x][board_y]>14) {
                board[board_x][board_y]-=14;
                unlock();
            }
        }
    }
    update();
}

//棋子移动
bool ChessBoard::move(Chesspiece* piece,int board_x,int board_y){
    if(piece->Canmove(*this,board_x,board_y)){
        board[piece->x][piece->y]=0;
        pieces[piece->x][piece->y]=NULL;
        board[board_x][board_y]=piece->id;
        pieces[board_x][board_y]=piece;
        piece->x=board_x; piece->y=board_y;
        update();
        return true;
    }
    return false;
}
