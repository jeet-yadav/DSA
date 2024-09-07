#include<iostream>
using namespace std;

class A{

    public:// bottom shit is about, function overloading. Comes under compile time polymorphism
    void Hello(){
        cout<<"Hello eyerynyan "<<endl;
    }
    void Hello(string name){
        cout<<"Hello eyerynyan "<<name<<endl;
    }
    int Hello(string name, int age){
        cout<<"Hello eyerynyan "<<endl;
        return 0;
    }
};

class B{

    public:
    int a;
    int b;

    public:
    int add(){
        return a+b;
    }

    void operator+ (B &obj){//operator overloading. Comes under compile time polymorphism
        int value1 = this -> a;
        int value2 = obj.a;
        cout<<"output : "<<value2 - value1<<endl;
    }

    void operator() (int a){
        cout<<"brackets "<<a<<endl;
    }

    void operator- (int a){
        cout<<"minus operator "<<a<<endl;
    }
};


class Animal{

    public:
    void speak(){
        cout<<"speaking"<<endl;
    }
};
class Dog: public Animal{
    public:
    void speak(){
        cout<<"barking"<<endl;
    }
};
int main(){
    // A a1;
    // a1.Hello("abc");

    // B obj1, obj2;

    // obj1.a = 5;
    // obj2.a = 6;

    // obj1 + obj2;
    // obj1(10);// this works differently then others
    // obj1 - (2);

    Dog d1;
    d1.speak();//this will call the speak() function of Dog class, function overridding. Comes under run time polymorphism.
     
    return 0;
}