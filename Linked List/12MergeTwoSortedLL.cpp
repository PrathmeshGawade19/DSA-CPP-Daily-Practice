//merge two sorted linked list
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

void mergeLL(Node* &head1, Node* &head2){
    Node* curr1 = head1;
    Node* p1 = head1;
    Node* curr2 = head2;
    
    curr1 = curr1->next;

    while(curr1 != NULL && curr2 != NULL){
        if(curr1->data <= curr2->data){
            p1->next = curr1;
            p1 = p1->next;
            curr1 = curr1->next;
        }
        else{
            p1->next = curr2;
            p1 = p1->next;
            curr2 = curr2->next;
        }
    }

    if(curr1 == NULL)
        p1->next = curr2;
    else
        p1->next = curr1;

    printLL(head1);

}

int main(){
    Node* node1 = new Node(1);
    Node* head1 = node1;

    Node* node2 = new Node(4);
    node1->next = node2;

    Node* node3 = new Node(5);
    node2->next = node3;

    printLL(head1);
    
    Node* node_1 = new Node(2);
    Node* head2 = node_1;

    Node* node_2 = new Node(3);
    node_1->next = node_2;

    Node* node_3 = new Node(6);
    node_2->next = node_3;

    printLL(head2);

    if(head1->data > head2->data){
        mergeLL(head2, head1);
    }
    else{
        mergeLL(head1, head2);
    }

    

    return 0;
}