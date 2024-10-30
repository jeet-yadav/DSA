#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

// breadth first search
void levelOrderTraversal(node* root){
    // Step 1 : Create an empty queue ans push root and NULL in it
    queue<node*> q;
    q.push(root);   // Add the root node to the queue
    q.push(NULL);   // NULL acts as a marker for the end of the current level

    // Step 2: Process nodes in the queue until it becomes empty
    while(!q.empty()){
        node* temp = q.front(); // Get the front node of the queue
        q.pop();                // Remove the front node from the queue

        // Step 3: Check if the current node is NULL
        if(temp == NULL){
            cout<<endl; // Print a newline to indicate the end of the current level

            // Step 4: If there are more nodes to process, add another NULL marker
            if(!q.empty()){
                q.push(NULL);// Add NULL to signify the end of the next level
            }
        }
        else{
            // Step 5: Print the data of the current node
            cout<<temp->data<<" ";

            // Step 6: Add the left child to the queue if it exists
            if(temp->left){
                q.push(temp->left);
            }

            // Step 7: Add the right child to the queue if it exists
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

//NLR
void preOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//LNR
void inOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

//LRN
void postOrderTraversal(node* root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void preOrderTraversalLoop(node* root){
    if(root == NULL){
        return;
    }

    stack<node*> s;
    s.push(root);

    while(!s.empty()){
        node* temp = s.top();
        s.pop();

        cout<<temp->data<<" ";

        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter root node : ";
    int rootData;
    cin>>rootData;
    root = new node(rootData);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Left of "<<temp->data<<" : ";
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp -> left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Right of "<<temp->data<<" : ";
        int rightdata;
        cin>>rightdata;
        
        if(rightdata != -1){
            temp -> right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main(){
    node* root = NULL;
    // root = buildTree(root);

    // // this is input 
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    // cout<<"Preorder : ";
    // preOrderTraversal(root);
    // cout<<endl;

    // cout<<"Inorder : ";
    // // inOrderTraversal(root);
    // preOrderTraversalLoop(root);
    // cout<<endl;

    // cout<<"preorder : ";
    // postOrderTraversal(root);

    buildFromLevelOrder(root);
    return 0;
}