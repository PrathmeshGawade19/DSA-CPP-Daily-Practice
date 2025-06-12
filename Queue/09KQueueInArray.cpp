// k queue in an single array
#include<iostream>
using namespace std;

class qQueue{
    public:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

    qQueue(int n, int k){
        this->k = k;
        this->n = n;
        freeSpot = 0;
        front = new int[k];
        rear = new int[k];
        arr = new int[n];
        next = new int[n];

        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
    }

    void enqueue(int x, int qn){
        if(freeSpot == -1){
            cout<<"no freespot present, Overflow reached!!"<<endl;
            return;
        }

        int index = freeSpot;
        freeSpot = next[index];

        if(front[qn-1] == -1){
            front[qn-1] = index;
        }
        else{
            next[rear[qn-1]] = index;
        }

        rear[qn-1] = index;
        next[index] = -1;
        arr[index] =  x;

        cout<<"the enqueue value is "<<x<<" in queue "<<qn<<endl;
    }

    void dequeue(int qn){
        if(front[qn-1] == -1){
            cout<<"the queue is empty, Underflow reached!!"<<endl;
            return;
        }

        int index = front[qn-1];

        front[qn-1] = next[index];

        next[index] = freeSpot;
        freeSpot = index;

        cout<<"the dequeue value is : "<<arr[index]<<endl;
    }
};

int main(){
    qQueue q(8, 3);

    q.enqueue(10, 1);
    q.enqueue(20, 1);
    q.enqueue(30, 2);
    q.enqueue(40, 1);
    
    q.dequeue(1);
    q.dequeue(1);
    q.dequeue(1);
    q.dequeue(2);


    
    return 0;
}