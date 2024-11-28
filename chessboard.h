#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QMainWindow>
#define RED 0
#define BLACK 1
const static int radius=28;
class Chesspiece;//前向声明
class ChessBoard : public QMainWindow
{
    Q_OBJECT
public:
    int board[10][9]={0};
    int board_1[10][9]={
        {2,3,6,5,1,5,6,3,2},
        {0,0,0,0,0,0,0,0,0},
        {0,4,0,0,0,0,0,4,0},
        {7,0,7,0,7,0,7,0,7},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {14,0,14,0,14,0,14,0,14},
        {0,11,0,0,0,0,0,11,0},
        {0,0,0,0,0,0,0,0,0,},
        {9,10,13,12,8,12,13,10,9}

    };//备份棋盘
    int redvalue,blackvalue;
    Chesspiece *pieces[10][9]={NULL};
    friend class Chesspiece;
    int flag,priority;//决定先手和棋子选择的变量
    Chesspiece *selected_piece;//当前被选中的棋子
    int start_x=4,start_y=26;//棋盘的开始坐标
    explicit ChessBoard(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);//绘制函数
    void drawBoard(QPainter &);//绘制棋盘
    void drawChess(QPainter &);//绘制棋子
    void mousePressEvent(QMouseEvent *);//鼠标点击事件
    Chesspiece* getpiece(int id);//获取一个棋子
    bool move(Chesspiece*,int,int);//移动棋子
    void init();//初始化函数
    inline void lock(Chesspiece *);
    inline void unlock();
signals:
};

#endif // CHESSBOARD_H
