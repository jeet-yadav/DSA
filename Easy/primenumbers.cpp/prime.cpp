#include<iostream>
#include <cmath>
using namespace std;

int prime(int n){
    if(n<2){
        cout<<"obviously not prime";
        return 0;
    }
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            cout<<"non prime";
            return 0;
        }
    }
    cout<<"the prime";
}

int main(){
    int n;
    cin>>n;
    prime(n);
    return 0;
}