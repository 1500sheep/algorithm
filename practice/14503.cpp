//
// Created by jameskang on 18. 4. 5.
//
#include <iostream>
#include <queue>

using namespace std;

#define SIZE 50

int N,M;
int arr[SIZE][SIZE];
int visit[SIZE][SIZE];
int X,Y,d;
int ans;

int dx[4] = {-1,0,1,-0};
int dy[4] = {0,1,0,-1};
void bfs() {
    int x = X;
    int y = Y;
    while (1) {
        if (visit[x][y] == 0) {
            visit[x][y] = 1;
            ans++;
        }

        int temp_d = d;

        while (1) {
            if (d == 0)
                d = 3;
            else
                d--;

            int temp_x = dx[d];
            int temp_y = dy[d];
            if (visit[temp_x][temp_y] == 0 && arr[temp_x][temp_y] == 0) {
                x = temp_x;
                y = temp_y;
                break;
            }
            if (temp_d == d) {
                int t=d;
                if (d == 1)
                    t = 3;
                else if (d == 0)
                    t = 2;
                else
                    t -= 2;

                temp_x = x + dx[t];
                temp_y = y + dy[t];
                if (arr[temp_x][temp_y] == 1) {
                    return;
                } else {
                    x = temp_x;
                    y = temp_y;
                    break;
                }
            }
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &X, &Y, &d);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &arr[i][j]);


    bfs();


    printf("%d\n", ans);
    return 0;
}
