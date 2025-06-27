// to check if tree is sum tree
// tree is sum tree if for every node in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. 
// an empty tree is also a sum tree as sum of an empty tree can be considered to be 0
// a lead node is also considered a sum tree

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

pair<bool,int> isSumTree(Node* root){
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p; 
    }

    pair<bool,int> leftAns = isSumTree(root->left);
    pair<bool,int> rightAns = isSumTree(root->right);
    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;
    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool condn = root->data == leftSum + rightSum;

    pair<bool,int> ans;
    if(isLeftSumTree && isRightSumTree && condn){
        ans.first = true;
        ans.second = root->data + leftSum + rightSum;
    }
    else{
        ans.first = false;
    }
    
    return ans;
}

int main(){
    // tree input 1 - 26 10 4 -1 -1 6 -1 -1 3 -1 3 -1 -1 ans = true
    // tree input 2 - 10 5 -1 -1 2 -1 -1 ans = false
    Node *root = NULL;    
    root = buildTree(root);
    levelOrderTraversal(root);

    cout<<"tree is sum tree : "<<isSumTree(root).first<<endl;

    return 0;
}