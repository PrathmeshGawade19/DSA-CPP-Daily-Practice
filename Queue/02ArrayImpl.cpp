//array implementation of queue

#include<iostream>
using namespace std;

class Queue{
    public:
    //data members
    int *arr;
    int front;
    int rear;
    int size;

    //constructor
    Queue(){
        size = 5;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    //methods
    //push operation
    void enqueue(int data){
        if(rear == size){
            cout<<"cannot enqueue as queue is full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    //pop operation
    void dequeue(){
        if(front == rear){
            cout<<"the queue is empty"<<endl;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            cout<<"the ele dequed is : "<<ans<<endl;
        }
    }

    //empty or not
    void empty(){
        if(front == rear){
            cout<<"queue is empty"<<endl;
        }
        else{
            cout<<"queue is non-empty"<<endl;
        }
    }

    //full or not
    void full(){
        if(rear == size){
            cout<<"queue is full"<<endl;
        }
        else{
            cout<<"queue is not full"<<endl;
        }
    }

    //front ele of queue
    int frontEle(){
        if(front == rear){
            cout<<"no front ele as queue is empty"<<endl;
        }
        else{
            cout<<"front ele of queue is :"<<arr[front]<<endl;
        }
    }

    //back ele of queue
    int backEle(){
        if(front == rear){
            cout<<"no back ele as queue is empty"<<endl;
        }
        else{
            cout<<"front ele of queue is :"<<arr[rear-1]<<endl;
        }
    }
  
};

int main(){
    Queue q1;

    q1.enqueue(5);
    q1.enqueue(3);
    q1.enqueue(2);
    q1.enqueue(1);
    q1.enqueue(4);

    q1.empty();
    q1.full();
    q1.frontEle();
    q1.backEle();

    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();

    q1.empty();
    q1.full();
    q1.frontEle();
    q1.backEle();
    
    return 0;
}
