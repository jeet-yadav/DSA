#include<iostream>
using namespace std;
int main(){
    int n;
    int count = 0; 
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<"  ";
        }
        for(int j=1; j<=i*2-1; j++){
            cout<<"* ";
        }
        /*for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        for(int j=2; j<=i; j++){
            cout<<"* ";
        }*/
        cout<<"\n";
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"  ";
        }
        for(int j=1; j<=n-i; j++){
            cout<<"* ";
        }
        for(int j=1; j<=n-(i+1); j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
    return 0;
}