#include "hashtable.h"
#include<cmath>
#include<ctime>
#define UNVALID 66666
#define ll long long
Hashtable::Hashtable() {
    init();
}

long long rand64(){
    return rand()^((ll)rand()<<15)^((ll)rand()<<30)^((ll)rand()<<45)^((ll)rand()<<60);
}

int rand32(){
    return rand()^((int)rand()<<15)^((int)rand()<<30);
}

void Hashtable::init(){
    srand(time(0));
    for(int i=0;i<15;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<9;k++){
                hashkey32[i][j][k]=rand32();
                hashkey64[i][j][k]=rand64();
            }
        }
    }
    table[0]=new Hashitem[1024*1024];
    table[1]=new Hashitem[1024*1024];
}

void Hashtable::gethash(ChessBoard& w){
    int id;
    Hashkey32=0;
    Hashkey64=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            id=w.board[i][j];
            if(id==0) continue;
            Hashkey32^=hashkey32[id][i][j];
            Hashkey64^=hashkey64[id][i][j];
        }
    }
}

int Hashtable::makehash(ChessBoard& w,moveway move){
    int id,target;
    id=w.board[move.from_x][move.from_y];
    target=w.board[move.to_x][move.to_y];
    Hashkey32^=hashkey32[id][move.from_x][move.from_y];
    Hashkey64^=hashkey64[id][move.from_x][move.from_y];
    if(target!=0){
        Hashkey32^=hashkey32[target][move.to_x][move.to_y];
        Hashkey64^=hashkey64[target][move.to_x][move.to_y];
    }
    Hashkey32^=hashkey32[id][move.to_x][move.to_y];
    Hashkey64^=hashkey64[id][move.to_x][move.to_y];
    return target;
}

void Hashtable::unmakehash(ChessBoard&w,moveway move,int target){
    int id;
    id=w.board[move.from_x][move.from_y];
    Hashkey32^=hashkey32[id][move.from_x][move.from_y];
    Hashkey64^=hashkey64[id][move.from_x][move.from_y];
    Hashkey32^=hashkey32[id][move.to_x][move.to_y];
    Hashkey64^=hashkey64[id][move.to_x][move.to_y];
    if(target!=0){
        Hashkey32^=hashkey32[target][move.to_x][move.to_y];
        Hashkey64^=hashkey64[target][move.to_x][move.to_y];
    }
}

int Hashtable::query(int deep,bool isMAX){
    Hashitem *hash;
    int x=Hashkey32&0xFFFFF;
    hash=&table[!isMAX][x];
    if(hash->deep>=deep&&hash->checksum==Hashkey64) return hash->hashvlue;
    return UNVALID;
}


void Hashtable::insert(int eval,int deep,bool isMAX){
    Hashitem *hash;
    int x=Hashkey32&0xFFFF;
    hash=&table[isMAX][x];
    hash->checksum=Hashkey64;
    hash->hashvlue=eval;
    hash->deep=deep;
}















