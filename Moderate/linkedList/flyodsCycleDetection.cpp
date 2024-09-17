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

// Floyd’s Cycle Detection Algorithm
Node* detectLoop(Node* head){
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast )
            return slow;
    }
    return NULL;
}

// Function to detect if there is a loop using Floyd's cycle detection algorithm
Node* floydDetectLoop(Node* head) {
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) 
            fast = fast -> next;

        slow = slow -> next;

        if(slow == fast)
            return slow;
    }
    return NULL;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    for(int i=2; i<=10; i++){
        insert(head, i);
    }
    print(head);

    Node* loopNode = detectLoop(head);
    if(loopNode != NULL) {
        cout<<"Loop detected at node with data: "<<loopNode->data<<endl;
    } else {
        cout<<"No loop detected"<<endl;
    }
    return 0;
}