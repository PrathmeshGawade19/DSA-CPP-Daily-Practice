#include<iostream>
#include<stack> //header to include to use stl stack
using namespace std;

int main(){
    stack<int> s;
    //push operation
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    //top or peek operation
    cout<<"top or peek element of stack is : "<<s.top()<<endl;

    //pop operation
    s.pop();
    s.pop();

    //empty operation
    if(s.empty() == 0){
        cout<<"stack is not empty"<<endl;
    }
    else{
        cout<<"stack is empty"<<endl;
    }

    //size operation
    cout<<"size of stack is : "<<s.size()<<endl;


    return 0;
}