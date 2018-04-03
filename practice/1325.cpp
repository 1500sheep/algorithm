//
// Created by jameskang on 18. 4. 2.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> arr[10001];
int N,M;
int sol[10001];
int visit[10001];
queue<int> q;
int maxv;


int main(){
    cin >> N >> M;
    int A,B;

    while(M--){
        cin>>A>>B;
        arr[B].push_back(A);
    }
    for(int i=1;i<=N;i++){
        fill(visit+1,visit+N+1,0);
        if(arr[i].size()==0)
            continue;
        visit[i] = true;
        int cnt = 0;
        q.push(i);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int j=0;j<arr[temp].size();j++){
                if(visit[arr[temp][j]]==0){
                    visit[arr[temp][j]] = 1;
                    q.push(arr[temp][j]);
                    cnt++;
                }
            }
        }
        sol[i] = cnt;
        if(sol[i]>maxv){
            maxv = sol[i];
        }

    }
    for(int i=1;i<=N;i++){
        if(sol[i]==maxv){
            printf("%d ",i);
        }
    }

    return 0;
}