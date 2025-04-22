//stl implementation of queue

#include<iostream>
#include<queue> //header file to be included
using namespace std;

void isEmpty(queue<int> q){
    if(q.empty()){
        cout<<"the queue is empty"<<endl;
    }
    else{
        cout<<"the queue is not empty"<<endl;
    }
}

int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout<<q.size()<<endl;

    isEmpty(q);

    cout<<"the front ele of the queue is : "<<q.front()<<endl;
    cout<<"the back ele of the queue is : "<<q.back()<<endl;

    q.pop();

    cout<<"the front ele of the queue is : "<<q.front()<<endl;
    cout<<"the back ele of the queue is : "<<q.back()<<endl;

    return 0;
}