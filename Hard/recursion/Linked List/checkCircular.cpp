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

void insertNormal(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
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

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
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

void checkCircular(Node* &head){
    if(head == head -> next){
        cout<<"Circular List"<<endl;
        return;
    }

    Node* temp = head -> next;
    while(temp != NULL){
        if(temp == head){
            cout<<"Circular List"<<endl;
            return;
        }
        temp = temp -> next;
    }
    cout<<"Non-Circular List"<<endl;
}

void checkCircular2(Node* &head){
    if(head == head -> next){
        cout<<"Circular List"<<endl;
        return;
    }

    Node* temp = head -> next;
    while(temp != NULL || temp == head){
        temp = temp -> next;
    }
    if(temp == head){
        cout<<"Circular List"<<endl;
    }
    else{
        cout<<"Non-Circular List"<<endl;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    for(int i=9; i>0; i--){
        insertNormal(head, i);// Inserting in Normal List
    }

    Node* tail = NULL;
    insertCircular(tail,0,1);
    insertCircular(tail,1,2);
    insertCircular(tail,2,3);

    cout<<"Linked-List : ";
    print(head);
    checkCircular2(head);

    cout<<"Circular Linked-List : ";
    printCircular(tail);
    checkCircular(tail);
    return 0;
}