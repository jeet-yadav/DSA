#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        data = d;
        next = NULL;
    }

    //destructor
    ~Node(){
        cout<<"Memory freed for: "<<this->data<<endl;
        this->next = NULL;
    }
};
void insertHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
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
void merge(Node* head1, Node* &head2){// My Solution
    // if head1 is empty
    if(head1 == NULL){
        cout<<"List 1 is empty"<<endl;
        return;
    }
    // if head2 is empty
    if(head2 == NULL){
        cout<<"List 2 is empty"<<endl;
        return;
    }

    Node* temp1 = head1;
    Node* temp2 = head2;

    // Traverse both lists and merge nodes in the correct position
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->next != NULL && (temp1 -> data <= temp2 -> data) && (temp2 -> data <= temp1 -> next -> data)){
            Node* temp1Next = temp1 -> next;
            temp1 -> next = temp2;
            temp2 = temp2 -> next;
            temp1->next->next = temp1Next;
        }
        temp1 = temp1 -> next;
    }
    if(temp1 == NULL && temp2 != NULL){
        temp1 = head1;
        while(temp1->next != NULL){ // Find the end of the list
            temp1 = temp1->next;
        }
        temp1->next = temp2;
    }
}

int main(){
    Node* node1 = new Node(7);
    Node* head1 = node1;

    insertHead(head1,6);
    insertHead(head1,3);
    insertHead(head1,1);

    Node* node2 = new Node(8);
    Node* head2 = node2;

    insertHead(head2,5);
    insertHead(head2,4);
    insertHead(head2,2);

    print(head1);
    print(head2); 
    merge(head1, head2);
    print(head1);
    return 0;
}