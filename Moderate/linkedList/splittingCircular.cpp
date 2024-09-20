#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory freed for : "<<value<<endl;
    }
};
void insertNode(Node* &tail, int element, int d){
    //if list is empty
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        tail -> next = temp;
    }
    else{
        Node* curr = tail;

        while(curr->data != element){
            curr = curr -> next;
        }
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

        if(curr == tail) {
            tail = temp;
        }
    }
}
void print(Node* tail){
    if(tail == NULL){
        cout<<"Empty List"<<endl;
        return;
    }

    Node* temp = tail -> next;
    do {
        cout<<temp -> data<<" ";
       temp = temp -> next;
    } while(temp != tail->next);

    cout<<endl;
}
int main(){
    Node* node1 = new Node(1);
    Node* tail = node1;
    tail->next = node1;

    for(int i=2; i<=6; i++){
        insertNode(tail, i-1, i);
    }

    print(tail);
    cout<<tail -> data<< endl;
    return 0;
}