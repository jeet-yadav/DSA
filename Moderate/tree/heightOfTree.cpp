#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildTree(Node* &root){
    cout<<"Enter the data : ";
    int data;
    cin>>data;

    if(data == -1){
        return;
    }

    root = new Node(data);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter the left child of "<<temp->data<<" : ";
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the right child of "<<temp->data<<" : ";
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }

}

void printTree(Node* root){
    if(root == NULL){return;}

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

// time complexity : O(n), space complexity : O(height)
int height(Node* node){
    if(node == NULL){return 0;}

    int left = height(root->left); 
    int right = height(root->right);

    int ans = max(left,right) + 1;
    return ans;
}

int main(){
    Node* root = NULL;
    buildTree(root);
    printTree(root);
    return 0;
}