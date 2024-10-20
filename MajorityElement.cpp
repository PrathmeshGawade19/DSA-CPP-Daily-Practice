//Majority element brute force approach - O(n^2)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //boyer moore voting algorithm - O(n)
        int candidate=0,count=0;
        
        for(int i:nums){
            if(count==0){
                candidate=i;
            }

            if(candidate==i){
                count++;
            }
            else{
                count--;
            }
        }

        return candidate;
    }
};

int main(){
    vector<int> nums={3,2,3};

    Solution sol;
    int ans=sol.majorityElement(nums);
    cout<<"majority element in given vector is : "<<ans;

    return 0;
}