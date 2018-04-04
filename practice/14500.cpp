//
// Created by jameskang on 18. 4. 4.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define SIZE 500


int N,M;
int arr[SIZE][SIZE];
int dp[SIZE][SIZE];
int ans;
int hop;
queue<pair<int,int>> q;
int x,y;
void bfs(){
    q.push(make_pair(0,0));
    memset(dp,0,sizeof(dp));
    int temp;
    while(!q.empty()){
        hop = 0;
        temp =0;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(x>=N||y>=M)
            continue;
        if(dp[x][y])
            continue;
        dp[x][y] = 1;
        // 네모 케이스 하나임
        if(x+1<N&&y+1<M){
            temp = arr[x][y]+arr[x][y+1]+arr[x+1][y]+arr[x+1][y+1];
            hop = max(hop,temp);
        }
        // 스페이스 케이스 세로
        if(x+3<N){
            temp = arr[x][y]+arr[x+1][y]+arr[x+2][y]+arr[x+3][y];
            hop =max(hop,temp);
        }
        // 스페이스 케이스 가로
        if(y+3<M){
            temp = arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x][y+3];
            hop =max(hop,temp);
        }

        // 두개엇갈린거 케이스1
        if(x+2<N&&y+1<M){
            temp = arr[x][y]+arr[x+1][y]+arr[x+1][y+1]+arr[x+2][y+1];
            hop =max(hop,temp);
        }

        // 두개엇갈린거 케이스2
        if(x-1>=0&&y+2<M){
            temp = arr[x][y]+arr[x][y+1]+arr[x-1][y+1]+arr[x-1][y+2];
            hop =max(hop,temp);
        }

        // 두개엇갈린거 케이스3
        if(x+1<N&&y+2<M){
            temp = arr[x][y]+arr[x][y+1]+arr[x+1][y+1]+arr[x+1][y+2];
            hop =max(hop,temp);
        }

        // 두개엇갈린거 케이스4
        if(x-2>=0&&y+1<M){
            temp = arr[x][y]+arr[x-1][y]+arr[x-1][y+1]+arr[x-2][y+1];
            hop =max(hop,temp);
        }

        // 뻑큐 모양 1
        if(x+1<N&&y+2<M){
            temp = arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x+1][y+1];
            hop =max(hop,temp);
        }

        // 뻑큐 모양 2
        if(x-1>=0&&y+2<M){
            temp = arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x-1][y+1];
            hop =max(hop,temp);
        }

        // 뻑큐 모양 3
        if(x+2<N&&y+1<M){
            temp = arr[x][y]+arr[x+1][y]+arr[x+2][y]+arr[x+1][y+1];
            hop =max(hop,temp);
        }

        // 뻑큐 모양 4
        if(x+1<N&&x-1>=0&&y+1<M){
            temp = arr[x][y]+arr[x][y+1]+arr[x-1][y+1]+arr[x+1][y+1];
            hop =max(hop,temp);
        }

        // 세개 한개 모양 1
        if(x+2<N&&y+1<M){
            temp = arr[x][y]+arr[x+1][y]+arr[x+2][y]+arr[x+2][y+1];
            hop =max(hop,temp);
        }

        // 세개 한개 모양 2
        if(x-2>=0&&y+1<M){
            temp = arr[x][y]+arr[x][y+1]+arr[x-1][y+1]+arr[x-2][y+1];
            hop =max(hop,temp);
        }

        // 세개 한개 모양 3
        if(x+1<N&&y+2<M){
            temp = arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x+1][y+2];
            hop =max(hop,temp);
        }

        // 세개 한개 모양 4
        if(x-1>=0&&y+2<M){
            temp = arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x-1][y+2];
            hop =max(hop,temp);
        }

        // 세개 한개 모양 5
        if(x-1>=0&&y+2<M){
            temp = arr[x][y]+arr[x-1][y]+arr[x-1][y+1]+arr[x-1][y+2];
            hop =max(hop,temp);
        }

        // 세개 한개 모양 6
        if(x-1>=0&&y+2<M){
            temp = arr[x][y]+arr[x-1][y]+arr[x][y+1]+arr[x][y+2];
            hop =max(hop,temp);
        }

        // 세개 한개 모양 7
        if(x+2<N&&y+1<M){
            temp = arr[x][y]+arr[x+1][y]+arr[x+2][y]+arr[x][y+1];
            hop =max(hop,temp);
        }
        // 세개 한개 모양 8
        if(x+2<N&&y+1<M){
            temp = arr[x][y]+arr[x][y+1]+arr[x+1][y+1]+arr[x+2][y+1];
            hop =max(hop,temp);
        }
        if(hop>ans)
            ans = hop;
        q.push(make_pair(x,y+1));
        q.push(make_pair(x+1,y));
        q.push(make_pair(x+1,y+1));
    }
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%d",&arr[i][j]);

    bfs();

    printf("%d\n",ans);

    return 0;
}
