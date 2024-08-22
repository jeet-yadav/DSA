#include<iostream>
using namespace std;
void merge(int arr[], int s, int e){
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int arr1[len1];
    int arr2[len2];

    int k = s;
    for(int i=0; i<len1; i++){
        arr1[i] = arr[k++];
    }
    
    k = mid+1;
    for(int i=0; i<len2; i++){
        arr2[i] = arr[k++];
    }
    int i = 0, j = 0;
    k = s;
    while(i < len1 && j < len2){
        if(arr1[i] < arr2[j]){
            arr[k++] = arr1[i];
        }
        if(arr1[i] > arr2[j]){
            arr[k++] = arr2[j++];
        }
    }
    while(i < len1){
        arr[k++] = arr1[i++];
    }
    while(i < len2){
        arr[k++] = arr2[j++];
    }
}
void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}
int main(){
    int arr[5] = {5,4,3,2,1};
    mergeSort(arr,0,4);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}