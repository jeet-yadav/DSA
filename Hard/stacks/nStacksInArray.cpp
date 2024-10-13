#include<iostream>
#include<stack>
using namespace std;

//https://www.naukri.com/code360/problems/n-stacks-in-an-array_1164271

class NStack{
    int *arr;       // Array to store the actual stack elements
    int *top;       // Array to store the top index of each stack
    int *next;      // Array to store the next available index in the array

    int n,s;        // 'n' is the number of stacks, 's' is the total size of the array
    int freespot;   // Keeps track of the next free spot in the array

public:

    // Constructor to initialize the NStack with N stacks and total size S
    NStack(int N, int S){
        n = N;   // Number of stacks
        s = S;  // Total size of the array

        // Initialize array for storing stack elements
        arr = new int[s];

        // Initialize top array where each stack's top is initially -1 (empty stack)
        top = new int[n];
        for(int i=0; i<n; i++){
            top[i] = -1;
        }
        
        // Initialize next array which helps in tracking free spotsyf
        next = new int[s];
        for(int i=0; i<s; i++){
            next[i] = i+1;   // Point each index to the next one as the next free spot
        }
        next[s-1] = -1;     // -1 indicates that the array is full

        // Initial free spot is at index 0 (start of the array)
        freespot = 0;
    }

    // pushes 'X' into the Mth stack. Returns true if it get pushed into the Mth stack else false.
    bool push(int X, int M){
        // Check if there are no free spots left (stack is full)
        if(freespot == -1){return false;}
        
        // Find the first free index in the array
        int index = freespot;

        // Update freespot to the next available spot
        freespot = next[index];

        // Insert the element X into the array at the free index
        arr[index] = X;

        // Link the new element to the previous top element of stack M
        next[index] = top[M-1];

        // Update the top of the Mth stack to the current index
        top[M-1] = index;

        return true;// Element successfully pushed
    }

    // Pops the top element from the Mth stack. Returns the element if successful, -1 if stack is empty
    int pop(int M){
        // Check if the Mth stack is empty
        if(top[M-1] == -1){return false;}

        // Get the index of the top element in the Mth stack
        int index = top[M-1];

        // Update the top of the Mth stack to the next element in the stack
        top[M-1] = next[index];

        // Link the popped index back to the list of free spots
        next[index] = freespot;
        freespot = index;

        // Return the popped element
        return arr[index];
    }
};

int main(){
    // Create an NStack object with 3 stacks and a total size of 6
    NStack n(3, 6);
    
    // Push an element '1' into the first stack (stack 1)
    n.push(1, 1);

    // Pop an element from the first stack (stack 1)
    n.pop(1);
    cout<<"executed successfully"<<endl<<"happy hacking :)"<<endl;
    return 0;
}