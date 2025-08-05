// to insert a node in a BST.
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
    Node* insertNode(Node* node, int key){
        // base case
        if(node == NULL){
            return new Node(key);
        }
        if(node->data == key){
            return node;
        }
        
        if(node->data < key){
            node->right = insertNode(node->right, key);
        }
        else{
            node->left = insertNode(node->left, key);
        }
        
        return node;
    }
  public:
    Node* insert(Node* node, int key) {

        // Your code goes here
        return insertNode(node, key);
        
    }
};