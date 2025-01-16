// Circularly Linked or not
#include<iostream>
using namespace std;

class Node{
    public:
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    int data;
    Node* next;
};

void PrintLL(Node* &head){
    cout<<head->data<<" ";
    Node* curr = head->next;

    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
        if(curr == head){
            cout<<endl;
            return;
        }
    }
    cout<<endl;
}

bool isCircularList(Node* &head){
    if(head == NULL){
        return true;
    }

    Node* curr = head->next;
    while(curr != NULL){
        curr = curr->next;
        if(curr == head){
            return true;
        }
    }

    return false;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;

    Node* node2 = new Node(20);
    node1->next = node2;

    Node* node3 = new Node(30);
    node2->next = node3;

    Node* node4 = new Node(40);
    node3->next = node4;

    Node* node5 = new Node(50);
    node4->next = node5;

    node5->next = node1; // links/points last node next to first node in linked list

    PrintLL(head);

    bool ans = isCircularList(head);
    cout<<"the list is circular ? "<<ans;

    return 0;
}