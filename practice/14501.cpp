//
// Created by jameskang on 18. 4. 5.
//
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 15

int t[SIZE];
int p[SIZE];

int dp[SIZE];

int N,ans;

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d %d",&t[i],&p[i]);

    int takeday;
    for(int i=0;i<N;i++){
        takeday = t[i];
        for(int j=0;j<i;j++){
            dp[i] = max(dp[i] ,dp[j]);
        }
        for(int j=0;j<i+takeday;j++){
            dp[i+takeday] = max(dp[i+takeday] ,dp[j]);
        }
        dp[i+takeday] = max(dp[i+takeday] ,dp[i]+p[i]);

    }
    for(int i=0;i<=N;i++){
        if(ans<dp[i])
            ans = dp[i];
    }
    printf("%d\n",ans);
    return 0;
}
