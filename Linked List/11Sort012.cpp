//sort 0s 1s 2s in linked list
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

int lengthLL(Node* &head){
    Node* curr = head;
    int count = 0;
    do{
        count++;
        curr = curr->next;
    }while(curr != head);
    return count;
}

//with replacement
void sort012(Node* &head){
    Node* curr = head;
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    while(curr != NULL){
        if(curr->data == 0){
            zeroCount++;
        }
        else if(curr->data == 1){
            oneCount++;
        }
        else if(curr->data == 2){
            twoCount++;
        }
        curr = curr->next;
    }

    curr = head;
    while(curr != NULL){
        if(zeroCount > 0){
            curr->data = 0;
            curr = curr->next;
            zeroCount--;
        }
        else if(oneCount > 0){
            curr->data = 1;
            curr = curr->next;
            oneCount--;
        }
        else if(twoCount > 0){
            curr->data = 2;
            curr = curr->next;
            twoCount--;
        }  
    }
}

//without replacement
void sortWithoutR012(Node* &head){
    //create separate linked list for 0 1 2 with dummy node
    Node* curr = head;

    Node* zeroDummy = new Node(-1);
    Node* zeroHead = zeroDummy;
    Node* zeroHeadCurr = zeroDummy;
    Node* oneDummy = new Node(-1);
    Node* oneHead = oneDummy;
    Node* oneHeadCurr = oneDummy;
    Node* twoDummy = new Node(-1);
    Node* twoHead = twoDummy;
    Node* twoHeadCurr = twoDummy;

    while(curr != NULL){
        Node* temp = curr;
        if(temp->data == 0){
            curr = curr->next;
            head = curr;
            temp->next = NULL;
            zeroHeadCurr->next = temp;
            zeroHeadCurr = zeroHeadCurr->next;
        }
        else if(temp->data == 1){
            curr = curr->next;
            head = curr;
            temp->next = NULL;
            oneHeadCurr->next = temp;
            oneHeadCurr = oneHeadCurr->next;
        }
        else if(temp->data == 2){
            curr = curr->next;
            head = curr;
            temp->next = NULL;
            twoHeadCurr->next = temp;
            twoHeadCurr = twoHeadCurr->next;
        }
    }

    printLL(zeroHead);
    printLL(oneHead);
    printLL(twoHead);

    //merge
    zeroHeadCurr->next = oneHead->next;
    oneHeadCurr->next = twoHead->next;
    head = zeroHead->next;

    printLL(head);
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    Node* node2 = new Node(0);
    node1->next = node2;

    Node* node3 = new Node(2);
    node2->next = node3;

    Node* node4 = new Node(1);
    node3->next = node4;

    Node* node5 = new Node(2);
    node4->next = node5;

    printLL(head);
    // sort012(head);
    sortWithoutR012(head);
    // printLL(head);
    

    return 0;
}