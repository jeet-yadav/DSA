#include<iostream>
using namespace std;

class Hero{
    private:
    int health;
    
    public:
    char level;

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
    cout<<h1.level<<endl;

    Hero h2;// This will call default constructor, which is removed as we have written our own constructor, which takes 2 inputs
    
    return 0;
}