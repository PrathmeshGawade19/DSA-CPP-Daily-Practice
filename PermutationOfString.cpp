/*Given an array nums of distinct integers, return all the possible 
permutations
. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
        void solve(vector<int> nums, int index, vector<vector<int>>& ans){
            //base case
            if(index>=nums.size()){
                ans.push_back(nums);
                return;
            }

            for(int j=index; j<nums.size(); j++){
                swap(nums[index],nums[j]);
                solve(nums, index+1, ans);
                swap(nums[index],nums[j]); //here backtracking is imp
            }
        }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0;
        vector<vector<int>> ans;
        solve(nums, index, ans);
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution sol;
    vector<vector<int>> ans = sol.permute(nums);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}