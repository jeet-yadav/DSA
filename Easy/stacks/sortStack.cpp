#include<iostream>
#include<stack>
using namespace std;

void sortInsert(stack<int> &s, int digit){
    if(s.empty() || s.top() >= digit){
        s.push(digit);
        return;
    }

    int num = s.top();
    s.pop();

    sortInsert(s,digit);

    s.push(num);
}

void sort(stack<int> &s){
    if(s.empty()) return;

    int num = s.top();
    s.pop();

    sort(s);

    sortInsert(s,num);
}

int main(){
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(5);
    s.push(2);
    s.push(4);

    sort(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}