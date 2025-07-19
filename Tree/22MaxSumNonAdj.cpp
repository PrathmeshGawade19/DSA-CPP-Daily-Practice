#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
    public:
    pair<int, int> solve(Node* root, pair<int, int> ans){
        if(root == NULL){
            return make_pair(0,0);
        }
        
        pair<int,int> left = solve(root->left, ans);
        pair<int,int> right = solve(root->right, ans);
        
        ans.first = root->data + left.second + right.second;
        ans.second = max(left.first, left.second) + max(right.first, right.second);
        
        return ans;
    }
  public:
    int getMaxSum(Node *root) {
        pair<int, int> ans;
        
        pair<int, int> result = solve(root, ans);
        return max(result.first, result.second);
    }
};