#include<iostream>
using namespace std;

inline int maxi(int& a, int&  b){
    return (a>b) ? a:b;//inline function of code below
}
int main(){
    int a = 1, b = 2;
    int ans = 0;

    // if(a > b){
    //     ans = a;
    // }
    // else{
    //     ans = b;
    // }

    int ans = maxi(a,b);
    cout<<ans<<endl;
    return 0;
}
