#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QWidget>
#include"chessboard.h"
#include"chessmove.h"

class Chesspiece : public QWidget
{
    Q_OBJECT
public:
    explicit Chesspiece(QWidget *parent = nullptr);
    int x,y,color,id;//棋子的坐标,颜色,和类型
    virtual bool Canmove(ChessBoard&,int ,int)=0;//判断移动位置是否合法
    virtual void generate_move(std::vector<moveway> &,ChessBoard& w)=0;
signals:
};

#endif // CHESSPIECE_H

