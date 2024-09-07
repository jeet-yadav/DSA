#include<iostream>
using namespace std;

class Human{

    private://cannot be inherited 
    int type;

    protected://can be inherited
    // int weight;

    public:
    int height;
    int age;
    int weight;

    public:
    int getAge(){
        return this -> age;
    }
    void setAge(int a){
        this -> age = a;
    }

    void setWeight(int w){// setter
        this -> weight = w;
    }
    int getWeight(){// getter
        return weight;
    }
};

class Male: private Human{

    public:
    string color;
    void setWeight(int w){// setter
        this -> weight = w;
    }
    int getWeight(){// getter
        return weight;
    }

    void sleep(){
        cout<<"male sleeping"<<endl;
    }
};

int main(){
    Male m1;
    // m1.height = 189;
    // m1.age = 20;
    m1.setWeight(70);
    // cout<<"height "<<m1.height<<endl;
    // cout<<"age "<<m1.age<<endl;
    cout<<"weight "<<m1.getWeight()<<endl;
    return 0;
}