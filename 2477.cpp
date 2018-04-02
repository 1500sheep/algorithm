//
// Created by jameskang on 18. 3. 29.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define SIZE 9
#define SIZE_K 1001
using namespace std;

struct Node{
    int num;
    int time;
};
bool operator<(const Node& node1,const Node& node2){
    return node1.time==node2.time?node1.num>node2.num:node1.time>node2.time;
}

priority_queue<Node> pq;
int N,M,K;
int ai[SIZE];
int bi[SIZE];
Node checkNi[SIZE];
Node checkMi[SIZE];
int tK[SIZE_K];
int A,B;

vector<Node> v_M;
vector<Node> v_N;

int visied_N[SIZE_K];
int visied_M[SIZE_K];

int ans;

void solve(){
    vector<int> v_first;
    vector<Node> v_second;
    bool finish = false;
    int t = 0;
    while(!finish){
        int first_num=0;
        
        sort(v_sort.begin(),v_sort.end());
        for(int i=1;i<=N;i++){
            Node node;
            if(checkNi[i]!=NULL){
                checkNi[i].time--;
                if(checkNi[i].time==0){
                    node.time = t;
                    node.num = checkNi[i].num;
                    v_second.push_back(node);
                    checkNi[i] = NULL;
                }
            }
            if(checkNi[i]==NULL&&v_first.size()>first_num){
                node.num = v_first[first_num];
                node.time = ai[i];
                checkNi[i]= node;
                first_num++;
            }
        }
        sort(v_second.begin(),v_second.end(),compare());

        for(int i=1;i<=M;i++){

        }

        t++;
    }
}

int main(){
    int t;
    int c = 0;
    scanf("%d",&t);
    while(c++<t){
        Node node;
        ans = 0;
        scanf("%d %d %d %d %d",&N,&M,&K,&A,&B);
        for(int i=1;i<=N;i++)
            scanf("%d",&ai[i]);
        for(int i=1;i<=M;i++)
            scanf("%d",&bi[i]);
        for(int i=1;i<=K;i++){
            int temp_time;
            scanf("%d",&temp_time);
            node.num = i;
            node.time = temp_time;
            pq.push(node);
        }

        int time = 0;
        bool finish = false;


        printf("#%d %d\n",c,ans);
    }
    return 0;
}