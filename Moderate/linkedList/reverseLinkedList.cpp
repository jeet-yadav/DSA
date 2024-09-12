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
            next = NULL;
        }
    }
};

void insert(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

void reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

void reverseRecursion(Node* &head,Node* prev,Node* &curr,Node* &forward){
    if(curr == NULL){
        head = prev;
        return;
    }

    forward = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = forward;

    reverseRecursion(head,prev,curr,forward);
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    for(int i=2; i<=5; i++){
        insert(head, i);
    }
    print(head);
    // reverse(head);

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    reverseRecursion(head,prev,curr,forward);
    print(head);
    return 0;
}