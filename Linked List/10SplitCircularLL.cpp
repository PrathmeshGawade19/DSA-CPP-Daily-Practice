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
    do{
        cout<<curr->data<<" ";
        curr = curr->next;
    }while(curr != head);
    cout<<endl;
}

int lengthLL(Node* &head){
    Node* curr = head;
    int count = 0;
    do{
        count++;
        curr = curr->next;
    }while(curr != head);
    return count;
}

Node* splitCircularLL(Node* &head, int len){
    Node* curr = head;
    if(len%2 == 0){
        //even
        int mid = (len / 2) - 1;
        int itr = 1;
        while(itr <= mid){
            curr = curr->next;
            itr++;
        }
        Node* secondHead = curr->next;
        curr->next = head;

        Node* curr2 = secondHead;
        while(curr2->next != head){
            curr2 = curr2->next;
        }
        curr2->next = secondHead;

        return secondHead;
    }
    else{
        //odd
        int mid = (len / 2);
        int itr = 1;
        while(itr <= mid){
            curr = curr->next;
            itr++;
        }
        Node* secondHead = curr->next;
        curr->next = head;

        Node* curr2 = secondHead;
        while(curr2->next != head){
            curr2 = curr2->next;
        }
        curr2->next = secondHead;

        return secondHead;
    }

}

int main(){
    //circular LL
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

    node6->next = head;

    printLL(head);
    int len = lengthLL(head);
    cout<<"length of circular LL is : "<<len<<endl;

    //split Circular LL
    Node* secondHead = splitCircularLL(head, len);
    cout<<"first list is : ";
    printLL(head);
    cout<<"second list is : ";
    printLL(secondHead);
    return 0;
}