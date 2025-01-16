//detect loop, remove loop and find start node of loop in LL 

#include<iostream>
#include<map>
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

//using map
bool detect1(Node* &head){
    if(head == NULL){
        return false;
    }

    map<Node*, bool> visited;
    Node* curr = head;
    while(curr != NULL){
        if(visited[curr] == true){
            return true;
        }

        visited[curr] = true;
        curr = curr->next;
    }
    return false;
}

//using floyds cycle detection algo
bool detect2(Node* &head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL || fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            return true;
        }
    }
    return false;
}

//start node of loop in LL
Node* startNodeInLoop(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL || fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){

            slow = head;

            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }

            return fast;
        }
    }
}

void removeLoop(Node* &head){
    Node* startNode = startNodeInLoop(head);
    Node* curr = startNode;
    while(curr->next != startNode){
        curr = curr->next;
    }
    curr->next = NULL;
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

    node5->next = node3;

    // PrintLL(head);

    bool ans1 = detect1(head);
    cout<<"loop present ? "<<ans1;
    cout<<endl;

    bool ans2 = detect2(head);
    cout<<"loop present ? "<<ans2;
    cout<<endl;

    Node* startNode = startNodeInLoop(head);
    cout<<"start node of the loop in linked list is : "<<startNode->data<<endl;

    removeLoop(head);
    bool ans3 = detect1(head);
    cout<<"loop present ? "<<ans3;
    cout<<endl;

    return 0;
}