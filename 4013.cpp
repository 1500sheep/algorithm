//
// Created by jameskang on 18. 3. 28.
//

#include <iostream>
#include <vector>
#include <cmath>

#define SIZE 20
using namespace std;

int ans,K;
int arr[4][8];
int arrK[SIZE];
vector<pair<int,int>> v;



void moveTopni(int pos,int way){
    int temp;
    if(way==1){
        temp = arr[pos][7];
        for(int i=6;i>=0;i--){
            arr[pos][i+1] = arr[pos][i];
        }
        arr[pos][0] = temp;
    }else{
        temp = arr[pos][0];
        for(int i=1;i<8;i++){
            arr[pos][i-1] = arr[pos][i];
        }
        arr[pos][7] = temp;
    }
}

int score(){
    int result=0;
    for(int i=0;i<4;i++){
        if(arr[i][0]==1){
            printf("%d\n",i);
            result+=pow(2,i);
        }
    }

    return result;

}
void changeTopni(int pos, int way){
    int right = 1;
    int left = -1;

}
int main(){
    int t;
    int c = 0;
    scanf("%d",&t);
    while(c++<t){
        v.clear();
        ans=0;
        scanf("%d",&K);
        for(int i=0;i<4;i++)
            for(int j=0;j<8;j++)
                scanf("%d",&arr[i][j]);
        for(int i=0;i<K;i++){
            int pos,way;
            scanf("%d %d",&pos,&way);
            pos-=1;
            v.push_back(make_pair(pos,way));
        }

        for(int i=0;i<v.size();i++){
            int pos =v[i].first;
            int direction =v[i].second;
            changeTopni(pos,direction);
            ans += score();
        }

        printf("#%d %d",c,ans);
    }
    return 0;
}
