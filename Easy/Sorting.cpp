#include<iostream>
using namespace std;
//                                                                  Simple Sorting Algorithms
int print(int arr[], int n){// print an array
    cout << "ARRAY >> ";
    for(int i=0; i<n; i++){
        cout <<  arr[i] << " ";
    }
    cout<<endl;
}

void SelectionSort(int arr[], int n){//        taking the smallest element from array and swapping to corresponding element from i, then increasing i
    for(int i=0; i<n-1; i++){//                                                 Selection Sort
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            } 
        }
        swap(arr[i], arr[min]);
    }   
}

int MySort(int arr[], int n){//                     Don't know what kind of sorting it is, but i made it myself :) 
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
    cout<<endl;
}
 
int BubbleSort(int arr[], int n){//                                          Bubble Sort
    for(int i=0; i<n-1; i++){  
        for(int j=0; j<n-i-1; j++){ //can use j<=n-1 als o
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int InsertionSort(int arr[], int n){//                                      Insertion sort 
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j=i-1;
        for(; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int InsertionSortWhile(int arr[], int n){//                            Insertion sort using while
    int i = 1;                   
    while(i<n){
        int j = i-1;
        int temp = arr[i];
        while(j >= 0){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1] = temp;
        i++;
    }
}

int main(){
    int arr[5] = {5,2,4,1,3};
    print(arr, 5);
    InsertionSortWhile(arr,5);
    print(arr, 5);
    return 0;
}