#include<iostream>
#include<stack>
using namespace std;

void insertEnd(stack<int> &s, int d){
    if(s.empty()){
        s.push(d);
        return;
    }
    int num = s.top();
    s.pop();
    insertEnd(s,d);
    s.push(num);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
   
    insertEnd(s,10);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}