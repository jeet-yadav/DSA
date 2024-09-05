#include<iostream>
using namespace std;

class Human{

    private:
    int type;

    public:
    int height;
    int weight;
    int age;

    public:
    int getAge(){
        return this -> age;
    }
    void setWeight(int w){
        this -> weight = w;
    }
    int getWeight(){
        return weight;
    }
};

class Male: public Human{

    public:
    string color;

    void sleep(){
        cout<<"male sleeping"<<endl;
    }
};

int main(){
    Male m1;
    m1.height = 189;
    cout<<m1.height<<endl;
    m1.sleep();
    m1.setWeight(70);
    cout<<m1.getWeight()<<endl;
    return 0;
}