#include<iostream>
#include<vector>
using namespace std;

// Tree Node
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
    private:
    void leftTraversal(Node *root, vector<int> &ans){
        if(root == NULL || root->left == NULL && root->right == NULL){
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            leftTraversal(root->left, ans);
        }
        else{
            leftTraversal(root->right, ans);
        }
    }
    
    void leafTraversal(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        
        if(root->left){
            leafTraversal(root->left, ans);
        }
        if(root->right){
            leafTraversal(root->right, ans);
        }
    }
    
    void rightTraversal(Node* root, vector<int> &ans){
        if(root == NULL || root->left == NULL && root->right == NULL){
            return;
        }
        
        if(root->right){
            rightTraversal(root->right, ans);
        }
        else{
            rightTraversal(root->left, ans);
        }
        
        ans.push_back(root->data);
        
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        // initial root NULL hai kya check karo if not then push
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        ans.push_back(root->data);

        // left boundary node ke data
        leftTraversal(root->left, ans);

        // leaf node ke data
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
        
        //right boundary node ke data
        rightTraversal(root->right, ans);
        
        return ans;
        
    }
};