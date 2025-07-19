#include<iostream>
#include<vector>
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

class Solution {
  public:
  int findPostion(vector<int> inorder, int n, int ele){
        for(int i=0; i<n; i++){
            if(inorder[i]==ele){
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(vector<int> inorder,vector<int> postorder, int n, int &index, int inStart, int inEnd){
        // base case
        if(index<0 || inStart > inEnd){
            return NULL;
        }
        int ele = postorder[index--];
        Node *root = new Node(ele);
        int pos = findPostion(inorder, n, ele);
        
        root->right = solve(inorder, postorder, n, index, pos+1, inEnd);
        root->left = solve(inorder, postorder, n, index, inStart, pos-1);
        
        return root;
    }
    
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        // code here
        int n = inorder.size(); // size of nodes in tree
        int index = n-1;
        Node* ans = solve(inorder, postorder, n, index, 0, n-1);
        return ans;
    }
};