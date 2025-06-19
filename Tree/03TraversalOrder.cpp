//inorder, preorder and postoder traversal

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

//inorder (LNR)
void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//preorder (NLR)
void preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//postorder (LRN)
void postorder(Node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


int main(){
    Node *root = NULL;    

    root = buildTree(root);

    cout<<"inorder traversal of tree is : ";
    inorder(root);
    cout<<endl;

    cout<<"preorder traversal of tree is : ";
    preorder(root);
    cout<<endl;

    cout<<"postorder traversal of tree is : ";
    postorder(root);
    cout<<endl;

    return 0;
}