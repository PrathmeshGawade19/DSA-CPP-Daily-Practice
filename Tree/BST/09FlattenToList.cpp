#include<iostream>
#include<vector>
using namespace std;

// User function Template for C++

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    public:
    void solve(Node* root, vector<Node*> &res){
        if(root == NULL){
            return;
        }
        
        solve(root->left, res);
        res.push_back(root);
        solve(root->right, res);
        
        return;
    }
  public:
    Node *flattenBST(Node *root) {
        // code here
        vector<Node*> res;
        solve(root, res);
        
        int size = res.size();
        for(int i=0; i<size; i++){
            if(i == size-1){
                res[i]->left = NULL;
                res[i]->right = NULL;
            }
            else{
                res[i]->left = NULL;
                res[i]->right = res[i+1];
            }
        }
        
        return res[0];
    }
};