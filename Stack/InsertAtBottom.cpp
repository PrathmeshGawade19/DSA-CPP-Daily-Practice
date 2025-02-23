//insert an element at bottom in a given stack
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

int main(){
    int x = 100;
    stack<int> s;
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(5);

    insertBottom(s, x);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}