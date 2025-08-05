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
    void solve(Node* root, vector<int> &in){
        if(root == NULL){
            return;
        }
        
        solve(root->left, in);
        in.push_back(root->data);
        solve(root->right, in);
        
        return;
    }
    
    void mergeArrays(vector<int> in1, vector<int> in2, vector<int> &in3){
        int i = 0, j = 0;
        while(i < in1.size() && j < in2.size()){
            if(in1[i] < in2[j]){
                in3.push_back(in1[i]);
                i++;
            }
            else{
                in3.push_back(in2[j]);
                j++;
            }
        }
        
        while(i < in1.size()){
            in3.push_back(in1[i]);
            i++;
        }
        while(j < in2.size()){
            in3.push_back(in2[j]);
            j++;
        }
    }

    // if question ask to built bst from merged inorder of two bst's
    // Node* inorderToBST(int s, int e, vector<int> in3){
    //     if(s > e){
    //         return NULL;
    //     }

    //     int mid = (s+e)/2;
    //     Node* root = new Node(in3[mid]);
    //     root->left = inorderToBST(s, mid-1, in3);
    //     root->right = inorderToBST(mid+1, e, in3);
    //     return root;
    // }
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        
        // step 1 - get inorder traverse of both bst ans store in vector/array
        vector<int> in1;
        vector<int> in2;
        solve(root1, in1);
        solve(root2, in2);
        
        // step 2 - merge 2 sorted vector/array
        vector<int> in3;
        mergeArrays(in1, in2, in3);
        
        return in3;
        
        // step 3 - inorder merged vector to BST
        // int s = 0 , e =  in3.size()-1;
        // return inorderToBST(s , e, in3);    
    
    }
};