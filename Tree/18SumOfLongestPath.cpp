#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; 

class Solution {
    private:
    void solve(Node* root,int sum, int &maxSum, int len, int &maxLen){
        if(root == NULL){
            if(len>maxLen){
                maxSum = sum;
                maxLen = len;
            }
            if(len==maxLen){
                maxSum = max(sum, maxSum);
            }
            return;
        }
        
        sum = sum + root->data;
        solve(root->left, sum, maxSum, len+1, maxLen);
        solve(root->right, sum, maxSum, len+1, maxLen);
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        int sum = 0, maxSum = 0, len = 0, maxLen = 0;
        if(root == NULL){
            return maxSum;
        }
        
        solve(root, sum, maxSum, len, maxLen);
        return maxSum;
    }
};