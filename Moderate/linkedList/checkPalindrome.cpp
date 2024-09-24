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

// Calculating the length of the linked list, O(n)
int length(Node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head -> next;
    }
    return len;
}

void palindrome(Node* head){// My Solution, O(n) + O(n) + O(n) = O(n)
    if(head == NULL || head -> next == NULL){
        cout<<"Palindrome"<<endl;
        return;
    }
    
    int len = length(head);
    int* arr = new int[len];
    int i = 0;

    // Copying the linked list to an array, O(n)
    Node* temp = head;
    while(temp != NULL){
        arr[i++] = temp -> data;
        temp = temp -> next;
    }

    // Checking if the array is a palindrome, O(n)
    for(i=0; i<len/2; i++){
        if(arr[i] != arr[len-1-i]){
            cout<<"Not Palindrome"<<endl;
            return;
        }
    }
    cout<<"Palindrome"<<endl;
    delete arr;
}

void Reverse(Node* &head){
    if(head == NULL || head -> next == NULL){
        return;
    }
    Node* temp = head -> next;
    Reverse(temp);
    head -> next -> next = head;
    head -> next = NULL;
    head = temp;
}
void palindrome2(Node* head){
    if(head == NULL || head -> next == NULL){
        cout<<"Palindrome"<<endl;
        return;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    Node* middle = slow;// For understanding and made middle = slow, otherwise can directly go to next line slow as middle
    // Reversing the list after middle
    Node* temp = middle -> next;
    Reverse(temp);

    // Checking if the list is a palindrome
    while(temp != NULL){
        if(head -> data != temp -> data){
            cout<<"Not Palindrome"<<endl;
            return;
        }
        head = head -> next;
        temp = temp -> next;
    }
    cout<<"Palindrome"<<endl;
    Reverse(temp); 
}

//Babbar solution
Node* Reverse2(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void checkPalindrome(Node* head){// Another Solution, O(n) + O(n) = O(n
    if(head == NULL || head -> next == NULL){
        cout<<"Palindrome"<<endl;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Find the middle of the linked list
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    Node* middle = slow;// For understanding and made middle = slow, otherwise can directly go to next line slow as middle
    Node* secondHalfStart = middle -> next;// Start of the second half
    middle -> next = Reverse2(secondHalfStart);// Reverse the second half

    Node* head1 = head; // Start of the first half
    Node* head2 = middle->next; // Start of the reversed second half
    
    // Compare the two halves
    while(head2 != NULL){
        if(head1 -> data != head2 -> data){
            cout<<"Not Palindrome"<<endl;
            return;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    cout<<"Palindrome"<<endl;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);

    print(head);
    palindrome2(head);
    return 0;
}