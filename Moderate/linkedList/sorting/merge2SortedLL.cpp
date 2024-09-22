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
void merge(Node* head1, Node* &head2){// My Solution, doesnt work for all lists T_T
    // if head1 is empty
    if(head1 == NULL){
        cout<<"List 1 is empty"<<endl;
        return;
    }
    // if head2 is empty
    if(head2 == NULL){
        cout<<"List 2 is empty"<<endl;
        return;
    }

    Node* temp1 = head1;
    Node* temp2 = head2;

    // Traverse both lists and merge nodes in the correct position
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->next != NULL && (temp1 -> data <= temp2 -> data) && (temp2 -> data <= temp1 -> next -> data)){
            Node* temp1Next = temp1 -> next;
            temp1 -> next = temp2;
            temp2 = temp2 -> next;
            temp1->next->next = temp1Next;
        }
        temp1 = temp1 -> next;
    }
    // If temp1 reaches the end and temp2 still has nodes, append temp2 to the end
    if(temp1 == NULL && temp2 != NULL){
        temp1 = head1;
        while(temp1->next != NULL){ // Find the end of the list
            temp1 = temp1->next;
        }
        temp1->next = temp2;
    }
}

// Merge two sorted linked lists
Node* solve(Node* first, Node* second){

    // If only one element is in the first list
    if(first -> next == NULL){
        first -> next = second;
        return first;
    }
    
    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;

    // Traverse both lists
    while(next1 != NULL && curr2 != NULL){
        // If curr2 fits between curr1 and next1
        if((curr1 -> data <= curr2 -> data) && (curr2 -> data <= next1 -> data)){
            // Insert curr2 between curr1 and next1
            curr1 -> next = curr2;  // Link curr1 to curr2
            next2 = curr2 -> next;  // Store the next node of curr2 (to move forward later)
            curr2 -> next = next1;  // Link curr2 to next1

            // Move curr1 and curr2 forward
            curr1 = curr2;  // curr1 is now at curr2's position
            curr2 = next2;  // curr2 moves to the next node in second list
        }   
        else{
            // Move curr1 and next1 one step forward in the first list
            curr1 = next1;
            next1 = next1 -> next;

            // If we reach the end of the first list (next1 becomes NULL)
            // Append the rest of the second list (curr2 and beyond) to the first list
            if(next1 == NULL){
                curr1 -> next = curr2;
            }
        }
    }
    return first;// Return the head of the merged list
}
Node* merge2(Node* first, Node* second){
    // if head1 is empty
    if(first == NULL){
        cout<<"List 1 is empty"<<endl;
        return second;
    }
    // if head2 is empty
    if(second == NULL){
        cout<<"List 2 is empty"<<endl;
        return first;
    }
    // Depending on the data at the head, start merging from the appropriate list
    // If the head of the first list is smaller or equal, call solve with first as the main list
    if(first -> data <= second -> data){
        return solve(first, second);
    }
    else{
        // Otherwise, call solve with second as the main list
        return solve(second, first);
    }
}

int main(){
    Node* node1 = new Node(7);
    Node* head1 = node1;

    insertHead(head1,6);
    insertHead(head1,3);
    insertHead(head1,1);

    Node* node2 = new Node(8);
    Node* head2 = node2;

    insertHead(head2,5);
    insertHead(head2,4);
    insertHead(head2,2);

    print(head1);
    print(head2); 
    merge2(head1, head2);
    print(head1);
    return 0;
}