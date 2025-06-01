//Doubly Ended Queue 
//Here push and pop operation can be done through front and rear both

#include<iostream>
using namespace std;

class doublyEndedQueue{
    public:
    int front;
    int rear;
    int size;
    int *arr;

    doublyEndedQueue(){
        size = 5;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    int isEmpty(){
        if(front == -1){
            return 1;
        }
        else{
            return 0;
        }
    }

    int isFull(){
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size))){
            return 1;
        }
        else{
            return 0;
        }
    }

    void push_front(int data){
        if(isFull() == 1){
            cout<<"queue is full"<<endl;
            return;
        } 
        else if(rear == -1){
            front = rear = 0;
            arr[front] = data;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
            arr[front] = data;
        }
        else{
            front--;
            arr[front] = data;
        }
    }

    void push_rear(int data){
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

    int pop_front(){
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

    int pop_rear(){
        if(isEmpty() == 1){
            cout<<"queue is empty"<<endl;
            return -1;   
        }
        else if(front == rear){
            int ans = arr[rear];
            front = rear = -1;
            return ans;
        }
        else if(rear == 0){
            int ans = arr[rear];
            rear = size - 1;
            return ans;
        }
        else{
            int ans = arr[rear];
            rear--;
            return ans;
        }
    }

};

int main(){
    doublyEndedQueue q1;
    int ans = q1.isFull();
    cout<<ans<<endl;


    return 0;
}
