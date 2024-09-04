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
    Hero(int health){//parameterized constructor, called when object is created with argument
        cout<<"this -> "<<this<<endl;// this is a pointer to current object
        this -> health = health;
    }
};

int main(){
    Hero h1;
    cout<<"h1 address -> "<<&h1<<endl;
    h1.level = 'A';
    h1.sethealth(70);
    cout<<h1.level<<endl;
    cout<<h1.getHealth()<<endl<<endl;

    Hero *h2 = new Hero(99);// using heap memory, Static memory allocation
    cout<<"h2 address -> "<<h2<<endl;
    h2->level = 'B';
    // h2->sethealth(80);
    cout<<(*h2).level<<endl;
    cout<<(*h2).getHealth()<<endl<<endl;
    // also can be written as
    // cout<< h2->level <<endl;
    // cout<< h2->getHealth() <<endl;

    Hero h3(10);// argument constructor
    cout<<"h3 address -> "<<&h3<<endl;
    cout<<h3.getHealth()<<endl;
    return 0;
}