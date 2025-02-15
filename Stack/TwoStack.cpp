//two stacks in an array
#include<iostream>
using namespace std;

class Stack{
public:
    int *arr;
    int top1;
    int top2;
    int size;
    
    Stack(int size){
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
        arr = new int[size];
    }

    void push1(int data){
        if(top2-top1 > 1){
            top1++;
            arr[top1] = data;
            cout<<"pushed element "<<data<<" in array1"<<endl;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    void push2(int data){
        if(top2-top1 > 1){
            top2--;
            arr[top2] = data;
            cout<<"pushed element "<<data<<" in array2"<<endl;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    void pop1(){
        if(top1>=0){
            cout<<"popped element "<<arr[top1]<<endl;
            top1--;            
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }

    void pop2(){
        if(top2<=size-1){
            cout<<"popped element "<<arr[top2]<<endl;
            top2++;            
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }

    void peek1(){
        if(top1>=0){
            cout<<"peek element of stack1 is : "<<arr[top1]<<endl;
        }
        else{
            cout<<"stack1 is empty"<<endl;
        }
    }

    void peek2(){
        if(top2<=size-1){
            cout<<"peek element of stack1 is : "<<arr[top2]<<endl;
        }
        else{
            cout<<"stack2 is empty"<<endl;
        }
    }
};

int main(){
    Stack s(10);

    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    s.push1(50);
    s.push1(60);
    s.push1(70);
    s.push1(80);

    s.peek1();

    s.push2(90);
    s.push2(100);
    s.push2(110);

    s.peek2();

    s.pop1();
    s.peek1();

    s.pop2();
    s.peek2();

    return 0;
}