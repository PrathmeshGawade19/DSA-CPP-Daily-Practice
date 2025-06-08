// Gas Station Problem or also called Circular Tour Problem

#include<iostream>
#include<vector>
using namespace std;

// approach 3 - using concept of deficit calculation 

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int balance = 0;
        int start = 0;

        for(int i=0; i<gas.size(); i++){
            balance = balance + (gas[i] - cost[i]);
            if(balance < 0){
                start = i+1;
                deficit = deficit + balance;
                balance = 0;
            }
        }

        if(deficit + balance >= 0){
            return start;
        }
        else{
            return -1;
        }
    }
};

int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    Solution sol;
    int ans = sol.canCompleteCircuit(gas, cost);

    if(ans == -1){
        cout<<"can not travel around the circuit once in the clockwise direction this index is "<<ans<<endl;
    }
    else{
        cout<<"can travel around the circuit thus starting gas station's index "<<ans<<endl;
    }
    
    return 0;
}