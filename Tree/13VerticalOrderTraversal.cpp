#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

 
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> m;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push(make_pair(root, make_pair(0,0)));
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        while(!q.empty()){
            pair<TreeNode*, pair<int,int>> temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            m[hd][lvl].push_back(frontNode->val);

            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(hd-1,lvl+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, make_pair(hd+1,lvl+1)));
            }
        }

        for(auto i : m){
            vector<int> col;
            for(auto j : i.second){
                vector<int> nodes_at_same_hd = j.second;
                // because - There may be multiple nodes in the same hd and same lvl.In such a case, sort these nodes by their values.
                sort(nodes_at_same_hd.begin(), nodes_at_same_hd.end()); 
                col.insert(col.end(), nodes_at_same_hd.begin(), nodes_at_same_hd.end());
            }
            ans.push_back(col);
        }

        return ans;

    }
};