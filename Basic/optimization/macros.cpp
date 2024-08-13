#include<iostream>
using namespace std;

#define PI 3.14 //macro
int score = 10; //global variable

void a(int a){//either pass address to change in main func or use global variable
    cout<<"a "<<++a<<endl;
    cout<<++score<<endl;
}

int main(){
    int r = 5;//local variable
    // int area = PI * r * r;
    // cout<<"area is "<<area<<endl;

    a(r);
    cout<<"main "<<r<<endl;
    cout<<"main "<<score<<endl;
    return 0;
}