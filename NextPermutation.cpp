//next permutation problem
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        //finding pivot element in given array
        int piv=-1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                piv=i;
                break;
            }
        }
        //case where array has largest possible arrangement so we will reverse the whole array to make it lowest possible order
        if(piv==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        //swapping with the right most element for below condition
        for(int i=n-1; i>piv; i--){
            if(nums[i]>nums[piv]){
                swap(nums[i],nums[piv]);
                break;
            }
        }

        //reversing the elements aftere the pivot 
        int i=piv+1,j=n-1;
        while(i<=j){
            swap(nums[i],nums[j]);
                i++;
                j--;
        }
    }
};

int main(){
    vector<int> nums={1,2,3};

    Solution sol;
    //logic1
    sol.nextPermutation(nums);

    //logic2 
    //next_permutation(nums.begin(),nums.end());
    for(int i:nums){
        cout<<i<<"\t";
    }
    cout<<endl;

    return 0;
}