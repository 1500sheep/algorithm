//
// Created by jameskang on 18. 4. 4.
//
#include <iostream>
#include <algorithm>
#include <vector>

#define SIZE 20
using namespace std;

int map[SIZE][SIZE];
int arr_k[1000];
int dice[5];
int n,M,K,x,y;

void move(int index){
    int temp;
    if(index==1){
        temp = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[3];
        dice[3] = dice[5];
        dice[5] = temp;
    }else if(index==2){
        temp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = dice[4];
        dice[4] = temp;
    }else if(index==3){
        temp = dice[0];
        for(int i=0;i<3;i++){
            dice[i] = dice[i+1];
        }
        dice[3] = temp;
    }else if(index==4){
        temp = dice[3];
        for(int i=3;i>0;i--){
            dice[i] = dice[i-1];
        }
        dice[0] = temp;
    }
}

int main(){
    scanf("%d %d %d %d %d",&n,&M,&x,&y,&K);
    for(int i=0;i<n;i++)
        for(int j=0;j<M;j++)
            scanf("%d",&map[i][j]);

    for(int i=0;i<K;i++){
        scanf("%d",&arr_k[i]);
    }
    int N;
    N = n;
    int move_dice,row,col;
    int floor = 3;
    int top = 1;
    for(int i=0;i<K;i++){
        row=0;
        col=0;
        move_dice = arr_k[i];
        if(move_dice==1){
            col =1;
        }else if(move_dice==2){
            col = -1;
        }else if(move_dice==3){
            row=-1;
        }else if(move_dice==4){
            row=1;
        }
        if((x+row) >=N || (y+col)>=M || x+row<0 || y+col<0)
            continue;

        x+=row;y+=col;

        move(move_dice);
        if(!map[x][y]){
            map[x][y] = dice[floor];
        }else{
            dice[floor] = map[x][y];
            map[x][y] =0;
        }
        cout<<dice[top]<<endl;
    }


    return 0;
}
