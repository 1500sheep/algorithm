//
// Created by jameskang on 18. 4. 4.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define SIZE 100

using namespace std;

struct Second_str{
    int second;
    char direct;
};

int ax[4] = {0,1,0,-1};
int ay[4] = {1,0,-1,0};
int arr_apple[SIZE][SIZE];
char arr_K[10001];
vector<Second_str> v_second;

int N,K,L;
int second;

int main(){
    memset(arr_K,NULL,sizeof(arr_K));

    scanf("%d %d",&N,&K);
    for(int i=0;i<K;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        arr_apple[x-1][y-1] = 1;
    }
    scanf("%d",&L);
    for(int i=0;i<L;i++) {
        int num;
        char direct;
        scanf("%d %c",&num,&direct);
        arr_K[num]= direct;
//        Second_str s;
//        s.second = num;
//        s.direct = direct;
//        v_second.push_back(s);
    }

    bool check = true;
    vector< pair<int,int> > v;
    queue<pair<int,int>> q_snake;
    q_snake.push(make_pair(0,0));
    int status = 0;

    while(check){
        v.clear();
        second++;
        int head_x = q_snake.front().first+ax[status];
        int head_y = q_snake.front().second+ay[status];
        if(head_x>=N||head_y>=N||head_x<0||head_y<0){
            check =false;
            break;
        }
        while(!q_snake.empty()){
            v.push_back(q_snake.front());
            q_snake.pop();
        }
        for(int i=0;i<v.size();i++){
            if(head_x==v[i].first&&head_y==v[i].second){
                check = false;
            }
        }
        if(!check) break;
        int check_apple = 1;
        if(arr_apple[head_x][head_y]){
            arr_apple[head_x][head_y]--;
            check_apple--;
        }
        q_snake.push(make_pair(head_x,head_y));
        for(int i=0;i<v.size()-check_apple;i++){
            q_snake.push(v[i]);
        }
//        bool check_second = false;
//        char direct;
//        for(int i=0;i<v_second.size();i++){
//            if(second==v_second[i].second){
//                check_second = true;
//                direct = v_second[i].direct;
//                break;
//            }
//        }
        if(arr_K[second]){
            if(arr_K[second]=='D'){
                status = (status+1)%4;
            }else if(arr_K[second]=='L'){
                if(status==0)
                    status=3;
                else
                    status--;
            }
        }
    }
    printf("%d\n",second);
    return 0;
}
