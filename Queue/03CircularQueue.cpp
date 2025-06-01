//implementation circular queue 
#include<iostream>
using namespace std;

class CircularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    //constructor
    CircularQueue(){
        size = 5;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    //push operation in circular queue
    void enqueue(int data){
        //case 1 - queue if full 
        if((front == 0 && rear == size-1) || (rear == (front-1) % (size-1))){
            cout<<"queue is full"<<endl;
            return;
        }
        //case 2 - initial push
        else if(rear == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        //case 3 - circular wrap around 
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }
        else{ // normal case first increment rear and then push data
            rear++;
            arr[rear] = data;
        }
    }

    void dequeue(){
        if(front == -1){ // check empty or not before pop operation
            cout<<"queue is empty"<<endl;
        }
        else if(front == rear){ //single element pop operation
            int ans = arr[front];
            cout<<"the dequeued ele is : "<<ans<<endl;
            front = rear = -1;
        }
        else if(front == size-1){ //circular wrap around of front
            int ans = arr[front];
            cout<<"the dequeued ele is : "<<ans<<endl;
            front = 0;
        }
        else{ // normal case pop ele and then increment front
            int ans = arr[front]; 
            front++;
            cout<<"the dequeued ele is : "<<ans<<endl;
        }
    }


};

int main(){
    CircularQueue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();

    q1.enqueue(60);

    q1.dequeue();
    q1.dequeue();

    q1.dequeue();
    


    return 0;
}
