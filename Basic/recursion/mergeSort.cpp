#include<iostream>
using namespace std;

void copyMerge(int arr[], int s, int e){
    int mid = (s+e)/2;

    int len1 = mid-s+1;// also can be said as mid-(s-1), i guess
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int k = s;
    for(int i=0; i<len1; i++){
        first[i] = arr[k++];
    }

    k = mid+1;
    for(int i=0; i<len2; i++){
        second[i] = arr[k++];
    }

    //merge 2 sorted arrays    
    int index1 = 0;
    int index2 = 0;
    k = s;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[k++] = first[index1++];
        }
        else{
            arr[k++] = second[index2++];
        }
    }

    //Copy remaining elements of first array, if any
    while(index1 < len1){
        arr[k++] = first[index1++];
    }
    while(index2 < len2){
        arr[k++] = second[index2++];
    }

    delete[]first;
    delete[]second;
}

void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;

    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    copyMerge(arr,s,e);
}

void print(int arr[], int n){
    for(int i=0 ;i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n = 10;
    int arr[n] = {10,9,8,7,6,5,4,3,2,1};
    print(arr,n);
    cout<<endl;
    mergeSort(arr,0,n-1);
    print(arr,n);
    return 0;
}