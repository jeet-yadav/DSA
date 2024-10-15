#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//https://www.geeksforgeeks.org/problems/queue-reversal/1

queue<int> reverse(queue<int> q){
    if(q.empty()){
        return q;// Base case: return the empty queue
    }

    // Store the front element
    int value = q.front();
    q.pop();

    // Recursively reverse the rest of the queue
    reverse(q);

    // Push the front element to the back of the queue after the rest is reversed
    q.push(value);

    return q;
}

int main(){
    queue<int> q;

    // taking input in queue
    for(int i=1; i<=5; i++){
       q.push(i);
    }

    //reversed using recursion(approach 2)
    queue<int> recursedQ;
    recursedQ = reverse(recursedQ);

    // printing normal queue
    queue<int> q_copy = q;
    while(!q_copy.empty()){
        cout<<q_copy.front()<<" ";
        q_copy.pop();
    }
    cout<<endl;

    // reversing the queue
    //step1 : create stack
    stack<int> s;

    //step2 : put all elements of q in s
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    //step 3 : put elements back in q from s
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    // printing reversed queue
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}