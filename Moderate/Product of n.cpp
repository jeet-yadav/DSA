#include<iostream>
using namespace std;
int main(){
    int n;
    int copy = n;
    int copy2 = n;
    cin>>n;
    for(int i=1; i<=3; i++){
        copy2 = n%10;
        cout<<copy2<<endl;;
    }
    return 0;
}