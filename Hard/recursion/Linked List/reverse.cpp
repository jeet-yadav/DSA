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

void Reverse(Node* &head){
    if(head == NULL || head -> next == NULL){
        return;
    }
    Node* temp = head -> next;
    Reverse(temp);
    head -> next -> next = head;
    head -> next = NULL;
    head = temp;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    for(int i=2; i<=5; i++){
        insert(head, i);
    }

    cout<<"Original : ";
    print(head);

    cout<<"Reverse : ";
    Reverse(head);
    print(head);
    return 0;
}