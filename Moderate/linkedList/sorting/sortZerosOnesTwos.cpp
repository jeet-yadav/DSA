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
    Node* temp2 = head;

    while(count0 > 0){
        temp2 -> data = 0;
        count0--;
        temp2 = temp2 -> next;
    }
    while(count1 > 0){
        temp2 -> data = 1;
        count1--;
        temp2 = temp2 -> next;
    }
    while(count2 > 0){
        temp2 -> data = 2;
        count2--;
        temp2 = temp2 -> next;
    }
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

    countSort(head);
    print(head);
    return 0;
}