#include<iostream>
using namespace std;

int prime(int n){
    for(int i=2; i<n/2; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n, count=0;
    cin>>n;
    for(int i=2; i<n; i++){
        if(prime(i)){
            count++;
        }
    }
    cout<<count;
    return 0;
}