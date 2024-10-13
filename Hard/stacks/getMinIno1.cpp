#include<iostream>
#include<stack>
using namespace std;
//https://www.naukri.com/code360/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465

class SpecialStack{
    stack<int> s;   // Stack to store elements
    int mini;   // Variable to store the current minimum element

public:
    // Pushes an element onto the stack
    void push(int data){
        //if the stack is empty push the element and is the data pushed is also mini
        if(s.empty()){
            s.push(data);   // Push the element directly
            mini = data;    // Set it as the minimum
        }                  
        else{
            // If the new element is smaller than the current minimum
            if(data < mini){
                // Push a modified value to store the difference
                int val = (2 * data) - mini;
                s.push(val);    // Push the modified value
                mini = data;    // Update the minimum
            }
            else{
                //if the data is greater than previous mini just push it
                s.push(data);   // Push it directly
            }
        }
    }

    // Pops the top element from the stack
    int pop(){
        if(s.empty()){return -1;}   // Return -1 if the stack is empty

        int curr = s.top();     // Get the top element
        s.pop();    // Remove the top element

        // If the top element is greater than or equal to the minimum
        if(curr > mini){
            return curr;    // Return the popped element directly
        }
        else{
            // If the top element is a distorted value
            int prevMin = mini; // Store the current minimum to return
            int val = 2 * mini - curr;  // Restore the previous minimum using the formula
            mini = val;
            return prevMin; // Return the previous minimum
        }
    }

    // Returns the top element of the stack without removing it
    int top(){
        if(s.empty()){return -1;}// Return -1 if the stack is empty

        int curr = s.top();// Get the top element

        // If the top element is less than the current minimum (distorted value)
        if(curr < mini){
            return mini;    // Return the current minimum
        }
        else{
            return curr;    // Otherwise, return the top element
        }
    }

    // Checks if the stack is empty
    bool isEmpty(){
        return s.empty(); 
    }

    // Returns the minimum element in the stack
    int getMin(){
        if(s.empty()){return -1;}   // Return -1 if the stack is empty

        return mini;    // Return the current minimum
    }
};

int main(){
    SpecialStack s;
    s.push(10);
    s.push(20);
    cout<<s.getMin()<<endl;
    s.push(5);
    s.push(3);
    cout<<s.getMin()<<endl;
    return 0;
}