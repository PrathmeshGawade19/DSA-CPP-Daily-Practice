//program to clone a linked list with random pointer
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void printLL(Node* &head){
    Node* curr = head;
    while(curr != NULL){
        cout<<curr->data<<endl;
        if(curr->random != NULL){
            cout<<"random pointer points to : "<<curr->random->data<<endl;
        }
        else{
            cout<<"random is NULL";
        }
        curr = curr->next;
    };
}

void printLL2(Node* &head){
    Node* curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    };
    cout<<endl;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp; //updating the tail
}

void cloneLL(Node* &head){
    //step 1 - clone original list next pointer
    Node* curr = head;

    Node* cloneTail = new Node(curr->data);
    Node* cloneHead = cloneTail;
    curr = curr->next;
    while(curr != NULL){
        insertAtTail(cloneTail, curr->data);
        curr = curr->next;
    }

    //step 2 - copy random pointer to clone list
    curr = head;
    Node* cloneCurr = cloneHead;
    while(cloneCurr != NULL){
        int randomData = curr->random->data;
        Node* cloneTemp = cloneHead;

        while(cloneTemp->data != randomData){
            cloneTemp = cloneTemp->next;
        }
        cloneCurr->random = cloneTemp;
        cloneCurr = cloneCurr->next;
        curr = curr->next;
    }

    printLL(cloneHead);
}

int main(){
    Node* head = new Node(1);

    Node* node2 = new Node(2);
    head->next = node2;

    Node* node3 = new Node(3);
    node2->next = node3;

    Node* node4 = new Node(4);
    node3->next = node4;

    Node* node5 = new Node(5);
    node4->next = node5;

    //random pointer
    head->random = node3;
    node2->random = head;
    node3->random = node5;
    node4->random = node3;
    node5->random = node2;

    printLL(head);

    cout<<"clone list along with random pointer below : "<<endl;
    cloneLL(head);

    return 0;
}