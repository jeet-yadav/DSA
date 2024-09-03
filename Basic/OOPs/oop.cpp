#include<iostream>
// #include "classes.cpp"//you can add clases from another files also
using namespace std;

class Hero {// user defined datatype
    // properties
    public:
    int health;
    char level;
};

int main(){
    Hero h1;
    cout<<h1.health<<endl;
    cout<<h1.level<<endl;
    return 0;
}