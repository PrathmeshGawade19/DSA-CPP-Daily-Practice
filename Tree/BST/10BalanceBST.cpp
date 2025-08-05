#include<iostream>
#include<vector>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
    public:
    void solve(Node* root, vector<int> &res){
        if(root == NULL){
            return;
        }
        
        solve(root->left, res);
        res.push_back(root->data);
        solve(root->right, res);
        
        return;
    }
    
    Node* inorderToBST(int s, int e, vector<int> res){
        if(s>e){
            return NULL;
        }
        
        int mid = (s+e)/2;
        Node* node = new Node(res[mid]);
        node->left = inorderToBST(s, mid-1, res);
        node->right = inorderToBST(mid+1, e, res);
        
        return node;
    }

  public:
    Node* balanceBST(Node* root) {
        // Code here
        vector<int> res;
        solve(root, res);
        return inorderToBST(0, res.size()-1, res);
        
    }
};