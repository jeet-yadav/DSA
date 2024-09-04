#include<iostream>
using namespace std;

class Hero{
    private:
    int health;
    
    public:
    char level;

    Hero(Hero& temp){// copy constructor
        cout<<"copy constructor called"<<endl;
        this -> health = temp.health;
        this -> level = temp.level;
    }

    Hero(int health, char level){//once we write constructor then compiler will remove default constructor
        cout<<"this -> "<<this<<endl;
        this -> health = health;
        this -> level = level;
        cout<<health<<endl;
        cout<<level<<endl;
    }
};

int main(){
    Hero h1(10, 'A');

    // Hero h2;// This will call default constructor, which is removed as we have written our own constructor, which takes 2 inputs
    
    Hero h3(h1);// copy constructor
    return 0;
}