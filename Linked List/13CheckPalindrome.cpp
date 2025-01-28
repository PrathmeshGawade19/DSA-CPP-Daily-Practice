//to check palindrome in LL

#include<iostream>
#include<vector>
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

void reverseLL(Node* &head, Node* headp){
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    headp->next = prev;
}

//approach 1 - SC : O(n) 
bool checkPalindrome1(Node* &head){
    Node* curr = head;
    //step 1 - create an array
    vector<int> vec;
    //step 2 - copy LL content into array
    while(curr != NULL){
        vec.push_back(curr->data);
        curr = curr->next;
    }
    //step 3 - apply logic to check palindrome or not for array
    int s = 0, e = vec.size()-1;
    while(s<=e){
        if(vec[s] != vec[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

//approach 2 - SC : o(1)
bool checkPalindrome2(Node* &head){
    //step 1 - find middle of LL
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    } 
    Node* middle = slow;

    //step 2 - reverse LL after middle
    reverseLL(middle->next, middle);

    //step 3 - compare both the halves
    Node* secLL = middle->next;
    Node* firstLL = head; 
    while(firstLL != middle->next && secLL != NULL){
        if(firstLL->data != secLL->data){
            return false;
        }

        firstLL = firstLL->next;
        secLL = secLL->next;
    }

    return true;
}

int main(){
    Node* head = new Node(1);

    Node* node2 = new Node(1);
    head->next = node2;

    Node* node3 = new Node(2);
    node2->next = node3;

    Node* node4 = new Node(1);
    node3->next = node4;

    // Node* node5 = new Node(2);
    // node4->next = node5;

    // Node* node6 = new Node(1);
    // node5->next = node6;

    printLL(head);

    // bool ans = checkPalindrome1(head);
    bool ans1 = checkPalindrome1(head);
    printLL(head);
    cout<<ans1<<endl;

    bool ans2 = checkPalindrome2(head);
    printLL(head);
    cout<<ans2<<endl;

    return 0;
}