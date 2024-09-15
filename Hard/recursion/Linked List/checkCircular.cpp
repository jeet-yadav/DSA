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
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

void checkCircular(Node* &head){
    if(head == head -> next){
        cout<<"Circular List"<<endl;
        return;
    }

    Node* temp = head -> next;
    while(temp != NULL){
        if(temp == head){
            cout<<"Circular List"<<endl;
            return;
        }
        temp = temp -> next;
    }
    cout<<"Non-Circular List"<<endl;
}

void checkCircular2(Node* &head){
    if(head == head -> next){
        cout<<"Circular List"<<endl;
        return;
    }

    Node* temp = head -> next;
    while(temp != NULL || temp == head){
        temp = temp -> next;
    }
    if(temp == head){
        cout<<"Circular List"<<endl;
    }
    else{
        cout<<"Non-Circular List"<<endl;
    }
}

int main(){
    // Declaring first node
    Node* node1 = new Node(10);
    Node* head = node1;// Head pointing to node1

    //creating and insertind data in linke lsit from 2 to 5
    for(int i=9; i>0; i--){
        insert(head, i);
    }
    cout<<"Linked-List : ";
    print(head);

    checkCircular2(head);
    return 0;
}