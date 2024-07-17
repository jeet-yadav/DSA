#include<iostream>
#include <cmath>
using namespace std;

bool prime(int n){
    if(n<2){
        return false;
    }
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n, count = 0;
    cout<<"Enter a number : ";
    cin>>n;
    for(int i=2; i<n; i++){
        if(prime(i)){
            count++;
        }
    }
    cout<<count;
    return 0;
}