#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
    int solve(Node* root, int k, int &i){
        if(root == NULL){
            return -1;
        }
        
        int left = solve(root->left, k, i);
        if(left != -1){
            return left;
        }
        
        i++;
        if(i == k){
            return root->data;
        }
        
        return solve(root->right, k, i);
    }
  public:
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here.
        int i = 0;
        int ans = solve(root, k, i);
        return ans;
    }
};