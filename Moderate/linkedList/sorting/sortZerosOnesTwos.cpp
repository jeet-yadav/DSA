#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        data = d;
        next = NULL;
    }

    //destructor
    ~Node(){
        cout<<"Memory freed for: "<<this->data<<endl;
        this->next = NULL;
    }
};
void insertHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void print(Node* &head){
    Node* temp = head;

    cout<<"Linked-List : ";
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
// Counting the number of 0's, 1's and 2's, and then putting them in the linked list
void countSort(Node* &head){
    Node* temp = head;
    int count0 = 0,count1 = 0,count2 = 0;
    while(temp != NULL){
        if(temp -> data == 0){
            count0++;
        }
        else if(temp -> data == 1){
            count1++;
        }
        else{
            count2++;
        }
        temp = temp -> next;
    }

    temp = head;
    while(temp != NULL){
        if(count0 != 0){
            temp -> data = 0;
            count0--;
        }
        else if(count1 != 0){
            temp -> data = 1;
            count1--;
        }
        else{
            temp -> data = 2;
        }
        temp = temp -> next;
    }
}

// Sorting without changing the data
void insertTail(Node* &tail, Node* curr){
    tail -> next = curr;
    tail = curr;
}

void sort(Node* &head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    // Create seprate list for 0's, 1's and 2's
    while(curr != NULL){
        int value = curr -> data;
        if(value == 0){
            insertTail(zeroTail, curr);
        }
        else if(value == 1){
            insertTail(oneTail, curr);
        }
        else if(value == 2){
            insertTail(twoTail, curr);
        }
        curr = curr -> next;
    }

    // Merge the three lists

    // If 1st list is not empty
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    }
    else{
        // If 1st list is empty
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    // Update head to point to the new list's start
    head = zeroHead -> next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    insertHead(head,0);
    insertHead(head,1);
    insertHead(head,0);
    insertHead(head,2);
    insertHead(head,1);
    insertHead(head,2);
    print(head);

    sort(head);
    print(head);
    return 0;
}