#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        map<int,int> m; // hD to node data
        queue<pair<Node*,int>> q; // node and hD
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hD = temp.second;
            // main logic to put value from queue to map if already mapping is not existed for the hD
            if(m.find(hD) == m.end()){
                m[hD] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hD-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hD+1));
            }
        }
        
        for(auto i : m){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};