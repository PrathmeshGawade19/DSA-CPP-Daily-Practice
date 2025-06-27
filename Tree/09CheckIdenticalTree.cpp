// check if two trees are identical or not

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

bool isIdentical(Node* r1, Node* r2){
    if(r1==NULL && r2==NULL){
        return true;
    }
    if(r1!=NULL && r2==NULL){
        return false;
    }
    if(r1==NULL && r2!=NULL){
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool value = r1->data == r2->data;

    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    // tree input 1 - 1 2 -1 -1 3 -1 -1 for both, ans = true 
    // tree input 2 - Tree 1: 1 2 -1 -1 3 -1 -1 Tree 2: 1 3 -1 -1 2 -1 -1 ans = false
    Node *root1 = NULL;    
    root1 = buildTree(root1);
    levelOrderTraversal(root1);

    Node *root2 = NULL;    
    root2 = buildTree(root2);
    levelOrderTraversal(root2);

    cout<<"the given tree is identical : "<<isIdentical(root1, root2)<<endl;

    return 0;
}