//
// Created by jameskang on 18. 4. 2.
//
#include <iostream>
#include <vector>
#include <cmath>

#define SIZE 20
using namespace std;

int arr[20001][20001];
int V,E,start;

int dfs(){
    int cnt = 0;
    return cnt;
}
int main(){
    scanf("%d %d %d",&V,&E,&start);
    for(int i=0;i<E;i++){
        int x,y,weight;
        scanf("%d %d %d",&x,&y,&weight);
        arr[x][y]=weight;
    }
    for(int i=1;i<=V;i++){
        if(i==start){
            printf("0\n");
            continue;
        }
        int result = dfs();
        if(result){
            printf("%d\n",result);
        }else{
            printf("INF\n");
        }

    }
    return 0;
}
