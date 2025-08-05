// to search a node in BST.
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void solve(Node* root, int x, bool &ans){
    //base case
    if(root == NULL){
        ans = 0;
        return;
    }
    if(root->data == x){
        ans = 1;
        return;
    }
    
    if(root->data > x){
        solve(root->left, x, ans);
    }
    else{
        solve(root->right, x , ans);
    }
}

bool search(Node* root, int x) {
    // Your code here
    bool ans;
    solve(root, x, ans);
    return ans;
}