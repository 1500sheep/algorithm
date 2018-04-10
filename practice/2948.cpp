//
// Created by jameskang on 18. 4. 10.
//
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define SIZE 100000
int N,M;

string arr1[SIZE];
string arr2[SIZE];

int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++)
        scanf("%s",&arr1[i]);
    for(int i=0;i<M;i++)
        scanf("%s",&arr2[i]);

    sort(arr2,arr2+M);
    for(int i=0;i<M;i++)
        printf(" %s ",arr2[i]);
    printf("\n");
    return 0;
}

