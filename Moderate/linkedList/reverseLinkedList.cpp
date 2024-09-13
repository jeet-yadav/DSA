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

void advanceRecursion(Node* &head){
    if(head == NULL || head -> next == NULL){
        return;
    }
    Node* temp = head -> next;
    advanceRecursion(temp);
    head -> next -> next = head;
    head -> next = NULL;
    head = temp;// How the fuck is this working
}

// void advanceRecursion2(Node* &head){// by babbar
//     if(head == NULL || head -> next == NULL){
//         return;
//     }
//     Node* val = advanceRecursion(head -> next);
//     head -> next -> next = head;
//     head -> next = NULL;
//     return val;
// }

int main(){
    // Declaring first node
    Node* node1 = new Node(1);
    Node* head = node1;// Head pointing to node1

    //creating and insertind data in linke lsit from 2 to 5
    for(int i=2; i<=5; i++){
        insert(head, i);
    }
    cout<<"Linked-List : ";
    print(head);

    cout<<"Reverse Linked-List : ";
    reverse(head);
    print(head);

    cout<<"Again Reverse using recursion : ";
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    reverseRecursion(head,prev,curr,forward);
    print(head);

    cout<<"Again Reverse using gud-recursion : ";
    advanceRecursion(head);
    print(head);
    return 0;
}