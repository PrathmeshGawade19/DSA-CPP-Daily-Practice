// to implement queue using stack
#include<iostream>
#include<stack>
using namespace std;

//approach 1 - by making push operation costly
/*class myQueue{
    public:
    stack<int> s1, s2;

    void push(int x){
        while(!s1.empty()){
            int value = s1.top();
            s1.pop();
            s2.push(value);
        }

        s1.push(x);

        while(!s2.empty()){
            int value = s2.top();
            s2.pop();
            s1.push(value);
        }

        cout<<"the value is pushed in queue is : "<<x<<endl;
    }

    void pop(){
        if(s1.empty()){
            cout<<"queue is empty!!"<<endl;
        }
        else{
            int value = s1.top();
            s1.pop();
            cout<<"the value popped from queue is : "<<value<<endl;
        }
    }
};*/

//approach 2 - by making pop operation costly
class myQueue{
    public:
    stack<int> s1, s2;

    void push(int x){
        s1.push(x);
        cout<<"the value is pushed in queue is : "<<x<<endl;
    }

    void pop(){
        while(!s1.empty()){
            int value = s1.top();
            s1.pop();
            s2.push(value);
        }

        if(s2.empty()){
            cout<<"the queue is empty!!"<<endl;
        }
        else{
            int value = s2.top();
            s2.pop();

            while(!s2.empty()){
                int value = s2.top();
                s2.pop();
                s1.push(value);
            }

            cout<<"the value popped from queue is : "<<value<<endl;
        }    
    }
};

//approach 3 - using single stack and recursion
/*class myQueue{
    public:
    stack<int> s1, s2;

    void push(int x){
        s1.push(x);
        cout<<"the value is pushed in queue is : "<<x<<endl;
    }

    int queuePop(){
        if (s1.empty()) 
            return -1; // to check can we pop ele 

        int x = s1.top(); 
        s1.pop();

        if (s1.empty()) 
            return x; // base case

        int item = queuePop();  // recursive call

        s1.push(x); // pushing back other ele than last again

        return item; // returns to last ele in last for every backtrack   
    }
};*/


int main(){
    myQueue q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);

    q1.pop();
    q1.push(40);
    q1.pop();
    q1.pop();
    q1.pop();



    return 0;
}