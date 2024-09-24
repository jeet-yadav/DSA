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
    // Base case: if the list is empty or contains only one node, it's already reversed
    if(head == NULL || head -> next == NULL){
        return;
    }
    // Store the next node in a temporary pointer before recursive call
    // This ensures we don't lose the rest of the list
    Node* temp = head -> next;

    // Recursively reverse the rest of the list from the second node onwards
    Reverse(temp);

    // After recursion: head->next now points to the last node in the reversed sublist
    // So, set the next of this node (head->next) to the current node (head) to reverse the link
    head -> next -> next = head;

    // Break the original forward link by setting the current node's next pointer to NULL
    // This step ensures the last node in the reversed list doesn't point to the next node
    head -> next = NULL;//This line so hard to digest for my brain but now i now, and its beautiful
    
    // Update the head pointer to the new head (the one returned after recursion)
    head = temp;
}

Node* Reverse2(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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