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
    Hero(){// constructor, called when object is created
        cout<<"constructor called"<<endl;
    }
    Hero(int health){
        cout<<"this -> "<<this<<endl;// this is a pointer to current object
        this -> health = health;
    }
};

int main(){
    Hero h1;
    h1.level = 'A';
    h1.sethealth(70);
    cout<<h1.level<<endl;
    cout<<h1.getHealth()<<endl;

    Hero *h2 = new Hero(99);// using heap memory, Static memory allocation
    h2->level = 'B';
    // h2->sethealth(80);
    cout<<(*h2).level<<endl;
    cout<<(*h2).getHealth()<<endl;
    // also can be written as
    // cout<< h2->level <<endl;
    // cout<< h2->getHealth() <<endl;

    Hero h3(10);// argument constructor
    cout<<h3.getHealth()<<endl;
    cout<<"h3 address -> "<<&h3<<endl;
    return 0;
}