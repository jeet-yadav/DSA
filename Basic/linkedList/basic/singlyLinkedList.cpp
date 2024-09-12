#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node *next;// Pointer to next node

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory freed for : "<<value<<endl;
    }
};

//inserting element at front
void insertHead(Node* &head, int d){
    Node* temp = new Node(d);//create new node ant put data in it
    temp -> next = head;//new node's next will point to where head is pointing,(left most node)
    head = temp;//head will point to new element
}

//inserting element at the end
void insertTail(Node* &tail, int d){
    Node* temp = new Node(d);//create new element and put data in it
    tail -> next = temp;//In tail's next put temp,(new element address)
    tail = temp;//Increment tail to new element, as new element is tail now
}

//inserting element in between
void insertPosition(Node* &head, Node* &tail, int position, int d){
    if(position == 1){
        insertHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1){
        temp = temp -> next;
        cnt++;
    }
    // if(temp -> next == NULL){
    //     insertTail(tail,d);
    //     return;
    // }
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
    
    //this code can also be used instead of code commented above 
    if(nodeToInsert -> next == NULL){
        tail = nodeToInsert;
    }
}

void deleteNode(Node* &head, Node* &tail, int position){
    //deleting first node
    if(position == 1){
        Node* temp = head;
        head = head -> next;//pointing head to next node
        temp -> next = NULL;
        delete temp;//deleting previous head
    }
    else{
        //deleting element in middle
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        cout<<"Deleting "<<curr -> data<<endl;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
        if(prev -> next == NULL){
            tail = prev;
        }
    }

}

void print(Node* &head){
    Node* temp = head;

    cout<<"Linked-List : ";
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;

    insertTail(tail, 7);
    insertTail(tail, 8);
    insertPosition(head,tail,4,6);
    print(head);
    cout<<"Head : "<<head -> data<<endl;
    cout<<"Tail : "<<tail -> data<<endl;
    deleteNode(head,tail,4);
    print(head);
    cout<<"Head : "<<head -> data<<endl;
    cout<<"Tail : "<<tail -> data<<endl;
    return 0;
}