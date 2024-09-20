#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node *next;

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

void insertHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void insertTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
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

// for sorted linked list
void removeDuplicates(Node* &head){//my solution
    if(head == NULL){
        cout<<"No elements";
        return;
    }
    Node* curr = head;
    Node* next = NULL;

    while(curr->next != NULL){
        next = curr -> next;
        if(curr -> data == next -> data){
            curr -> next = next -> next;
            next -> next = NULL;
            delete next;
        }
        else{
            curr = curr -> next;
        }
    }
}

// for sorted linked list
void removeDuplicates2(Node* &head){//babbar solution
    if(head == NULL){
        cout<<"No elements";
        return;
    }
    Node* curr = head;

    while(curr != NULL){
        if((curr -> next != NULL) && curr -> data == curr -> next -> data){
            Node* next_node = curr -> next -> next;
            Node* nodeTodelete = curr -> next;
            delete nodeTodelete;
            curr -> next = next_node;
        }
        else{
            curr = curr -> next;
        }
    }
}

//for unsorted linked list
void removeDuplicates3(Node* &head){//
    if(head == NULL){
        cout<<"No elements";
        return;
    }
    Node* curr = head;

    while(curr != NULL){
        Node* temp = curr -> next;

        while(temp != NULL && temp->next != NULL){
            if(temp -> next -> data == curr -> data){
                Node* todelete = temp -> next;
                temp -> next = temp -> next -> next;
                todelete -> next = NULL;
                delete todelete;
            }
            else{
                temp = temp -> next;
            }
        }
        curr = curr -> next;
    }
}

int main(){
    // Node* node1 = new Node(1);
    // Node* head = node1;
    // Node* tail = node1;

    // for(int i=2; i<=10; i++){
    //     if(i == 2 || i == 5 || i == 10){
    //         insertTail(tail, i);
    //     }
    //     insertTail(tail, i);
    // }
    // print(head);
    // removeDuplicates(head);
    // print(head);

    Node* node2 = new Node(2);
    Node* head2 = node2;
    Node* tail2 = node2;
    insertTail(tail2, 1);
    insertTail(tail2, 4);
    insertTail(tail2, 2);
    insertTail(tail2, 3);
    print(head2);
    removeDuplicates3(head2);
    print(head2);
    return 0;
}