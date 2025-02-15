//implementation of stack without using stl 

//array implementation of stack

#include<iostream>
using namespace std;
/*
class Stack{
    public:
    int *arr;
    int top;
    int size;

    //constructor
    Stack(int size){
        this->size = size;
        arr = new int[size];
        this->top = -1; //because indexing in array starts from 0
    }

    //push operation
    void push(int ele){
        //means atleast one positon is empty to push new element
        if(top < size - 1){
            top++; 
            arr[top] = ele; 
            cout<<"succesfully pushed element : "<<ele<<endl;
        }
        else{
            cout<<"stack overflow occurred!!!"<<endl;
        }
    }

    //pop operation
    void pop(){
        if(top == -1){
            cout<<"stack underflow occured!!!"<<endl;
        }
        else{
            cout<<"popped element: " << arr[top] << endl;
            top--;
        }
    }

    //top or peek element
    void peek(){
        if(top >= 0){
            cout<<"top element of stack is : "<<arr[top]<<endl;
        }
        else{
            cout<<"stack is empty"<<endl;
        }  
    }

    //stack empty or not
    void isempty(){
        if(top >= 0){
            cout<<"stack is non-empty"<<endl;
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }

    //destructor
    ~Stack(){
        delete[] arr;
    }
};

int main(){
    Stack s(5);
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.pop();
    s.pop();
    s.pop();
    // s.pop();
    // s.pop();

    s.peek();

    s.isempty();


    return 0;
}
*/

//linked list implementation of stack
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    public:
    Node* top;

    Stack(){
        this->top = NULL;
    }

    //push
    void push(int data){
        Node* new_node = new Node(data);

        if(!new_node){
            cout<<"stack overflow occured!!!";
        }

        new_node->next = top;

        top = new_node;
    }

    //pop
    void pop(){
        if(top==NULL){
            cout<<"stack underflow occured!!!";
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    //peek
    int peek() {
        if (top!=NULL)
            return top->data;
        else {
            cout << "\nStack is empty";
            return INT32_MIN;
        }
    }

    //empty
    void isEmpty(){
        if(top==NULL){
            cout<<"stack is empty";
        }
        else{
            cout<<"stack is not empty";
        }
    }
};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();

    int ans = s.peek();
    cout<<"peek element is "<<ans<<endl;

    s.isEmpty();

    return 0;
}
