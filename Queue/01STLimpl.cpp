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

    //push operation from rear side (rear pointer) of queue and rear pointer gets incremented by 1
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout<<q.size()<<endl;

    isEmpty(q);

    cout<<"the front ele of the queue is : "<<q.front()<<endl;
    cout<<"the back ele of the queue is : "<<q.back()<<endl;

    //pop operation from front side (front pointer) of queue and front pointer gets incremented by 1
    q.pop();

    cout<<"the front ele of the queue is : "<<q.front()<<endl;
    cout<<"the back ele of the queue is : "<<q.back()<<endl;

    return 0;
}
