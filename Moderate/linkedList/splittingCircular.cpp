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
            this -> next = NULL;
        }
        cout<<"Memory freed for : "<<value<<endl;
    }
};
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

        if(curr == tail) {
            tail = temp;
        }
    }
}
void print(Node* tail){
    if(tail == NULL){
        cout<<"Empty List"<<endl;
        return;
    }

    Node* temp = tail -> next;
    do {
        cout<<temp -> data<<" ";
       temp = temp -> next;
    } while(temp != tail->next);

    cout<<endl;
}
int length(Node* tail){
    if(tail == NULL){
        return 0;
    }
    Node* temp = tail -> next;
    int count = 1;
    
    while(temp != tail){
        temp = temp -> next;
        count++;
    }
    return count;
}
Node* split(Node* head, Node* tail){
    int len = length(tail);

    Node* temp = head;
    int i=0;
    while(i < (len/2)-1){
        temp = temp -> next;
        i++;
    }
    Node* head2 = temp -> next;
    Node* temp2 = temp -> next;
    temp -> next = head;

    while(temp2 != tail){
        temp2 = temp2 -> next;
    }
    tail -> next = head2;
    return head2;
}
Node* split2(Node* head, Node* &tail){
    int len = length(tail);

    Node* temp = head;
    int i=0;
    while(i < (len/2)-1){
        temp = temp -> next;
        i++;
    }
    Node* head2 = temp -> next;
    Node* tail2 = tail;
    tail = temp;
    temp -> next = head;
    
    Node* temp2 = temp -> next;

    while(temp2 != tail){
        temp2 = temp2 -> next;
    }
    tail2 -> next = head2;
    return tail2;
}
int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    tail->next = node1;

    for(int i=2; i<=6; i++){
        insertNode(tail, i-1, i);
    }

    print(tail);
    cout<<"tail is "<< tail -> data<< endl;
    cout<<"length is "<<length(tail)<<endl;

    Node* tail2 = split2(head, tail);
    print(tail);
    print(tail2);
    return 0;
}