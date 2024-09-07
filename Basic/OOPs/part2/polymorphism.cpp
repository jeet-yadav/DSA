#include<iostream>
using namespace std;

class A{

    public:
    void Hello(){
        cout<<"Hello eyerynyan "<<endl;
    }
    void Hello(string name){
        cout<<"Hello eyerynyan "<<name<<endl;
    }
    int Hello(string name, int a){
        cout<<"Hello eyerynyan "<<endl;
        return 0;
    }
};

int main(){
    A a1;
    a1.Hello("abc",1);
    return 0;
}