//to sort stack
#include<iostream>
#include<stack>
using namespace std;

void sortInsert(stack<int>& s, int temp){
    //base case
    if(s.empty() || s.top()<temp){
        s.push(temp);
        return;
    }

    int x = s.top();
    s.pop();

    sortInsert(s, temp);
    s.push(x);
}

void sortStack(stack<int>& s){
    //base case
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();

    sortStack(s);

    sortInsert(s, temp);
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sortStack(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}