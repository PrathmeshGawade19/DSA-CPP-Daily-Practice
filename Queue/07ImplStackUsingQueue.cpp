// to implement stack using queue 

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//approach - using two queues
//approach 1 - by making push() operation costly
//approach 2 - By making pop() operation costly
//approach 3 - by using single queue

/*class Stack{
    //approach 1 - by making push() operation costly
    public:
    queue<int> q1, q2;

    void push(int x){
        q2.push(x);

        while(!q1.empty()){
            int value = q1.front();
            q1.pop();
            q2.push(value);
        }

        //swap
        while(!q2.empty()){
            int value = q2.front();
            q2.pop();
            q1.push(value);
        }

        cout<<"following value pushed succesfully in stack : "<<x<<endl;
    }

    void pop(){
        if(q1.empty()){
            cout<<"stack is empty!!!"<<endl;
        }
        else{
            int value = q1.front();
            q1.pop();
            cout<<"the popped value from stack is : "<<value<<endl;
        }
    }

    void isEmpty(){
        if(q1.empty()){
            cout<<"stack is empty!!!"<<endl;
        }
        else{
            cout<<"stack is not empty"<<endl;
        }
    }
};*/

/*class Stack{
    //approach 2 - by making pop() operation costly
    public:
    queue<int> q1, q2;

    void push(int x){
        q1.push(x);
        cout<<"following value pushed succesfully in stack : "<<x<<endl;
    }

    void pop(){
        if(q1.empty()){
            cout<<"stack is empty!!!"<<endl;
        }
        else{
            int n = q1.size();

            int i=0;
            while(i<n-1){
                int value = q1.front();
                q1.pop();
                q2.push(value);
                i++;
            }

            int temp = q1.front();
            q1.pop();

            //swap
            while(!q2.empty()){
                int value = q2.front();
                q2.pop();
                q1.push(value);
            }

            cout<<"the popped value from stack is : "<<temp<<endl;
        }
    }

    void isEmpty(){
        if(q1.empty()){
            cout<<"stack is empty!!!"<<endl;
        }
        else{
            cout<<"stack is not empty"<<endl;
        }
    }
};*/

class Stack{
    //approach 3 - by using single queue
    public:
    queue<int> q1;

    void push(int x){
        int n = q1.size();
        q1.push(x);
        
        int i=0;
            while(i<n){
                int value = q1.front();
                q1.pop();
                q1.push(value);
                i++;
            }
        cout<<"following value pushed succesfully in stack : "<<x<<endl;
    }

    void pop(){
        if(q1.empty()){
            cout<<"stack is empty!!!"<<endl;
        }
        else{
            int value = q1.front();
            q1.pop();
            cout<<"the popped value from stack is : "<<value<<endl;
        }
    }

    void isEmpty(){
        if(q1.empty()){
            cout<<"stack is empty!!!"<<endl;
        }
        else{
            cout<<"stack is not empty"<<endl;
        }
    }
};


int main(){
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();


    return 0;
}