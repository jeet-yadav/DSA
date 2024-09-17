#include<iostream>
#include<map>
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

void insertNormal(Node* &head, int d){
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
void insertCircular(Node* &tail, int element, int d){
    //if list is empty
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        tail -> next = temp;
    }
    else{
        Node* curr = tail;

        while(curr->data != element){
            curr = curr -> next;
        }
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}
void printCircular(Node* tail){
    Node* temp = tail;
    
    if(tail == NULL){
        cout<<"Empty List"<<endl;
    }

    //Do while is best for situation like this, Used it first time W_W
    do {
        cout<<tail -> data<<" ";
        tail = tail -> next;
    } while(tail != temp);

    cout<<endl;
}
void printC(Node* tail){
    Node* temp = tail;
    
    if(tail == NULL){
        cout<<"Empty List"<<endl;
    }

    //Do while is best for situation like this, Used it first time W_W
    do {
        cout<<tail -> data<<" ";
        tail = tail -> next;
    } while(tail != temp);

    cout<<endl;
}

// Floyd’s Cycle Detection Algorithm
bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL || fast -> next != NULL){
        if(slow == fast ){
            return true;
        }
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return false;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    for(int i=9; i>0; i--){
        insertNormal(head, i);// Inserting in List
    }

    cout<<"Linked-List : ";
    print(head);
    
    Node* tail = NULL;
    insertCircular(tail,0,1);
    insertCircular(tail,1,2);
    insertCircular(tail,2,3);
    insertCircular(tail,3,4);

    cout<<"Circular Linked-List : ";
    printC(tail);

    // Currently checking for circular list, update tail to head il line below to check for normal list
    if(detectLoop(tail)){
        cout<<"Loop Found"<<endl;
    }
    else{
        cout<<"Loop Not Found"<<endl;
    }
    return 0;
}