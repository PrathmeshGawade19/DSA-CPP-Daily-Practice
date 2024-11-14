//count the ways to reach the nth stair

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        //base case
        if(n==0)
            return 1;

        if(n<0)
            return 0;
        
        //recusive relation
        return fib(n-1)+fib(n-2);
    }
};

int main(){
    Solution sol;
    cout<<sol.fib(3);

    return 0;
}