#include<iostream>
#include<vector>
using namespace std;

class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        Node* curr = root;
        Node* pred = NULL;
        Node* suc = NULL;
        
        while(curr){
            if(curr->data > key){
                suc = curr; // if is not present
                curr = curr->left;
            }
            else if(curr->data < key){
                pred = curr; // if is not present
                curr = curr->right;
            }
            else{
                if(curr->left){
                    Node* temp = curr->left;
                    while(temp->right){
                        temp = temp->right;
                    }
                    pred = temp;
                }
                if(curr->right){
                    Node* temp = curr->right;
                    while(temp->left){
                        temp = temp->left;
                    }
                    suc = temp;
                }
                
                break;
            }
        }
        
        ans.push_back(pred);
        ans.push_back(suc);
        
        return ans;
        
    }
};