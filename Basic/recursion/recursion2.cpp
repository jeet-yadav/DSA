#include<iostream>
using namespace std;

int check(int arr[], int n){//check if the array is sorted
    int flag = true;
    for(int i=1; i<n; i++){
        if(arr[i] > arr[i-1]){
            flag = true;
        }
        else{
            flag = false;
            break;
        }
    }
    return flag;
}

bool isSorted(int arr[], int n){//same-same but recursion 
    if( n == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    else{
        // isSorted(arr+1,n-1);
        bool rp = isSorted(arr+1,n-1);
        return rp;
    }
}

int arrSum(int arr[],int n){//did it myself 
    if(n == 0){
        return 0;
    }
    int sum = arr[0] + arrSum(arr+1,n-1);
    return sum;
}

int main(){
    int arr[5] = {1,2,3,4,5};
    // cout<<check(arr,5)<<endl;
    // int ans = isSorted(arr,5);
    // cout<<ans<<endl;
    cout<<arrSum(arr,5);
    return 0;
}