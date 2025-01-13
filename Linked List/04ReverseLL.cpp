//reverse the linked list

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

//iterative apporach
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

//recursive appraoch 1
void reverseLL2(Node* &head, Node* curr, Node* prev){
    //base case
    if(curr == NULL){
        head = prev;
        return;
    }
    Node* forward = curr->next;
    reverseLL2(head, forward, curr);
    curr->next = prev;
}

//recursive appraoch 2
Node* reverseLL3(Node* &head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* chotaHead = reverseLL3(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}

int main(){
    Node* node1 = new Node(3);
    Node* head = node1;

    Node* node2 = new Node(5);
    node1->next = node2;

    Node* node3 = new Node(7);
    node2->next = node3;

    cout<<"linked list created is : ";
    printLL(head);
    cout<<endl;

    reverseLL(head);
    cout<<"reverse of given linked list is : ";
    printLL(head);
    cout<<endl;

    reverseLL2(head, head, NULL);
    cout<<"reverse2 of given linked list is : ";
    printLL(head);
    cout<<endl;

    Node* value = reverseLL3(head);
    cout<<"value is : "<<value->data<<endl;
    cout<<"reverse3 of given linked list is : ";
    printLL(value);
    cout<<endl;
    

    return 0;
}