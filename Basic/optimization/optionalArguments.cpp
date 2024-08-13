#include<iostream>
using namespace std;

void print(int arr[], int n, int start = 0){//default argument if start is go passes as argument, start will be 0 as defautl
    for(int i=start; i<n; i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[5] = {5,2,4,78,23};
    print(arr,5);//start not given 
    return 0;
}
//only rightmost element are allowed to be default argument