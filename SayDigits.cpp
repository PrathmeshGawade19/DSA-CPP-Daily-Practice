//say digits
//example 412 - four one two

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void fib(int n) {
        //base case
        if(n==0)
            return;

        //processing
        vector<string> digmap = {"zero","one","two","three","four","five","six","seven","eight","nine"};
        int dig = n%10;
        // cout<<digmap[dig]<<" "; two one four 
        n=n/10;

        //recusive relation
        fib(n);

        cout<<digmap[dig]<<" "; //four one two
    }
};

int main(){
    Solution sol;
    sol.fib(412);

    return 0;
}