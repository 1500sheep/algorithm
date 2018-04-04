//
// Created by jameskang on 18. 4. 4.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int N,B,C;
long long ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin>>N;
    int num;
    for(int i=0;i<N;i++){
        cin>>num;
        v.push_back(num);
    }
    cin>>B>>C;
    for(int i=0;i<N;i++){
        int mem = v[i];
        mem-=B;
        if(mem>0){
            ans +=(mem/C);
            if(mem%C!=0){
                ans++;
            }
        }
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
