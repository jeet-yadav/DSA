#include<iostream>
using namespace std;

int binarySearch(int arr[][3], int row, int col, int target){
    int s = 0;
    int e = (row * col)-1;
    int mid = (s+e)/2;
    while(s<e){
        int element =  arr[mid/col][mid%col];
        if(element==target){
            return 1;
        }
        else if(element < target){
                s = mid + 1;
        }
        else{
                e = mid - 1;
        }
        mid = (s+e)/2;
    }
    return -1;
}

int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<binarySearch(arr, 3, 3, 32);
    return 0;
}