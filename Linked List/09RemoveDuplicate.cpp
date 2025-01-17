#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    int data;
    Node* next;

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            this->next = NULL;
            delete next;  
        }
        cout<<"node deleted with value : "<<value<<endl;
    }
};

void PrintLL(Node* &head){
    Node* curr = head;

    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

// O(n)
void removeDuplicateSorted(Node* &head){ 
    Node* curr = head;
    while(curr != NULL && curr->next != NULL){
        if(curr->data == curr->next->data){
            Node* nodeToDelete = curr->next;
            curr->next = curr->next->next;
            delete nodeToDelete; 
        }
        else{
            curr = curr->next;
        }
    }
}

//leetcode 82 - leaving only distinct numbers from the original list
void removeDuplicateSorted2(Node* &head){ 
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            // Skip and delete all nodes with the same value.
            int duplicateValue = curr->data;
            while (curr != NULL && curr->data == duplicateValue) {
                Node* nodeToDelete = curr;
                curr = curr->next;
                delete nodeToDelete;
            }
            // Update prev->next or head after deletion.
            if (prev == NULL) {
                head = curr; // Update head if starting nodes were deleted.
            } else {
                prev->next = curr;
            }
        } else {
            // Move prev forward only when no deletion occurs.
            prev = curr;
            curr = curr->next;
        }
    }
}

//approach 1 - O(n^2)
void removeDuplicateUnsorted(Node* &head){
    Node* curr = head;
    while(curr != NULL){
        Node* forward = curr->next;
        Node* prev = curr;
        while(forward != NULL){
            if(curr->data == forward->data){
                Node* nodeToDelete = forward;
                prev->next = forward->next;
                forward = forward->next;
                delete nodeToDelete;
            }
            else{
                forward = forward->next;
                prev = prev->next;
            }
        }
        curr = curr->next;
    }
}

//approach 2 - map O(n)
void removeDuplicateUnsorted2(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    map<int ,bool> visited; 
    while(curr != NULL){
        if(visited[curr->data] == true){
            Node* nodeToDelete = curr;
            curr = curr->next;
            prev->next = curr;
            delete nodeToDelete;
        }
        else{
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }      
    }
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    Node* node2 = new Node(1);
    node1->next = node2;

    Node* node3 = new Node(1);
    node2->next = node3;

    Node* node4 = new Node(2);
    node3->next = node4;

    Node* node5 = new Node(3);
    node4->next = node5;

    // Node* node6 = new Node(4);
    // node5->next = node6;

    PrintLL(head);

    // removeDuplicateSorted(head);
    removeDuplicateSorted2(head);
    // removeDuplicateUnsorted(head);
    // removeDuplicateUnsorted2(head);
    
    PrintLL(head);
    cout<<head->data<<endl;

    return 0;
}