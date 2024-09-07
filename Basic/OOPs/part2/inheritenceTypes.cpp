#include<iostream>
using namespace std;

class Animal{

    public:
    void eat(){
        cout<<"animal eating"<<endl;
    }
};

class Human{

    public:
    void eat(){// same function name as in animal, causes ambiguity
        cout<<"human eating"<<endl;
    }
};
class Hybrid: public Animal, public Human{
    
};

int main(){
    Hybrid d1;
    d1.Animal::eat();// both the parents have function with same name, using scope resolution operator this can be managed
    d1.Human::eat();
    return 0; 
}