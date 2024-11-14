//fibonacci series 0 1 1 2 3 5 8 13 21 34 ......
//next number is sum of previous two numbers

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        //base case
        if(n==0)
            return 0;

        if(n==1)
            return 1;
        
        //recusive relation
        return fib(n-1)+fib(n-2);
    }
};

int main(){
    Solution sol;
    cout<<sol.fib(3);

    return 0;
}