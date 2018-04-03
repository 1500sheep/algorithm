//
// Created by jameskang on 18. 3. 26.
//
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

#define SIZE 1001
using namespace std;

int arr[SIZE];
int N;

double cpu_time(){
    double value;
    value = (double)clock() / (double)CLOCKS_PER_SEC;
    return value;
}

void f(int n){
    if(n==0)return;
    f(n-1);
    f(n-1);
}

void exchangeSort(){
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void merge(int low,int high){
    int mid = (low+high) / 2;
    int i = low;
    int j = mid+1;
    int k = 0;
    int u[high-low+1];

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            u[k] = arr[i];
            i+=1;
        }else{
            u[k] = arr[j];
            j+=1;
        }
        k+=1;
    }

    if(i>mid){
        for(int ii=j;ii<=high;ii++){
            u[ii-j+k] = arr[ii];
        }
    }
    else{
        for(int ii=i;ii<=mid;ii++){
            u[k+ii-i] = arr[ii];
        }
    }
    for(int ii=low;ii<=high;ii++){
        arr[ii] = u[ii-low];
    }

}

void mergeSort(int low,int high){
    if(low==high){
        return;
    }
    int mid = (low+high)/2;
    mergeSort(low,mid);
    mergeSort(mid+1,high);
    merge(low,high);
}

int main(){

    scanf("%d",&N);

    for(int i=0;i<N;i++)
        arr[i] = rand() %1000 +1;

    int n,m,i,j;
    double atime,btime;
    atime = cpu_time();
    exchangeSort();
    btime = cpu_time();
    cout<<-atime+btime<<endl;
    m = pow((double)2,(double)n);
    atime = cpu_time();
    mergeSort(0,N-1);
    btime = cpu_time();
    cout<<-atime+btime<<endl;

    return 0;
}