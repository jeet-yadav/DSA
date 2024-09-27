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
};

void insertTail(Node* &tail, int d){
    Node* temp = new Node(d);
    if(tail == NULL){
        tail = temp;
        // tail -> next = NULL;
    }
    else{
        tail -> next = temp;
        tail = temp;
    }
}
void print(Node* head){
    if(head == NULL) {
        cout << "Empty" << endl;
        return;
    }
    cout<<"Linked List : ";
    while(head != NULL){
        cout<<head -> data<<" ";
        head = head -> next;
    }
    cout<<endl;
}
Node* findMid(Node* head){
    if (head == NULL || head->next == NULL) return head;
    
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast->next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
Node* merge(Node* left, Node* right){
    if(left == NULL) return right;
    if(right == NULL) return left;
    
    Node* ans = new Node(-1);// Temporary dummy node to start the merged list
    Node* temp = ans;

    // Merge 2 sorted Linked List
    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    // Append remaining nodes from left or right list
    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    while(right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    // Move the result pointer to the first valid node
    ans = ans -> next;
    return ans;
}
Node* mergeSort(Node* head){
    // Base case, empty list or single node
    if(head == NULL || head -> next == NULL){
        return head;
    }
    // find the mid
    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;// Break the list into two halves

    //  Recursively sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the sorted halves
    // Node* result = merge(left, right);
    // return result;
    return merge(left, right);
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    for(int i=9; i>0; i--){
        insertTail(tail,i);
    }
    print(head); 

    Node* newHead = mergeSort(head);
    print(newHead);
    return 0;
}