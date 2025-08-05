#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
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
    void solve(Node* root, int target, vector<int> &ans){
        if(root == NULL){
            return;
        }
    
        solve(root->left, target, ans);
        ans.push_back(root->data);
        solve(root->right, target, ans);
        
        return;
    }
  public:
    bool findTarget(Node *root, int target) {
        // your code here.
        vector<int> ans;
        solve(root, target, ans);
        
        int i=0, j=ans.size()-1;
        while(i<j){
            int sum = ans[i] + ans[j];
            if(sum > target){
                j--;
            }
            else if(sum < target){
                i++;
            }
            else{
                return true;
            }
        }
        
        return false;
    }
};