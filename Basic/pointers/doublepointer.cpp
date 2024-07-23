#include<iostream>
using namespace std;

void update(int **p){
    p = p + 1;

    // *p = *p + 1; 

    // **p = **p + 1;
}

int main(){
    int a = 5;
    int *p = &a;
    int **pp = &p;

    // cout<< a <<endl;
    // cout<< *p <<endl;
    // cout<< **pp <<endl<<endl;
 
    // cout<< &a <<endl;
    // cout<< p <<endl;
    // cout<< *pp <<endl<<endl;

    // cout<< &p <<endl;
    // cout<< pp <<endl<<endl;

    cout <<"before "<< a <<endl;
    cout <<"before "<< p <<endl;
    cout <<"before "<< pp <<endl;
    update(pp);
    cout <<"after "<< a <<endl;
    cout <<"after "<< p <<endl;
    cout <<"after "<< pp <<endl;
    return 0;
}