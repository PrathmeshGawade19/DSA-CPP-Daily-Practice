//to reverse stack using recursion
#include<iostream>
#include<stack>
using namespace std;

void insertBottom(stack<int>& s, int x){
    //base case
    if(s.empty() == true){
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();

    insertBottom(s, x);

    s.push(temp);
}

void reverseStack(stack<int>& s){
    //base case
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();

    reverseStack(s);
    
    insertBottom(s, temp);
}

int main(){
    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(7);
    s.push(9);

    reverseStack(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}