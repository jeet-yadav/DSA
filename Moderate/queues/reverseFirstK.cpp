#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

int main(){
    deque<int> q;
    int k = 3; // Number of elements to reverse from the front

    // taking input in deque (1, 2, 3, 4, 5)
    for(int i=1; i<=5; i++){
       q.push_back(i);
    }

    // Step : 1 Create a stack which will have elements of q till k
    stack<int> s;

    // Step : 2 Pop the first k elements from the deque and push them into the stack
    while(k <= q.size()){
        s.push(q.front());
        q.pop_front();
    }
    // for(int i=0; i<k; i++){
    //     s.push(q.front());
    //     q.pop_front();
    // }
    
    // Step : 3 Push the reversed elements from the stack back into the deque
    while(!s.empty()){
        q.push_back(s.top());
        s.pop();
    }

    // Step : 4 To restore the order of the remaining elements, rotate the last (n-k) elements
    for(int i=0; i<q.size()-k; i++){
        q.push_back(q.front());
        q.pop_front();
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop_front();
    }
    
    return 0;
}