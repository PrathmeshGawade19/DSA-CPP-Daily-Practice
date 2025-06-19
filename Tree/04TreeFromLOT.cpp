// to built tree from given level order traversal sequence
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

// build binary tree from level order traversal sequence 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
void buildFromLOT(Node *&root){
    queue<Node*> q;
    cout<<"enter data for root :"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        // for left node
        cout<<"enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new Node (leftData);
            q.push(temp->left);
        }

        // for right node
        cout<<"enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new Node (rightData);
            q.push(temp->right);
        }
    }

}

int main(){
    Node *root = NULL;

    buildFromLOT(root);
    levelOrderTraversal(root);

    return 0;

}