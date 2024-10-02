#include<iostream>
#include<stack>
using namespace std;

class Stack{
    // Properties
    public:
        int *arr;
        int top;
        int size;

    // Behaveiour
    Stack(int size){// Constructor
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data){
        if(size - top > 1){
            top++;
            arr[top] = data; 
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(top > -1){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    int peek(){
        if(top > -1){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top < 0)
            return 1;
        else
            return 0;
    }
};

int main(){
    // Basic's Of Staks
    // // Creation
    // stack<int> s;

    // //push operation
    // s.push(5);
    // s.push(10);

    // //pop
    // s.pop();

    // // Top element of Stack
    // cout<<"Top Element : "<<s.top()<<endl;

    // // Check if the Stack is empty or not
    // s.empty() ? cout<<"Empty"<<endl : cout<<"Not Empty"<<endl;

    // // Size of Stack
    // cout<<"Size of Stack : "<<s.size()<<endl;
 
    Stack st(5);
    st.push(35);
    st.push(92);
    st.push(11);
    st.push(13);

    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;

    cout<<st.isEmpty()<<endl;
    return 0;
}