// level order traversal 
// it is a type of bfs
#include<iostream>
#include<queue>
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

// level order traversal
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

int main(){
    Node *root = NULL;

    root = buildTree(root);

    cout<<"printing the level order traversal of built tree : "<<endl;
    levelOrderTraversal(root);

    return 0;
}
