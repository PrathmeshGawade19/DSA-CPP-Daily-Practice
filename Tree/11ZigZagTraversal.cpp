#include<iostream>
#include<vector>
#include<queue>
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
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        // Code here
        vector<int> result;
        if(root==NULL){
            return result;
        }
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int ansSize = q.size();
            vector<int> ans(ansSize);
            for(int i=0; i<ansSize; i++){
                Node* temp = q.front();
                q.pop();
                if(leftToRight==true){
                    ans[i] = temp->data;
                }
                else{
                    ans[ansSize-i-1] = temp->data;
                }
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            leftToRight = !leftToRight;
            for(int i : ans){
                result.push_back(i);
            }
        }
        return result;
    }
};