#include<iostream>
#include<vector>
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
    void solve(Node *root, int k, vector<int> &ans, int &count){
        //base case - leaf node
        if(root == NULL){
            return;
        }
        
        ans.push_back(root->data);
        int sum = 0;
        for(int i=ans.size()-1; i>=0; i--){
            sum = sum + ans[i];
            if(sum == k){
                count++;
            }
        }
        
        solve(root->left, k, ans, count);
        solve(root->right, k, ans, count);
        
        ans.pop_back();
    }
  public:
    int sumK(Node *root, int k) {
        // code here
        vector<int> ans;
        int count = 0;
        
        solve(root, k, ans, count);
        
        return count;
    }
};