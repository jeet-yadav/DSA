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
        front == rear ? true : false;
    }
    bool enqueue(int data){
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout<<"Queue is full"<<endl;
            return false;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
        arr[rear] = data;
        return true;
    }
    int dequeue(){
        if(front == -1){return -1;}

        int ans = arr[front];
        arr[front] = -1;
        if(rear == front){
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }
    int frontEl(){
        if(front == rear) {return -1;}
        return arr[front];
    }
};

int main() {
    
    return 0;
}
