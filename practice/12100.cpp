//
// Created by jameskang on 18. 4. 3.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define SIZE 20
using namespace std;

int arr[SIZE][SIZE];
int arr_temp[SIZE][SIZE];
int visit[SIZE][SIZE];

int N;
int ans;

void move_row_right(){
    for(int x=0;x<N;x++) {
        queue<int> q;
        int j;
        for (j = N - 2; j >= 0; j--) {
            if (arr[x][j]) {
                q.push(j);
            }
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            int i = 0;
            for (i = temp + 1; i < N; i++) {
                if (arr[x][i]) {
                    if (!visit[x][i] && arr[x][i] == arr[x][temp]) {
                        visit[x][i] = 1;
                        arr[x][i] *= 2;
                        arr[x][temp] = 0;
                        break;
                    }
                    if (i == temp + 1)
                        break;
                    arr[x][i - 1] = arr[x][temp];
                    arr[x][temp] = 0;
                    break;
                }

            }
            if (i == N) {
                arr[x][--i] = arr[x][temp];
                arr[x][temp] = 0;
            }
        }
    }
}

void move_row_left(){
    for(int x =0;x<N;x++) {
        queue<int> q;
        int j;
        for (j = 1; j < N; j++) {
            if (arr[x][j]) {
                q.push(j);
            }
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            int i = 0;
            for (i = temp - 1; i >= 0; i--) {
                if (arr[x][i]) {
                    if (!visit[x][i] && arr[x][i] == arr[x][temp]) {
                        visit[x][i] = 1;
                        arr[x][i] *= 2;
                        arr[x][temp] = 0;
                        break;
                    }
                    if (i == temp - 1)
                        break;
                    arr[x][i + 1] = arr[x][temp];
                    arr[x][temp] = 0;
                    break;
                }

            }
            if (i == -1) {
                arr[x][++i] = arr[x][temp];
                arr[x][temp] = 0;
            }
        }
    }
}

void move_row_up(){
    for(int y=0;y<N;y++) {
        queue<int> q;
        int i;
        for (i = 1; i < N; i++) {
            if (arr[i][y]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            i = 0;
            for (i = temp - 1; i >= 0; i--) {
                if (arr[i][y]) {
                    if (!visit[i][y] && arr[i][y] == arr[temp][y]) {
                        visit[i][y] = 1;
                        arr[i][y] *= 2;
                        arr[temp][y] = 0;
                        break;
                    }
                    if (i == temp - 1)
                        break;
                    arr[i + 1][y] = arr[temp][y];
                    arr[temp][y] = 0;
                    break;
                }

            }
            if (i == -1) {
                arr[++i][y] = arr[temp][y];
                arr[temp][y] = 0;
            }
        }
    }
}
void move_row_down(){
    for(int y=0;y<N;y++) {
        queue<int> q;
        int i;
        for (i = N - 2; i >= 0; i--) {
            if (arr[i][y]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            i = 0;
            for (i = temp + 1; i < N; i++) {
                if (arr[i][y]) {
                    if (!visit[i][y] && arr[i][y] == arr[temp][y]) {
                        visit[i][y] = 1;
                        arr[i][y] *= 2;
                        arr[temp][y] = 0;
                        break;
                    }
                    if (i == temp + 1)
                        break;
                    arr[i - 1][y] = arr[temp][y];
                    arr[temp][y] = 0;
                    break;
                }

            }
            if (i == N) {
                arr[--i][y] = arr[temp][y];
                arr[temp][y] = 0;
            }
        }
    }
}
queue<int> q2;
void dfs(int depth,int ar2[5]){

    if(depth==5){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                arr[i][j] = arr_temp[i][j];
        for(int i=0;i<depth;i++){
            memset(visit,0,sizeof(visit));
            if(ar2[i]==0){
                move_row_up();
            }else if(ar2[i]==1){
                move_row_down();
            }else if(ar2[i]==2){
                move_row_left();
            }else if(ar2[i]==3){
                move_row_right();
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(ans<arr[i][j])
                    ans = arr[i][j];
            }
        }
        return;
    }

    ar2[depth] = 0;
    dfs(depth+1,ar2);

    ar2[depth] = 1;
    dfs(depth+1,ar2);

    ar2[depth] = 2;
    dfs(depth+1,ar2);

    ar2[depth] = 3;
    dfs(depth+1,ar2);
}
int main(){

    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&arr_temp[i][j]);
    int ar2[5];
    memset(ar2,0,sizeof(ar2));
    dfs(0,ar2);
    printf("%d\n",ans);

    return 0;
}

