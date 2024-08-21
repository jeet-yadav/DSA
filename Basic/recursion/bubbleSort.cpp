#include<iostream>
using namespace std;

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    print(arr,n);
}

void bubbleSortByBabbar(int arr[], int n){
    if(n == 0 || n == 1)
        return;
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleSortByBabbar(arr,n-1);
}

void bubbleRecursion(int arr[], int n, int i, int j){
    if(i==n-1)
        return;
    if(j == n-i-1){
        bubbleRecursion(arr,n,i+1,0);
        return;
    }
    if(arr[j]>arr[j+1])
        swap(arr[j], arr[j+1]);
    bubbleRecursion(arr,n,i,j+1);
}

int main(){
    int arr[] = {5,7,3,9,7,1,4,6,7,4};
    print(arr, 10);
    // bubbleSort(arr,10);
    // bubbleRecursion(arr,10,0,0);
    bubbleSortByBabbar(arr,10);
    print(arr, 10);
    return 0;
}