#include<iostream>
// #include "classes.cpp"//you can add clases from another files also
using namespace std;

class Hero {// user defined datatype
    // properties
    private:// access modifiers
    int health;

    public:
    char level;
    int getHealth(){// getter
        return health;
    }
    void sethealth(int h){// setter
        health = h;
    }
};

int main(){
    Hero h1;
    h1.sethealth(70);
    cout<<h1.getHealth()<<endl;
    h1.level = 'A';
    // cout<<h1.health<<endl;
    cout<<h1.level<<endl;
    return 0;
}