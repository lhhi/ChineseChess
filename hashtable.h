#ifndef HASHTABLE_H
#define HASHTABLE_H
#include"chessboard.h"
#include"chessmove.h"

typedef struct HASH{
    long long checksum;
    int deep,hashvlue;
}Hashitem;

class Hashtable
{
public:
    Hashtable();
    void gethash(ChessBoard&);
    int makehash(ChessBoard&,moveway move);
    void unmakehash(ChessBoard&,moveway move,int);
    int query(int,bool);
    void insert(int,int,bool);
    void init();
    ulong hashkey64[15][10][9];
    uint hashkey32[15][10][9];
    uint Hashkey32;
    long long Hashkey64;
    Hashitem *table[2];
};

#endif // HASHTABLE_H
