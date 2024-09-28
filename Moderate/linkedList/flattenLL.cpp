#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> child = NULL;
    }
};

void insertTail(Node* &tail, int d){
    Node* temp = new Node(d);
    if(tail == NULL){
        tail = temp;
        // tail -> next = NULL;
    }
    else{
        tail -> next = temp;
        tail = temp;
    }
}
void insertChild(Node* parent, int d){
    Node* temp = new Node(d);

    if(parent->child == NULL){
        parent->child = temp;
    }
    else{
        Node* childTail = parent->child;

        while(childTail->next != NULL){
            childTail = childTail->next;
        }
        childTail->next = temp;
    }
}
void printChild(Node* child){
    while(child != NULL){
        cout<<child->data<<" ";
        child = child->next;
    }
}
void print(Node* head){
    if(head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    cout<<"Linked List : ";
    while(head != NULL){
        cout<<head -> data<<" ";

        if(head->child != NULL){
            cout << "[Child: ";
            printChild(head->child);
            cout << "] ";
        }
        head = head -> next;
    }
    cout<<endl;
}
void flatten(Node* head){
    if(head == NULL) return;
    
    Node* curr = head;

    while(curr != NULL){
        if(curr -> child != NULL){
            Node* nextNode = curr -> next;

            curr -> next = curr -> child;
            curr -> child = NULL;

            Node* temp = curr -> next;
            while(temp->next != NULL){
                temp = temp -> next;
            }
            
            temp -> next = nextNode;
        }
        curr = curr -> next;
    }
}
int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertChild(tail,2);
    insertChild(tail,3);

    insertTail(tail,4);
    insertChild(tail,5);
    insertChild(tail,6);

    insertTail(tail,7);
    insertChild(tail,8);

    insertTail(tail,9);
    insertChild(tail,12);

    insertTail(tail,20);

    print(head);
    flatten(head);
    print(head);
    return 0;
}