//middle of linked list
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
    Node* itr = head;
    while(itr != NULL){
        cout<<itr->data<<" ";
        itr = itr->next;
    }
}

int lengthLL(Node* &head){
    Node* itr = head;
    int count = 0;
    while(itr != NULL){
        itr = itr->next;
        count++;
    }

    return count;
}

//approach 2
int middleLL(Node* &head){
    int len = lengthLL(head);
    int mid = (len/2) + 1;
    Node* itr = head;
    int count = 1;
    while(count < mid){
        itr = itr->next;
        count++;
    }
    return itr->data;
}

//approach 2
int middleLL2(Node* &head){
    Node* fast = head;
    Node* slow = head;
    int len = lengthLL(head);
    if(len%2 == 0){
        //even
        while(fast != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data;
    }
    else{
        //odd
        while(fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data; 
    }

}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    Node* node2 = new Node(2);
    node1->next = node2;

    Node* node3 = new Node(3);
    node2->next = node3;

    Node* node4 = new Node(4);
    node3->next = node4;

    Node* node5 = new Node(5);
    node4->next = node5;

    Node* node6 = new Node(6);
    node5->next = node6;

    cout<<"linked list created is : ";
    printLL(head);
    cout<<endl;

    int len = lengthLL(head);
    cout<<"length of given linked list is : "<<len<<endl;

    int midValue = middleLL(head);
    cout<<"mid data value is : "<<midValue<<endl;

    int midValue2 = middleLL2(head);;
    cout<<"mid data value thorught approach 2 is : "<<midValue2<<endl;


    return 0;
}