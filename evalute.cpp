#include "evalute.h"
#include<cstring>

Evalute::Evalute() {}

/*int Evalute::evalute(ChessBoard& w,int turn){
    int redvalue=0,blackvalue=0;
    int basicvalue[2]={0,0};
    int mobilvalue[2]={0,0};
    int positvalue[2]={0,0};
    int relatvalue[2]={0,0};
    int id,side,target;
    memset(Relation,0,sizeof(Relation));
    for(int i = 0;i < 10; i++){
        for(int j = 0;j < 9; j++){
            if(w.board[i][j]==0) continue;
            id=w.pieces[i][j]->id;
            side=w.pieces[i][j]->color;
            if(w.pieces[i][j]->color==0){
                basicvalue[0]+=values[id];
                positvalue[0]+=positionvalue[id][i][j];
            }else{
                basicvalue[1]+=values[id];
                positvalue[1]+=positionvalue[id][i][j];
            }
            std::vector<moveway> points;
            w.pieces[i][j]->generate_move(points,w);
            for(moveway point:points){
                target=w.board[point.to_x][point.to_y];
                if(w.board[point.to_x][point.to_y]==0){
                    mobilvalue[side]+=mobilityvalues[id];
                }else if(w.pieces[point.to_x][point.to_y]->color!=side){
                    if(target==1){
                        if(turn==1){
                            return INT_MIN+10;
                        }else{
                            relatvalue[0]-=20;
                            continue;
                        }
                    }
                    if(target==8){
                        if(turn==0){
                            return INT_MIN+10;
                        }else{
                            relatvalue[1]-=20;
                            continue;
                        }
                    }
                    Relation[point.to_x][point.to_y].ID=target;
                    int count=Relation[point.to_x][point.to_y].AttackCount;
                    Relation[point.to_x][point.to_y].UnderAttack[count]=target;
                    Relation[point.to_x][point.to_y].AttackCount++;
                }else if(w.pieces[point.to_x][point.to_y]->color==side){
                    if(target==1||target==8) continue;
                    Relation[point.to_x][point.to_y].ID=target;
                    int count=Relation[point.to_x][point.to_y].GuardCount;
                    Relation[point.to_x][point.to_y].UnderGurad[count]=target;
                    Relation[point.to_x][point.to_y].GuardCount++;
                }
            }
        }
    }
    for(int i = 0;i < 10; i++){
        for(int j = 0;j < 9; j++){
            int attack,guard;
            attack=guard=0;
            int minattack=777,maxattack=0;
            int minguard=0,maxguard=777;
            int flagvalue=777;
            int unitvalue;
            if(Relation[i][j].ID==0) continue;
            id=Relation[i][j].ID;
            side=id>7?0:1;
            unitvalue=values[id]>>3;
            for(int k=0;k<Relation[i][j].AttackCount;k++){
                if(values[Relation[i][j].UnderAttack[i]]<values[id]&&
                    values[Relation[i][j].UnderAttack[i]]<flagvalue){
                    flagvalue=values[Relation[i][j].UnderAttack[i]];
                }
                if(values[Relation[i][j].UnderAttack[i]]<minattack)
                    minattack=values[Relation[i][j].UnderAttack[i]];
                if(values[Relation[i][j].UnderAttack[i]]>maxattack)
                    maxattack=values[Relation[i][j].UnderAttack[i]];
                attack+=values[Relation[i][j].UnderAttack[i]];
            }
            for(int k=0;k<Relation[i][j].GuardCount;k++){
                minguard=std::min(values[Relation[i][j].UnderGurad[i]],minguard);
                maxguard=std::max(values[Relation[i][j].UnderGurad[i]],maxguard);
                guard+=values[Relation[i][j].UnderGurad[i]];
            }
            if(attack==0) relatvalue[side]+=5*Relation[i][j].GuardCount;
            else{
                if()
            }


        }
    }


}*/
