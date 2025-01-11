//circular linked list
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

//insertion
void insertNode(Node* &tail, int element, int data){
    //empty list
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        //element found - curr is representing element wala node
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void PrintCLL(Node* &tail){
    //empty list
    if(tail == NULL){
        cout<<"list is empty can not print"<<endl;
        return;
    }

    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

void deleteNode(Node* &tail, int value){
    //empty list
    if(tail == NULL){
        cout<<"list is empty please check again"<<endl;
        return;
    }
    else{
        //non empty
        //assuming that the value is present in the linked list
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        //1 node linked list
        if(curr == prev){
            tail = NULL;
        }

        //>=2 linke list
        if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main(){
    Node* tail = NULL;
   insertNode(tail, 5, 3);
    PrintCLL(tail);

    insertNode(tail, 3, 5);
    PrintCLL(tail);
 
    insertNode(tail, 5, 7);
    PrintCLL(tail);

    insertNode(tail, 7, 9);
    PrintCLL(tail);

    insertNode(tail, 3, 10);
    PrintCLL(tail);

    deleteNode(tail, 3);
    PrintCLL(tail);


    return 0;
}