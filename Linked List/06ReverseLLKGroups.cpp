//reverse nodes in k groups

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

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory free for a node with data : "<<value<<endl;
    }
};

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

Node* reverseInK(Node* &head, int k){
    // Check if there are enough nodes to form a group of k
    Node* temp = head;
    int cnt = 0;
    while (temp != NULL && cnt < k) {
        temp = temp->next;
        cnt++;
    }

    // If the count is less than k, return the head without reversing
    if (cnt < k) {
        return head;
    }

    //step 1 - revere first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;
    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //step2 - recursion dakhega aage ka
    if(next != NULL){
        head->next = reverseInK(next, k);
    }

    //step3 - return head of reversed list
    return prev;
}

int main(){
    Node* node1 = new Node(3);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 7);
    insertAtHead(head, tail, 8);
    insertAtHead(head, tail, 9);
    // insertAtHead(head, tail, 11);

    cout<<"linked list created is : ";
    Print(head); 
    cout<<endl;

    int k = 3;
    Node* newHead = reverseInK(head, k);

    cout<<"linked list after reversing k groups is : ";
    Print(newHead);  
    cout<<endl;  

    return 0;
}