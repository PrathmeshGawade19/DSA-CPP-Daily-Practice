//doubly linked list
#include<iostream>
using namespace std;

class Node{
    public:
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    int data;
    Node* next;
    Node* prev;

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory free for a node with data : "<<value<<endl;
    }
};

void PrintLL(Node* &head){
    Node* itr = head;
    while(itr != NULL){
        cout<<itr->data<<" ";
        itr = itr->next;
    }
}

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    //if trying to insert at head
    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    Node* itr = head;
    int count = 1;
    while(count < position-1){
        itr = itr->next;
        count++;
    }

    //if trying to insert at tail
    if(itr->next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = itr->next;
    itr->next->prev = nodeToInsert;
    itr->next = nodeToInsert;
    nodeToInsert->prev = itr;
}

void deleteNode(Node* &head, Node* &tail, int position){
    //deleting first node
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    //deleting last or middle node
    else{
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }

        if(curr->next == NULL){ //updating the tail
            tail = prev;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main(){
    Node* node1 = new Node(100);
    Node* head = node1;
    Node* tail = node1;
    PrintLL(head);
    cout<<endl;

    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtHead(head, 400);
    PrintLL(head);
    cout<<endl;

    insertAtTail(tail, 500);
    insertAtTail(tail, 600);
    insertAtTail(tail, 700);
    PrintLL(head);
    cout<<endl;

    insertAtPosition(head, tail, 3, 800);
    PrintLL(head);
    cout<<endl;

    deleteNode(head, tail, 1);
    deleteNode(head, tail, 2);
    deleteNode(head, tail, 6);
    PrintLL(head);
    cout<<endl;

    return 0;
}