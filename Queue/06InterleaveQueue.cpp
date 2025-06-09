// Interleave the first half of queue with second half

#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    int n = q.size();

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
}