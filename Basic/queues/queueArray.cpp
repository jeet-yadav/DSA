#include <iostream>
#include <queue>
using namespace std;

// https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTab=0%3Fsource%3Dyoutube&campaign=LoveBabbar_Codestudio&leftPanelTabValue=PROBLEM&customSource=studio_nav
class Queue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(){
        size = 100;
        arr = new int[size];
        rear = 0;
        rear = 0;
    }
    bool isEmpty(){
        front == rear ? true : false;
    }
    void enqueue(int data){
        if(rear == size){
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[rear++] = data;
    }
    int dequeue(){
        if(front == rear){return -1;}

        int ans  = arr[front];
        arr[front++] = -1;

        if(front == rear){
            front = 0;
            rear = 0;
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
