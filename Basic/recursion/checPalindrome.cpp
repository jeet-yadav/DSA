#include<iostream>
using namespace std;

bool palindrome(string str, int s, int n){
    if(s > n/2)
        return true;
    if(str[s] != str[n-s-1]){
        return false;
    }
    return palindrome(str,s+1,n);
}

void power(int a, int b){
    int ans = a;
    for(int i=a; i<=b; i++){
        ans *= a;
    }
    cout<<ans<<endl;
}

int powerRecursion(int a, int b){
    if(b==1){
        return a;
    }
    return a * powerRecursion(a,b-1);
}

int main(){
    string name = "malayalam";

    // if(palindrome(name, 0, name.length())){
    //     cout << "The string is a palindrome" << endl;
    // }
    // else{
    //     cout << "The string is not a palindrome" << endl;
    // }
    power(3,5);
    cout<<powerRecursion(3,5);
    return 0;
}