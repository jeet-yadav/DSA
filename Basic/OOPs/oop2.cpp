#include<iostream>
#include<cstring>//fuck warnings
using namespace std;

class Hero{
    private:
    int health;

    public:
    char *name;
    char level;
    static int timeToComplete;// Static variable, without creating any object we can access it

    static int random(){// Static function, can only access static variable
        cout<<"random function called"<<endl;
        return timeToComplete;
    }

    Hero(){
        cout<<"default constructor called"<<endl;
        name = new char[100];
    }
    Hero(char health){
        cout<<"parameterized constructor called"<<endl;
        this -> health = health;
    }
    Hero(char health, char level){
        cout<<"double parameterized constructor called"<<endl;
        this -> health = health;
        this -> level = level;
        name = new char[100];
    }

    // Shallow copy, if we didnt define copy constructor then value of name will be same as that of h1, but due to pointer pointing to same address changes in h1 will be reflected in h2
    // Deep copy, copies all the properties. Create a new array for copied element
    Hero(Hero& temp){// copy constructor
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "Copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void setname(char name[]){// Setter for name
        strcpy(this->name, name);
    }

    // Setters and getters for health
    void sethealth(int h){
        health = h;
    }
    int gethealth(){
        return health;
    }

    void print(){// Print function
        cout << endl;
        cout << "[ Name: " << this->name<< " ,";
        cout << "health: " << this->health << " ,";
        cout <<"level: " << this->level << " ]";
        cout << endl << endl;
    }

    // Destructors are automatically created but for object made in heap memory(dynamic memory allocation) manually creating destructors is required
    // Destructor XDDD
    ~Hero(){
        cout<<"Destructor called"<<endl;
        delete[] name;
    }
};

int Hero::timeToComplete = 5;

int main(){
    Hero h1(89,'S');
    h1.setname("jeet");
    h1.print();
    
    Hero h2(h1);
    h2.print();
    h1.setname("helloStranger");
    h1.print();
    h2.print();

    Hero h3 = h1;// Assignment operator, Shallow copy
    Hero *p = new Hero();// Dynamic memory allocation

    cout<<"Time to complete -> "<<Hero::timeToComplete<<endl;
    return 0;
}