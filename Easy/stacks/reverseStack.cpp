#include<iostream>
#include<stack>
using namespace std;

void insertBottom(stack<int> &s, int d){
    if(s.empty()){
        s.push(d);
        return;
    }
    int num = s.top();
    s.pop();
    insertBottom(s,d);
    s.push(num);
}

void reverse(stack<int> &s){
    if(s.empty()) return;

    int num = s.top();
    s.pop();

    reverse(s);

    insertBottom(s,num);
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }

    reverse(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}