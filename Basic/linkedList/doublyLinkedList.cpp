#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

// Inserting new node at front
void insertHead(Node* &head, int d){
    //for creating first node, but we already created the first node in main function
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
    }
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

// Insertion at the end
void insertTail(Node* &tail, int d){
    //for creating first node, but we already created the first node in main function
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
    }
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    temp -> next = NULL;
    tail = temp;
}

// Insert at any position
void insertPosition(Node* &head, Node* &tail, int position, int d){
    //for inserting in first position
    if(position == 1){
        insertHead(head,d);
        return;
    }

    int cnt = 1;
    Node* temp = head;
    
    while(cnt < position-1){
        cnt++;
        temp = temp -> next;
    }

    //if inserting in last position
    if(temp -> next == NULL){
        insertTail(tail,d);
        return;
    }

    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    temp -> next -> prev = newNode;
    temp -> next = newNode;
    newNode -> prev = temp;
}

// Traversing in Linked list
void print(Node* head){
    Node* temp = head;

    cout<<"Linked-List : ";
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}


//Gives length of Linked list 
void getLength(Node* head){
    int len = 0;    
    while(head != NULL){
        len++;// Increment length
        head = head -> next;// Move to the next node
    }
    cout<<"length : "<<len<<endl;
}

int main(){
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    getLength(head);
    insertHead(head,1);
    insertHead(head,2);
    insertHead(head,3);
    insertTail(tail,6);
    print(head);
    cout<<"Head : "<<head -> data<<endl;
    cout<<"Tail : "<<tail -> data<<endl;
    insertPosition(head,tail,6,69);
    print(head);
    cout<<"Head : "<<head -> data<<endl;
    cout<<"Tail : "<<tail -> data<<endl;
    return 0;
}