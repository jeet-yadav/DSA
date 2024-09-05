#include<iostream>
using namespace std;

class Student{
    private:// Hogya incapsulation 
        int age;
    public:
        Student(int a){
            age = a;
        }
        int getAge(){
            return age;
        }
};

int main(){
    Student s1(20);
    cout<<s1.getAge();
    return 0;
}