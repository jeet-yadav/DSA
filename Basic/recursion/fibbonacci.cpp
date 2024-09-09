#include<iostream>
using namespace std;

int fibbo(int n){//has higher complexity
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    int ans = fibbo(n-1) + fibbo(n-2);
    return ans;  
}

int main(){
    int n = 4;
    int a = fibbo(n);
    cout<<a<<endl;

    int ans = 0;
    int x = 0, y = 1;
    for(int i=0; i<=n; i++){// have lower complexity
        cout<<ans<<" ";
        x = y;
        y = ans;
        ans = x + y;
    }
    return 0;
}