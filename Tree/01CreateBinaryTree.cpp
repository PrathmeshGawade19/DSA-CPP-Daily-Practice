//creating/building binary tree

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


int main(){
    Node *root = NULL;    

    root = buildTree(root); // need to do because we have passed root pointer as argument in pass by value and not pass by reference so to point to the built tree which is new copy in function we need to assign it the root in main function so it also points to the built tree and not NULL.
    // to pass by reference the parameter of buildTree function should be void buildTree(Node *&root).


    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1