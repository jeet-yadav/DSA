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

void middleElement(Node* head){
    // Getting length of the linked list
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    int mid = (len/2) + 1;// Getting middle element

    Node* middleElement = head;
    cout<<"middle element at : "<<mid<<endl;

    while(mid-- > 1){
        middleElement = middleElement -> next;
    }

    cout<<"middle element is : "<<middleElement->data<<endl;
}

void middleElement2(Node* head){
    if(head == NULL || head -> next == NULL){
        cout<<"No Middle Element"<<endl;
        return;
    }
    if(head -> next -> next == NULL){
        cout<<"middle element is : "<<head -> next -> data<<endl;
        return;
    }
    
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
    }

    // This can also be rather than the code above U_U
    // while(fast != NULL && fast->next != NULL){
    //     fast = fast -> next -> next; // fast moves two steps
    //     slow = slow -> next;         // slow moves one step
    // }

    cout<<"middle element is : "<<slow->data<<endl;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    // Inserting data in linked list
    for(int i=2; i<=5; i++){
        insert(head, i);
    }
    // middleElement(head);
    middleElement2(head);
    return 0;
}