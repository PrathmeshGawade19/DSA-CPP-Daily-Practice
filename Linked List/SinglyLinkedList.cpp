//singly linked list

#include<iostream>
using namespace std;

//implementation of LL node 
class Node{
    public:
    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    int data;
    Node* next;

    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory free for a node with data : "<<value<<endl;
    }
};

//traverse in LL
void Print(Node* &head){
    Node* itr = head;
    while(itr != NULL){
        cout<<itr->data<<" ";
        itr = itr->next;
    }
    
}

//insert at head
void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);

    temp->next = head;
    head = temp;
}

//insert at tail
void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

//insert at position
void insertAtPosition(Node* &head, Node* &tail, int data, int position){
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

    Node* temp = new Node(data);
    temp->next = itr->next;
    itr->next = temp; 
}

//delete node
void deleteNode(Node* &head, int position){
    //deleting first node
    if(position == 1){
        Node* temp = head;
        head = head->next;

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
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main(){
    Node* node1 = new Node(100);

    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    Node* head = node1;

    insertAtHead(head, 200);
    insertAtHead(head, 300);
    insertAtHead(head, 400);
    Print(head);
    cout<<endl;

    Node* tail = node1;
    insertAtTail(tail, 500);
    insertAtTail(tail, 600);
    insertAtTail(tail, 700);
    Print(head);
    cout<<endl;

    insertAtPosition(head, tail, 800, 8);
    Print(head);
    cout<<endl;

    deleteNode(head, 5);
    Print(head);
    cout<<endl;
    
    cout<<head->data<<endl;
    cout<<tail->next<<endl;

    return 0;
}