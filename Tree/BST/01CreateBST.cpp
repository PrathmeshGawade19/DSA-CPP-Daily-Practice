// creating a BST
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

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

void builtBST(int x, Node* &root){
    // base case
    if(root == NULL){
        root = new Node(x);
        return;
    }

    if(x < root->data){
        builtBST(x, root->left);
    }
    else{
        builtBST(x, root->right);
    }

    return ;
}

void userInput(Node* &root){
    int x;
    cin>>x;
    while(x!=-1){
        builtBST(x, root);
        cin>>x;
    }
}

int main(){
    Node* root = NULL; 
    cout<<"Enter the data for BST : ";
    userInput(root);

    cout<<"Printing the BST : ";
    levelOrderTraversal(root);

    return 0;
}