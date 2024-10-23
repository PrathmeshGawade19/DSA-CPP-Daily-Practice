//program to rotate array
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

#include<iostream>
using namespace std;

void printarray(int arr[],int arrsize);

int main(){
    int arr1[]={1,7,9,11}; //{9,11,1,7}
    int k=2;
    int arrsize=sizeof(arr1)/sizeof(int);

    //approach 1
    int arr2[arrsize];
    for(int i=0; i<arrsize; i++){
        arr2[(i+k)%arrsize]=arr1[i];
    }
    
    //approach 2
    // k = k % nums.size();
    // reverse(nums.begin() + nums.size() - k, nums.end());
    // reverse(nums.begin(), nums.begin() + nums.size() - k);
    // reverse(nums.begin(), nums.end());

    printarray(arr2,arrsize);

    return 0;
}

void printarray(int arr[],int arrsize){
    for(int i=0; i<arrsize; i++){
        cout<<arr[i]<<"\t";
    }
}