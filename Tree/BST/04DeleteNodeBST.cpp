// to delete a node in BST.
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    public:
    Node* solve(Node* root, int X){
        // base case
        if(root == NULL){
            return NULL;
        }
        
        if(root->data > X){
            root->left = solve(root->left, X);
        }
        else if(root->data < X){
            root->right = solve(root->right, X);
        }
        else{
            // deletion logic
            // case 1 - 0 child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            // case 2 - 1 child
            // left child
            if(root->left != NULL && root->right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // right child
            if(root->left == NULL && root->right != NULL){
                Node* temp = root->right;
                delete root;
                return temp; 
            }
            // case 3 - 2 child
            if(root->left != NULL && root->right != NULL){
                Node* temp = root->right;
                while(temp->left){
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = solve(root->right, temp->data);
                return root;
            }
        }
        
        return root;
    }
  public:
    // Function to delete a node from BST.
    Node *deleteNode(Node *root, int X) {
        // your code goes here
        Node* rootAns = solve(root, X);
        return rootAns;
    }
};