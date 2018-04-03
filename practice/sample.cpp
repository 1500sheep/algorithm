//
// Created by jameskang on 18. 4. 3.
//
#include <iostream>
#define SIZE 101
using namespace std;

int arr[SIZE][SIZE];

int main(){
    fill_n(arr,SIZE,0);
    for(int i=1;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(j==0||j==i)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d\n",arr[n][m]);
    return 0;
}