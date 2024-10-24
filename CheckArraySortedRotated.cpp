//program to check array is sorted and rotated
// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
// Example 2:

// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.
// Example 3:

// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is the original sorted array.
// You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

#include<iostream>
using namespace std;

void printarray(int arr[],int arrsize);

int main(){
    int nums[]={3,4,5,1,2};
    int numssize=sizeof(nums)/sizeof(nums[0]);

    //we observe that in sorted and rotated array nums[i-1]>nums[i] count is maximum 1 not more than that.
    //whereas random array has count more than 1
    int count=0;
        for(int i=1; i<numssize; i++){
            if(nums[i-1]>nums[i]){
                count++;
            }
        }

        if(nums[numssize-1]>nums[0]){ //important
            count++;
        }
        
        if(count==0 || count==1){
            cout<<"true";
        }
        else{
            cout<<"false";
        }

    return 0;
}