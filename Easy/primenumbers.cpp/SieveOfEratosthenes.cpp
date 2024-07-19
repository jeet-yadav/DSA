#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int SieveOfEratosthenes(int n){    //using vector
    int count = 0;
    vector<bool> prime(n+1, true); // a bool type vector named prime of size n+1, all the elements are initialised as true for now
    
    prime[0] = prime[1] = false;   // since 0 and 1 are not prime numbers
    
    for(int i=2; i<n; i++){
        if(prime[i]){              // already we have declared all elements as prime
            count++;
            
            for(int j=2*i; j<n; j+=i){//    multiples of i are marked as non prime/false
                prime[j] = 0;
            }
        }
    }
    cout<<count;
    return 0;
}

int main(){
    int n, count = 0;
    cout<<"Enter a number : ";
    cin>>n;
    SieveOfEratosthenes(n);
    return 0;
}