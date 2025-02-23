//to delete middle ele of the stack
#include<iostream>
#include<stack>
using namespace std;

void deleteMiddleEle(stack<int>& s, int size, int mid, int count){
    //base case
    if(count == mid){
        s.pop();
        return;
    }

    int x = s.top();
    s.pop();

    deleteMiddleEle(s, size, mid, ++count);
    s.push(x);
}

int main(){
    stack<int> s;
    s.push(3);
    s.push(5);
    s.push(9);
    s.push(2);
    s.push(4);
    
    int s_size = s.size();
    int mid = s_size / 2;
    int count = 0;

    deleteMiddleEle(s, s_size, mid, count);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}