//circular queue implementation
#include<iostream>
using namespace std;

class CircularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(){
        size = 5;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int data){
        //case 1
        if((front == 0 && rear == size-1) || (rear == (front-1) % (size-1))){
            cout<<"queue is full"<<endl;
            return;
        }
        //case 2
        else if(rear == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        //case 3
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    int dequeue(){
        if(front == -1){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        else if(front == rear){
            int ans = arr[front];
            front = rear = -1;
            return ans;
        }
        else if(front == size-1){
            int ans = arr[front];
            front = 0;
            return ans;
        }
        else{
            int ans = arr[front];
            front++;
            return ans;
        }
    }


};

int main(){
    CircularQueue q1;
    // q1.enqueue(10);
    // q1.enqueue(20);
    // q1.enqueue(30);
    // q1.enqueue(40);
    // q1.enqueue(50);
    
    q1.dequeue();
    


    return 0;
}