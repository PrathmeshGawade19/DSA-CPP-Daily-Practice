#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

class Solution {
    public:
    Node* solve(Node* root, int &k, int node){
        //base case leaf node or node found
        if(root == NULL){
            return NULL;
        }
        if(root->data == node){
            return root;
        }
        
        Node* left = solve(root->left, k, node);
        Node* right = solve(root->right, k, node);
        
        if(left==NULL && right!=NULL){
            k--;
            if(k<=0){
                k = __INT32_MAX__;
                return root;
            }
            return right;
        }
        else if(left!=NULL && right==NULL){
            k--;
            if(k<=0){
                k = __INT32_MAX__;
                return root;
            }
            return left;
        }
        else{ //left==NULL && right==NULL
            return NULL;
        }
    }
    public:
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        
        Node* ans = solve(root, k, node);

        if(ans==NULL || ans->data == node){
            return -1;
        }
        return ans->data;
        
    }
};
