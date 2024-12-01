//three sum problem
/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int j=i+1,k=nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else if(sum==0){
                    vector<int> trip;
                    trip={nums[i],nums[j],nums[k]};
                    ans.push_back(trip);
                    j++,k--;
                    while(j<k &&  nums[j]==nums[j-1]){
                        j++;
                    }
                }
            } 
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    
    vector<vector<int>> ans;
    ans = sol.threeSum(nums);

    int r = ans.size();
    int c = ans[0].size();

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}