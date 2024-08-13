#include<iostream>
using namespace std;

int fact(int n){//factorial of n
    if(n == 0)//base case
        return 1;
    return n * fact(n-1);//recurrence relation
}

int power(int n){//2 power n
    if(n == 0){
        return 1;
    }
    return 2 * power(n-1);
}

void count(int n){
    if(n == 0){
        return;
    }
    // cout<<n<<" "; tail recursion
    count(n-1);
    cout<<n<<" ";// head recursion
}

int main(){
    int n;
    cin >> n;
    // cout<< fact(n) <<endl;
    // cout<< power(n) <<endl;
    count(n);
    return 0;
}