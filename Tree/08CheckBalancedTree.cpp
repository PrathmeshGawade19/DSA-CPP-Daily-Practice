// to check tree is balanced or not
// tree is balanced if difference between height of left and right subtree is not more than one for all nodes
// abs[height(left) - height(right)] <= 1

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

bool isBalanced(Node *root){
    if(root == NULL){
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    // tree input 1 - 1 10 5 -1 -1 -1 39 -1 -1 ans = true
    // tree input 2 - 1 2 3 -1 -1 -1 -1 ans = false
    Node *root = NULL;    
    root = buildTree(root);
    levelOrderTraversal(root);

    cout<<isBalanced(root)<<endl;


    return 0;
}