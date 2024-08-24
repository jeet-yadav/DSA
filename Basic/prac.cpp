#include<iostream>
using namespace std;

bool check(int arr[], int n, int i){// my logic is easy HAHAHAHAHAH
    if(n == 1)
        return true;
    if(arr[i] > arr[i+1])//but for the last element it is checking element outside the array
        return false;
    check(arr,n-1,i+1);
}

bool babbarCheck(int arr[], int n, int index){
    if(index >= n)
        return true;
    if(arr[index] > arr[index-1])
        return babbarCheck(arr,n,index+1);
    return false;
}

bool binaryRecursion(int arr[], int s, int e, int key){
    if(s>e)
        return 0;

    int mid = s+(e-s)/2;
    if(arr[mid] == key)
        return 1;

    if(key > arr[mid]){
        return binaryRecursion(arr,mid+1,e,key);
    }
    else{
        return binaryRecursion(arr,s,mid-1,key);
    }
}

int subsequence(string str, string output, int index){
    if(index >= str.length()){
        cout<<output<<endl;
        return 1;
    }
    char ch = str[index];

    output.push_back(ch);
    subsequence(str,output,index+1);

    output.pop_back();
    subsequence(str,output,index+1);

    // subsequence(str,output,index+1);

    // output.push_back(ch);
    // subsequence(str,output,index+1);
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int arr2[1] = {1};
    cout<<check(arr2,5,0)<<endl;
    cout<<babbarCheck(arr2,1,1)<<endl;
    cout<<binaryRecursion(arr,0,4,5)<<endl;
    cout<<subsequence("abc"," ",0)<<endl;
    return 0;
}