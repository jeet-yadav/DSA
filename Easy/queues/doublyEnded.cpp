#include<iostream>
#include<queue>
using namespace std;

class DeQueue{
    int *arr;
    int size;
    int front;
    int rear;

public:
    DeQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool pushFront(int data){
        if((front == 0 && rear == size-1) || ((rear+1) % size == front)){
            cout<<"Queue is full";
            return false;
        }

        if(front == -1){
            front = rear = 0;
        }
        else if(front == 0){
            front = size - 1;
        }
        else{
            front--;
        }

        arr[front] = data;
        cout<<"element pushed at "<<front<<endl;
        return true;
    }

    bool pushRear(int data){
        if((front == 0 && rear == size-1) || ((rear+1) % size == front)){
            cout<<"Queue is full";
            return false;
        }

        if(front == -1){
            front = rear = 0;
        }
        else if(rear == size - 1){
            rear = 0;
        }
        else{
            rear++;
        }

        arr[rear] = data;
        cout<<"element pushed at "<<rear<<endl;
        return true;
    }

    int popFront(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){
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

    int popRear(){
        if(rear == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear){
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size-1;
        }
        else{
            rear--;
        }
        return ans;
    }

    int getFront(){
        if(front == -1){
            return -1;
        }
        return arr[front];
    }

    getRear(){
        if(rear == -1){
            return -1;
        }
        return arr[rear];
    }

    bool isFUll(){
        if((front == 0 && rear == size-1) || (rear+1)%size == front){
            return true;
        }
        return false;
    }
};

int main(){
    DeQueue dq(5);

    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushFront(5);

    cout << "Popped from front: " << dq.popFront() << endl;
    cout << "Popped from rear: " << dq.popRear() << endl;
    
    dq.pushRear(30);
    dq.pushFront(1);
    return 0;
}