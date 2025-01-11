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
void insertAtHead(Node* &head, Node* &tail, int data){
    //if empty list
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp->next = head;
        head = temp; //updating the head
    }
}

//insert at tail
void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp; //updating the tail
}

//insert at position
void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    //if trying to insert at head
    if(position == 1){
        insertAtHead(head, tail, data);
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
void deleteNode(Node* &head, Node* &tail, int position){
    //deleting first node
    if(position == 1){
        Node* temp = head;
        head = head->next; //updating the head

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
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main(){
    // Node* node1 = new Node(100);

    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    // Node* head = node1;
    // Node* tail = node1;

    //case when LL is empty and we insert a node 
    Node* head = NULL;
    Node* tail = NULL;    

    insertAtHead(head, tail, 200);
    insertAtHead(head, tail, 300);
    insertAtHead(head, tail, 400);
    Print(head);
    cout<<endl;

    insertAtTail(tail, 500);
    insertAtTail(tail, 600);
    insertAtTail(tail, 700);
    Print(head);
    cout<<endl;

    insertAtPosition(head, tail, 800, 7);
    Print(head);
    cout<<endl;

    deleteNode(head, tail, 1); //head position delete
    deleteNode(head, tail, 3); //middle position delete
    deleteNode(head, tail, 5); //tail position delete
    Print(head);
    cout<<endl;
    
    cout<<head->data<<endl;
    cout<<tail->next<<endl;

    return 0;
}