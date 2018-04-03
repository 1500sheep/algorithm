#include <iostream>
using namespace std;
#define MAX_N 100
int table[MAX_N + 1][MAX_N + 1];
long long cache[MAX_N + 1][MAX_N + 1];
int n;

long long jump(int x,int y){
    if(x==n-1 && y==n-1)
        return 1;
    if(table[x][y]==0)
        return 0;
    if(cache[x][y]>0)
        return cache[x][y];

    long long ret = 0;
    int dx = x + table[x][y];
    int dy = y + table[x][y];
    if(dx<n)
        ret+=jump(dx,y);
    if(dy<n)
        ret+=jump(x,dy);
    return cache[x][y] = ret;
}

//경로의 개수는 263-1보다 작거
int main()
{
    cin >>  n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> table[i][j];
        }
    }
    cout << jump(0,0) << endl;

    return 0;
}