#include<iostream>
using namespace std;

bool binarySearch(int arr[],int s, int e,int key){
    if(s>e)
        return 0;

    int mid = s+(e-s)/2;
    if(arr[mid]==key)
        return 1;
    if(key > arr[mid]){
        return binarySearch(arr,mid+1,e,key);
    }
    else{
        return binarySearch(arr,s,mid-1,key);
    }
}

int main(){
    int n = 5;
    int arr[5] = {1,2,3,4,5};
    int key = 48;
    cout<<binarySearch(arr,0,4,key);
    return 0;
}