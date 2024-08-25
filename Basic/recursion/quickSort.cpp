#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int cnt = 0;

    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivot){
            cnt++;
        }
    }

    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(pivot < arr[j]){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }

    int p = partition(arr,s,e); 

    quickSort(arr,s,p);
    quickSort(arr,p+1,e);
}

int main(){
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    quickSort(arr,0,9);

    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}