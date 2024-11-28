//two sum problem
//optimized approach with O(n) tc is using hashing 

/*Hashing is a process of converting data (like a key or value) into a fixed-size numerical representation, called a hash value or hash code, using a mathematical function known as a hash function. The hash value is used to efficiently store, retrieve, and manage data.
Hashing is like creating a "shortcut" to quickly find or store data in a table (called a hash table) instead of searching through everything.
Hashing makes lookups, insertions, and deletions very fast, typically O(1) on average.
In simple terms, hashing is a way to organize data for quick and efficient access, like assigning "addresses" to data using a mathematical function.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            int first = nums[i];
            int sec = target - first;
            if(m.find(sec)!=m.end()){
                ans.push_back(i);
                ans.push_back(m[sec]);
                break;
            }
        m[first]=i;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {3,2,4};
    int target = 6;
    vector<int>ans;
    ans = sol.twoSum(nums,target);

    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}