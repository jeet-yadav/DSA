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

int height(Node* node){
    if(node == NULL){return 0;}

    int left = height(node->left); 
    int right = height(node->right);

    int ans = max(left,right) + 1;
    return ans;
}

// time complexity : O(n-square ), space complexity : O(height)
// int diameter(Node* node){
//     if(node == NULL){return 0;}

//     int op1 = diameter(node->left);
//     int op2 = diameter(node->right);
//     int op3 = height(node->left) + height(node->right) + 1;
    
//     return max(op1,max(op2,op3));
// }

pair<int,int> diameterFast(Node* root){
    if(root == NULL){
        pair<int, int> p = make_pair(0,0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.ssecond = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node* root){
    return diameterFast(root).fast;
}

int main(){
    Node* root = NULL;
    buildTree(root);
    printTree(root); 
    cout<<"Diameter : "<<diameter(root);
    return 0;
}