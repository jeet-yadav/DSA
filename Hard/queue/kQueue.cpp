#include<iostream>
#include<queue>
using namespace std;

class kQueue{
    int n;           // Size of the array for storing elements
    int k;           // Number of queues
    int *arr;        // Array to store queue elements
    int *front;      // Array to store the index of the front of each queue
    int *rear;       // Array to store the index of the rear of each queue
    int *next;       // Array to manage the next free index for insertion and to maintain the linked list structure within each queue
    int freespot;    // Index of the next available free spot in the `arr`

public:
    // Constructor to initialize kQueue with size `n` and `k` queues
    kQueue(int n, int k){
        this -> n = n;
        this -> k = k;

        // Allocate memory for the main array
        arr = new int[n];

        // Allocate memory and initialize front and rear pointers for each queue to -1 (indicating they are empty)
        front = new int[k];
        rear = new int[k];
        for(int i=0; i<k; i++){
            front[i] = -1;  // Indicates the queue is initially empty
            rear[i] = -1;   // Indicates the queue is initially empty
        }

        // Initialize the `next` array, where each index points to the next free spot
        next = new int[n];
        for(int i=0; i<n; i++){
            next[i] = i+1;// Link to the next index
        }
        next[k-1] = -1;// Last element in `next` array should point to -1 as there's no next free spot

        freespot = 0;// Initially, the first free spot is 0
    }

    void enQueue(int qn, int data){
        // Check Overflow
        if(freespot == -1){
            cout<<"Queue is full"<<endl;
            return;
        }
        // Get the index of the next free spot
        int index = freespot;

        // Update the free spot to the next available index
        freespot = next[index];

        // If its the firs element
        if(front[qn-1] == -1){
            front[qn-1] = index;
        }
        else{
            // Link the previous element to the new element
            next[rear[qn-1]] = index;
        }

        // Update the next of the current element to -1 (end of the queue)
        next[index] = -1;

        // Update the rear pointer for the queue
        rear[qn-1] = index;

        // Insert the data in the array
        arr[index] = data;
        return;
    }

    void deQueue(int qn){

        // Underflow
        if(front[qn-1] == -1){
            cout<<"Queue is empty"<<endl;
            return;
        }
        // find index to pop
        int index = front[qn-1];

        // update front
        front[qn-1] = next[index];

        // front is moved so the next index if free and point to next freespot
        next[index] = freespot;

        // put freespot to index
        freespot = index;
        cout<<"Popped element : "<<arr[index]<<endl;
    }
};

int main(){

    return 0;
}