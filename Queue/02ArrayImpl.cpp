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
    bool empty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data){
        if(rear == size){
            cout<<"cannot enqueue as queue is full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){
        if(front == rear){
            return -1;
        }

        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int frontEle(){
        if(front == rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int backEle(){
        if(front == rear){
            return -1;
        }
        else{
            return arr[rear-1];
        }
    }
    
};

int main(){
    Queue q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    // q1.enqueue(60);


    bool ans = q1.empty();
    cout<<ans<<endl;

    int backans = q1.backEle();
    cout<<backans<<endl;

    return 0;
}