#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(){
    queue<int> q;
    for(int i=1; i<=4; i++){
        q.push(i);
    }

    queue<int> q2;
    for(int i=0; i<q.size()/2; i++){
        q2.push(q.front());
        q.pop();
    }

    while(!q2.empty()){
        q.push(q2.front());
        q2.pop();
        
        q.push(q.front());
        q.pop();
    }

    // Print the interleaved queue
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}