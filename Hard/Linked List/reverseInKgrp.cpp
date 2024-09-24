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

Node* KthRecursion(Node* &head, int k){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    // Reverse first k nodes
    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // After reversing, next is the (k+1)th node, and head is the kth node
    if(next != NULL){
        head -> next = KthRecursion(next,k);
    }
    return prev;// prev is the new head of this segment
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

    head = KthRecursion(head,2);
    print(head);
    return 0;
}