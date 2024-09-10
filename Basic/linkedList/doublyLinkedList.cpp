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

// Inserting new node at front
void insertHead(Node* &head, Node* &tail, int d){
    //for creating first node, but we already created the first node in main function
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

// Insertion at the end
void insertTail(Node* &head, Node* &tail, int d){
    //for creating first node, but we already created the first node in main function
    if(tail == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
        return;
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
        insertHead(head,tail,d);
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
        insertTail(head,tail,d);
        return;
    }

    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    temp -> next -> prev = newNode;
    temp -> next = newNode;
    newNode -> prev = temp;
}

void deleteNode(Node* &head, Node* &tail, int position){
    //deleting first node
    if(position == 1){
        head -> next -> prev = NULL;
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

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        if(curr->next != NULL)
            curr->next->prev = prev;
        
        delete curr;
        if(prev -> next == NULL){
            tail = prev;
        }
    }

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
    insertHead(head,tail,1);
    insertHead(head,tail,2);
    insertHead(head,tail,3);
    insertTail(head,tail,6);
    print(head);
    cout<<"Head : "<<head -> data<<endl;
    cout<<"Tail : "<<tail -> data<<endl;
    insertPosition(head,tail,6,69);
    print(head);
    cout<<"Head : "<<head -> data<<endl;
    cout<<"Tail : "<<tail -> data<<endl;
    deleteNode(head,tail,5);
    print(head);
    cout<<"Head : "<<head -> data<<endl;
    cout<<"Tail : "<<tail -> data<<endl;
    return 0;
}