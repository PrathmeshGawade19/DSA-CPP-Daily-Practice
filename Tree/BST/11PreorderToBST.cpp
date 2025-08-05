#include<iostream>
#include<vector>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

class Solution {
    public:
    Node* solve(int pre[], int size, int mini, int maxi, int &i){
        if(i >= size){
            return NULL;
        }
        
        if(pre[i] < mini || pre[i] > maxi){
            return NULL;
        }
        
        Node* root = newNode(pre[i++]);
        root->left = solve(pre, size, mini, root->data, i);
        root->right = solve(pre, size, root->data, maxi, i);
        
        return root;
        
    }
  public:
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        // code here
        int mini = INT64_MIN, maxi = INT64_MAX, i = 0;
        return solve(pre, size, mini, maxi, i);
    }
};