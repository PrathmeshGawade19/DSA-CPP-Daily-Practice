//implementation of stack without using stl 

//array implementation of stack
#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    //constructor
    Stack(int size){
        this->size = size;
        arr = new int[size];
        this->top = -1;
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

    void pop(){
        if(top == -1){
            cout<<"stack underflow occured!!!"<<endl;
        }
        else{
            cout<<"popped element: " << arr[top] << endl;;
            top--;
        }
    }

    void topele(){
        if(top >= 0){
            cout<<"top element of stack is : "<<arr[top]<<endl;
        }
        else{
            cout<<"stack is empty"<<endl;
        }  
    }

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
    s.pop();
    // s.pop();

    s.topele();

    s.isempty();


    return 0;
}