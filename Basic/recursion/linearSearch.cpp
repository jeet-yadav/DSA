#include<iostream>
using namespace std;

int search(int arr[],int n,int key){//linear search using recursion
    if(n == 0){
        return 0;
    }
    if(arr[0]==key){
        return 1;
    }
    else{
        search(arr+1,n-1,key);
    }
}

int main(){
    int n = 5;
    int arr[n] = {8,3,5,1,6};
    int key = 1;
    cout<<search(arr,n,key);
    return 0;
}