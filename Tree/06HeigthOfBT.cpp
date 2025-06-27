// to find height of binary tree
// longest path between node and a leaf node of tree is height a tree

#include<iostream>
#include<queue>
using namespace std;

// class to define node structure of tree
class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// function to build tree
Node *buildTree(Node *root){
    cout<<"enter data :"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"data for left "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"data for right "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

// level order traversal to print tree
void levelOrderTraversal(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *temp = q.front();
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

// function to find height of tree
int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;

    return ans;
}

int main(){
    // tree input 1 - 2 1 -1 -1 3 4 -1 -1 -1 ans = 3
    // tree input 2 - 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 ans = 3
    // tree input 3 - 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 9 8 -1 -1 -1 -1 ans = 5
    Node *root = NULL;    
    root = buildTree(root);
    levelOrderTraversal(root);

    cout<<"height of the tree is : "<<height(root)<<endl;

    return 0;
}