#include<iostream>
#include<queue>
#include<map>
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
    // to burn tree from target Node and count time
    void burnTreeMinTime(Node* targetNode, map<Node*, Node*> nodeToParent,int &ans){
        queue<Node*> q;
        q.push(targetNode);
        map<Node*, bool> visited;
        visited[targetNode] = 1;
        ans = 0;
        
        while(!q.empty()){
            int size = q.size();
            bool timeFlag = false;
            
            for(int i=0; i<size; i++){
                Node* queueFront = q.front();
                q.pop();
                
                if(queueFront->left && !visited[queueFront->left]){
                    q.push(queueFront->left);
                    visited[queueFront->left] = 1;
                    timeFlag = true;
                }
                if(queueFront->right && !visited[queueFront->right]){
                    q.push(queueFront->right);
                    visited[queueFront->right] = 1;
                    timeFlag = true;
                }
                if(nodeToParent[queueFront] && !visited[nodeToParent[queueFront]]){
                    q.push(nodeToParent[queueFront]);
                    visited[nodeToParent[queueFront]] = 1;
                    timeFlag = true;
                }
            }
            
            if(timeFlag == true){
                ans++;
            }
        }
    }
    
    // to create mappping of node to parent and finding target Node* 
    Node* nodeToParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
        queue<Node*> q;
        Node* targetNode = NULL;
        q.push(root);
        nodeToParent[root] = NULL;
        
        while(!q.empty()){
            Node* queueFront = q.front();
            if(queueFront->data == target){
                targetNode = queueFront;
            }
            q.pop();
            if(queueFront->left){
                nodeToParent[queueFront->left] = queueFront;
                q.push(queueFront->left);
            }
            if(queueFront->right){
                nodeToParent[queueFront->right] = queueFront;
                q.push(queueFront->right);
            }
        }
        return targetNode;
    }
    
  public:
    int minTime(Node* root, int target) {
        // code here
        map<Node*, Node*> nodeToParent;
        Node* targetNode = nodeToParentMapping(root, target, nodeToParent);
        int ans;
        burnTreeMinTime(targetNode, nodeToParent, ans);
        return ans;
        
    }
};