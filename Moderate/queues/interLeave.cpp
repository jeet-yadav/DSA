#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(){
    queue<int> q;
    for(int i=11; i<=18; i++){
        q.push(i);
    }
    
    int mid = q.size()/2;

    // put first halve in stack
    stack<int> s;
    for(int i=0; i<mid; i++){
        s.push(q.front());
        q.pop();
    }

    // put first halve of stack again in queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    // rotate the queue till mid
    for(int i=0; i<mid; i++){
        q.push(q.front());
        q.pop();
    }

    // put second halve in stack
    stack<int> s2;
    for(int i=0; i<mid; i++){
        s2.push(q.front());
        q.pop();
    }

    // put second halve of stack again in queue
    while(!s2.empty()){
        int val = s2.top();
        s2.pop();
        q.push(val);

        val = q.front();
        q.pop();
        q.push(val);
    }

    // Print the interleaved queue
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}