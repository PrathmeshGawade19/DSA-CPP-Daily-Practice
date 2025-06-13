// reverse first k elements of queue

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k=3;

    int n = q.size();
    stack<int> s;
    int i=0;
    while(i<k){
        int value = q.front();
        q.pop();
        s.push(value);
        i++;
    }

    while(!s.empty()){
        int value = s.top();
        s.pop();
        q.push(value);
    }

    i=0;
    while(i < n-k){
        int value = q.front();
        q.pop();
        q.push(value);
        i++;
    }

    //print
    while(!q.empty()){
        int value = q.front();
        q.pop();
        cout<<value<<" ";
    }

    return 0;
}