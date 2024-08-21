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

void power(int a, int b){//no recursion T_T
    int ans = 1;
    for(int i=1; i<=b; i++){
        ans *= a;
    }
    cout<<ans<<endl;
}

int powerRecursion(int a, int b){// I did it, BRUTE-FORCE >_<
    if(b==1){
        return a;
    }
    return a * powerRecursion(a,b-1);
}

int powerRecur(int a, int b){//real shit, and optimized 0_0
    if(b==0)
        return 1;
    if(b==1)
        return a;
    int ans = powerRecur(a, b/2);
    if(b%2 == 0){
        return ans * ans;
    }
    else{
        return a * ans * ans;
    }
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
    cout<<powerRecursion(3,5)<<endl;
    cout<<powerRecur(3,5)<<endl;
    return 0;
}