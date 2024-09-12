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
        cout<<"Memory freed for : "<<value<<endl;
    }
};

//inserting node in middle
void insertNode(Node* &tail, int element, int d){
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

//deletion
void deleteNode(Node* &tail, int element){
    // If the list is empty
    if(tail == NULL){
        cout<<"waht you tryna delete, it's already [EMPTY, M-PTY, M-PTY, EM-T, MT,  ]";
        return;
    }

    Node* prev = tail;
    Node* curr = prev -> next;

    while(curr->data != element){
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = curr -> next;

    //for single element in list
    if(curr == prev){
        tail = NULL;
    }

    //for more than 1 elements in list
    if(tail == curr){
        tail = prev;
    }

    curr -> next = NULL;
    delete curr;
}

void print(Node* tail){
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
int main(){
    Node* tail = NULL;
    insertNode(tail,5,3);
    insertNode(tail,3,5);
    insertNode(tail,3,4);
    print(tail);
    deleteNode(tail,3);
    print(tail);
    cout<<"Tail : "<<tail -> data<<endl;
    return 0;
}