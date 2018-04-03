//
// Created by jameskang on 18. 4. 2.
//

#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
struct Node{
    int x;
    int y;
    int r;
};
using namespace std;

int n;

int ans;
Node arr[3001];
int memo[3001];
int dodouble(int a){
    return a * a;
}
// 코드 참고!!
int parentFind(int index){
    if(index ==memo[index]){
        return index;
    }else{
        // 이 부분이 부모 찾을 수 도 있고 넣어줄 수도 있고!! Remember!
        return memo[index] = parentFind(memo[index]);
    }
}
// 부모가 동일하지 않으면 부모를 갖게 해준다!!
void parentMerge(int i,int j){
    i = parentFind(i);
    j = parentFind(j);
    memo[i] = j;
}
void dfs(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) {
            bool check = sqrt(dodouble(arr[i].x - arr[j].x) + dodouble(arr[i].y - arr[j].y)) <=
                         (arr[i].r + arr[j].r);
            if (check) {
                if(parentFind(i)!=parentFind(j)){
                    parentMerge(i,j);
                    ans--;
                }
            }
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t-->0){
        ans = 0;
        memset(arr,0,sizeof(arr));
        memset(memo,0,sizeof(memo));
        n=0;
        scanf("%d",&n);
        ans = n;
        for(int i=1;i<=n;i++){
            int x,y,r;
            scanf("%d %d %d",&x,&y,&r);
            Node node;
            node.x = x;
            node.y = y;
            node.r = r;
            arr[i] = node;
            memo[i] = i;
        }

        dfs();
        printf("%d\n",ans);
    }
    return 0;
}