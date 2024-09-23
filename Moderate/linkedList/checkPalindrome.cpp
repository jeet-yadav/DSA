#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

void insert(Node* &head, int d){
    Node* newNode = new Node(d);
    newNode -> next = head;
    head = newNode;
}

void print(Node* head){
    head == NULL ? cout<<"Empty" : cout<<endl;
    cout<<"Linked-List : ";
    while(head != NULL){
        cout<<head -> data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

int length(Node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head -> next;
    }
    return len;
}

void palindrome(Node* head){// My Solution
    int len = length(head);
    int* arr = new int[len];
    int i = 0;

    Node* temp = head;
    while(temp != NULL){
        arr[i++] = temp -> data;
        temp = temp -> next;
    }

    for(i=0; i<len/2; i++){
        if(arr[i] != arr[len-1-i]){
            cout<<"Not Palindrome"<<endl;
            return;
        }
    }
    cout<<"Palindrome"<<endl;
    delete arr;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);

    print(head);
    palindrome(head);
    return 0;
}