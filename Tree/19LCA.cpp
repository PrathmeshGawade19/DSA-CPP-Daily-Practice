#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    private:
    Node* solve(Node* root, Node* n1, Node* n2){
        if(root == NULL){
            return NULL;
        }
        
        if(root->data == n1->data || root->data == n2->data){
            return root;
        }
        
        Node* left = solve(root->left, n1, n2);
        Node* right = solve(root->right, n1, n2);
        
        if(left!=NULL && right!=NULL){
            return root;
        }
        else if(left!=NULL && right==NULL){
            return left;
        }
        else if(left==NULL && right!=NULL){
            return right;
        }
        else{
            return NULL;
        }
    }
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        return solve(root, n1, n2);
    }
};