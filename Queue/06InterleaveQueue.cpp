// Interleave the first half of queue with second half

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);

    int n = q.size();
    /*
    // approach 1 - using queue
    queue<int> newq;
    
    int i=0;
    while(i<n/2){
        int value = q.front();
        q.pop();
        newq.push(value);
        i++;
    }
 
    while(!newq.empty()){
        int value = newq.front();
        newq.pop();
        q.push(value);
        value = q.front();
        q.pop();
        q.push(value);
    }

    cout<<"size of q is : "<<q.size()<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
    */

    //approach 2 - using stack 
    stack<int> s;
    int i=0;
    while(i<n/2){
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
    while(i<n/2){
        int value = q.front();
        q.pop();
        q.push(value);
        i++;
    }

    i=0;
    while(i<n/2){
        int value = q.front();
        q.pop();
        s.push(value);
        i++;
    }

    while(!s.empty()){
        int value = s.top();
        s.pop();
        q.push(value);
        value = q.front();
        q.pop();
        q.push(value);
    }

    cout<<"size of q is : "<<q.size()<<endl;
    cout<<"the interleaved queue is as follows : ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

}
