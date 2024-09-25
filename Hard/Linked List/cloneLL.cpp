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
};
void insertTail(Node* &tail, int data){
    if(tail == NULL){
        return;
    }
    Node* temp = new Node(data);
    tail -> next = temp;
    temp -> next = NULL;
    tail = temp;
}
void print(Node* head){
    if(head==NULL){
        return;
    }
    cout<<"Linked List : ";
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
void clone(Node* head, Node* head2){
    if(head2 == NULL){
        Node* temp = new Node(head -> data);
        head2 = temp;
        head2 -> next = NULL;
        head = head -> next;
    }
    else{
        head = head -> next;
    }
    while(head != NULL){
        Node* newNode = new Node(head -> data);
        head = head -> next;
        head2 -> next = newNode;
        head2 = head2 -> next;
        newNode -> next = NULL;
    }
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertTail(tail,2);
    insertTail(tail,3);
    insertTail(tail,4);
    insertTail(tail,5);
    print(head);

    // Node* clonedList = new Node(node1 -> data);
    Node* head2 = NULL;
    // Node* tail2 = clone;
    clone(head,head2);
    print(head2);
    return 0;
}