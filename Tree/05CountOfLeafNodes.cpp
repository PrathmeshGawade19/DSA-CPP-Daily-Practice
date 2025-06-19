// to count lead nodes of tree
#include<iostream>
using namespace std;

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

// count of leaf Nodes
void inorder(Node* root, int &count){
    if(root == NULL){
        return;
    }

    inorder(root->left, count);
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    inorder(root->right, count);
}

int main(){
    Node *root = NULL;
    root = buildTree(root);

    int count=0;
    inorder(root, count);
    cout<<"count of leaf nodes is : "<<count<<endl;

    return 0;
}