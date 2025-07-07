#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Should return  right view of tree
class Solution {
    private:
    void solve(Node* root,vector<int> &ans, int level){
        //base case
        if(root == NULL){
            return;
        }
        if(ans.size() == level){
            ans.push_back(root->data);
        }
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }
  public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        // Your Code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        solve(root, ans, 0);
        return ans;
    }
};