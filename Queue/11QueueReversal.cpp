// queue reversal

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//approach 1 - using stack
/*int main(){
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    stack<int> s;
    while(!q.empty()){
        int value = q.front();
        q.pop();
        s.push(value);
    }

    while(!s.empty()){
        int value = s.top();
        s.pop();
        q.push(value);
    }

    while(!q.empty()){
        int value = q.front();
        q.pop();
        cout<<value<<" ";
    }


    return 0;
}*/

//approach 2 - using recursion

queue<int> reverseQueue(queue<int> q){
    //base case
    if(q.empty()){
        return q;
    }
    
    int value = q.front();
    q.pop();

    //rr
    queue<int> ansQueue = reverseQueue(q); 

    ansQueue.push(value);

    return ansQueue;
}

int main(){
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    
   queue<int> ans = reverseQueue(q);

   while(!ans.empty()){
    int value = ans.front();
    ans.pop();
    cout<<value<<" ";
   }


    return 0;
}