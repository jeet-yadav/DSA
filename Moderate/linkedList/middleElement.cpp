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

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    // Inserting data in linked list
    for(int i=2; i<=5; i++){
        insert(head, i);
    }

    // Getting length of the linked list
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }

    return 0;
}