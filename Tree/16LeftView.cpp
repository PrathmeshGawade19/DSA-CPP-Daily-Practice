#include<iostream>
#include<vector>
#include<queue>
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

// recursive approach
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
        solve(root->left, ans, level+1);
        solve(root->right, ans, level+1);
    }
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        solve(root, ans, 0);
        return ans;
    }
};

// level order traversal appraoch
class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<pair<Node*,int>> q; // node and level
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int lvl = temp.second;
            
            if(ans.size() == lvl){
                ans.push_back(frontNode->data);
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, lvl+1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, lvl+1));
            }
        }
        
        return ans;
    }
};