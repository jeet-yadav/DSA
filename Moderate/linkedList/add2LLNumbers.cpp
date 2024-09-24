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
    if(head == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    head == NULL ? cout<<"Empty" : cout<<"";
    cout<<"Linked-List : ";
    while(head != NULL){
        cout<<head -> data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

void reverse(Node* &head){
    if(head == NULL || head-> next == NULL){
        return;
    }
    Node* temp = head -> next;
    reverse(temp);
    head -> next -> next = head;
    head -> next = NULL;
    head = temp;
}
void insertTail(Node* &head,Node* &tail, int val){
    Node* temp = new Node(val);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    else{
        tail -> next = temp;
        tail = temp;
    }
}
Node* add(Node* first, Node* second){
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;
    while(first != NULL || second != NULL || carry != 0){
        int val1 = 0;
        if(first != NULL){
            val1 = first -> data;
        }
        
        int val2 = 0;
        if(second != NULL){
            val2 = second -> data;
        }

        int sum = carry + val1 + val2;
        int digit = sum % 10;

        insertTail(ansHead,ansTail,digit);

        carry = sum / 10;
        if(first != NULL){
            first = first -> next;
        }
        if(second != NULL){
            second = second -> next;
        }
    }
    return ansHead;
}
void addTwoList(Node* &head, Node* &head2){
    reverse(head);
    reverse(head2);

    Node* ans = add(head, head2);
    
    reverse(ans);
    print(ans);
}
int main(){
    Node* node1 = new Node(2);
    Node* head = node1;
    insert(head, 1);

    Node* node2 = new Node(3);
    Node* head2 = node2;
    insert(head2,2);
    insert(head2,1);

    print(head);
    print(head2);

    addTwoList(head, head2);
    return 0;
}