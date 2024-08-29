#include<iostream>
using namespace std;

void bs(int arr[], int n, int index){
    if(index >= n){
        return;
    }
    for(int i=0; i<n-index-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bs(arr,n,index+1);
}

void bs(int arr[], int n){
    if(n == 1 || n == 0){
        return;
    }
    if(arr[i] > arr[i+1])
        swap(arr[i],arr[i+1]);
        
    bs(arr,n);
    bs(arr,n-1);
}

int main(){
    int arr[5] = {5,4,3,2,1};
    bs(arr,5);

    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0; 
}