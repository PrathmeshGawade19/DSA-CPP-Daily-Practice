//add two numbers represented by linked lists or add 1 to a number represented by LL

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node* &head){
    Node* curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    };
    cout<<endl;
}

void reverseLL(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev; //update the head
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp; //updating the tail
}

void addTwoNum(Node* &head1, Node* &head2){
    //step 1 - reverse
    reverseLL(head1);
    reverseLL(head2);
    printLL(head1);
    printLL(head2);

    //step 2 - add from left
    Node* curr1 = head1;
    Node* curr2 = head2;
    int carry = 0, dig, sum, ans;

    Node* dummyTail = new Node(-1);
    Node* dummyHead = dummyTail;
    while(curr1 != NULL || curr2 != NULL){
        if(curr1 == NULL){
            sum = 0 + curr2->data + carry;
            curr2 = curr2->next;
        }
        else if(curr2 == NULL){
            sum = curr1->data + 0 + carry;
            curr1 = curr1->next;
        }
        else{
            sum = curr1->data + curr2->data + carry;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        dig = sum % 10;
        carry = sum / 10;
        insertAtTail(dummyTail, dig);    
    }

    if(carry != 0){
       insertAtTail(dummyTail, dig); 
    }

    reverseLL(dummyHead->next);
    printLL(dummyHead->next);
}

int main(){
    Node* head1 = new Node(4);

    Node* node12 = new Node(5);
    head1->next = node12;

    // Node* node13 = new Node(0);
    // node12->next = node13;

    Node* head2 = new Node(3);

    Node* node22 = new Node(4);
    head2->next = node22;

    Node* node23 = new Node(5);
    node22->next = node23;

    printLL(head1);
    printLL(head2);

    addTwoNum(head1, head2);
    
    return 0;
}

//Leetcode Problem - Add Two Numbers 
/* 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

/* 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
private:
    void insertAtTail(ListNode*& tail, int data) {
        ListNode* temp = new ListNode(data);
        tail->next = temp;
        tail = temp; // updating the tail
    }

public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* curr1 = head1;
        ListNode* curr2 = head2;
        int carry = 0, dig, sum, ans;

        ListNode* dummyTail = new ListNode(-1);
        ListNode* dummyHead = dummyTail;
        while (curr1 != NULL || curr2 != NULL) {
            if (curr1 == NULL) {
                sum = 0 + curr2->val + carry;
                curr2 = curr2->next;
            } else if (curr2 == NULL) {
                sum = curr1->val + 0 + carry;
                curr1 = curr1->next;
            } else {
                sum = curr1->val + curr2->val + carry;
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            dig = sum % 10;
            carry = sum / 10;
            insertAtTail(dummyTail, dig);
        }

        if (carry != 0) {
            insertAtTail(dummyTail, carry);
        }

        return dummyHead->next;
    }
};
*/