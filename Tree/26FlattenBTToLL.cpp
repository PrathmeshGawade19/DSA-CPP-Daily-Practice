#include<iostream>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int data){
        left = NULL;
        right = NULL;
        this->data = data;
    }
};

class Solution {
  public:
    void flatten(Node *root) {
        // code here
        Node *curr = root;
        while(curr != NULL){
            if(curr->left){
                Node *pred = curr->left;
                while(pred->right){
                    pred = pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};