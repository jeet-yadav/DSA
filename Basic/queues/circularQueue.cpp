#include <iostream>
#include <queue>
using namespace std;

//https://www.naukri.com/code360/problems/circular-queue_1170058?leftPanelTab=0%3Fsource%3Dyoutube&campaign=LoveBabbar_Codestudio

class Queue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }
    bool isEmpty(){
        return front == -1;
    }
    bool enqueue(int data){
        // Check if the queue is full
        if((front == 0 && rear == size-1) || ((rear + 1) % size == front)){
            return false;
        }

        // If queue is empty
        else if(front == -1){
            front = rear = 0;
        }

        // Circular wrap-around case
        else if(rear == size-1 && front != 0){
            rear = 0;
        }

        // Normal case
        else{
            rear++;
        }

        // Insert the element at the rear position
        arr[rear] = data;
        return true;
    }

    int dequeue(){
        // Queue is empty
        if(front == -1){return -1;}

        int ans = arr[front];
        arr[front] = -1;// Optional: mark as removed

        // If only one element was in the queue
        if(rear == front){
            front = rear = -1;
        }

        // Circular wrap-around case
        else if(front == size-1){
            front = 0;
        }

        // Normal case
        else{
            front++;
        }
        return ans;
    }
    int frontEl(){
         // Return the front element, handle case where queue is empty
        if(front == rear) {return -1;}
        return arr[front];
    }
};

int main() {
    
    return 0;
}
