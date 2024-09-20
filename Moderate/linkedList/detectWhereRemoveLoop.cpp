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

// Function to detect if there is a loop using Floyd's cycle detection algorithm
Node* whereLoopStarts1(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    Node* noLoop;
    while(fast != NULL && fast -> next != NULL){

        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){// Loop detected
            slow = head;

            // Move both pointers one step at a time until they meet
            while(slow != fast){
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }
    }
    return NULL;
}

// Floyd’s Cycle Detection Algorithm
Node* floydDetectLoop(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast ){
            return slow;
        }
    }
    return NULL;
}

Node* whereLoopStarts2(Node* head){// Babbar solution
    if(head == NULL)
        return NULL;

    Node* intersection = floydDetectLoop(head);
    if(intersection == NULL)
        return NULL;

    Node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head == NULL)
        return;
    Node* startOfLoop = whereLoopStarts2(head);
    Node* temp = startOfLoop;
    while(temp -> next != startOfLoop){
        temp = temp -> next;
    }
    temp -> next = NULL;
    cout<<"Loop removed"<<endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    for(int i=9; i>0; i--){
        insertNormal(head, i);// Inserting in List
    }

    cout<<"Linked-List : ";
    print(head);
    
    Node* head2 = node1;
    Node* tail = NULL;
    insertCircular(tail,0,1);
    insertCircular(tail,1,2);
    insertCircular(tail,2,3);
    insertCircular(tail,3,4);

    cout<<"Circular Linked-List : ";
    printCircular(tail);

    Node* loop1 = whereLoopStarts2(head);
    if(loop1 != NULL) {
        cout<<"Loop detected at node with data: "<<loop1->data<<endl;
    } else {
        cout<<"No loop detected"<<endl;
    }

    Node* loop2 = whereLoopStarts2(tail);
    if(loop2 != NULL) {
        cout<<"Loop detected at node with data: "<<loop2->data<<endl;
    } else {
        cout<<"No loop detected"<<endl;
    }

    removeLoop(tail);
    Node* loop3 = whereLoopStarts2(tail);
    if(loop3 != NULL) {
        cout<<"Loop detected at node with data: "<<loop3->data<<endl;
    } else {
        cout<<"No loop detected"<<endl;
    }
    return 0;
}