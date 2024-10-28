// Programt to get sum of max subarray of given array

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

    // brute force approach to find all possible subarrays O(n^3)
    //  for(int start=0; start<arr.size(); start++){
    //      for(int end=start; end<arr.size(); end++){
    //          for(int i=start; i<=end; i++){
    //              cout<<arr[i];
    //          }
    //          cout<<" ";
    //      }
    //      cout<<endl;
    //  }

    //Method 1 to get sum of max subarray
    //The O(n^3)code calculates the sum of each subarray from scratch with three nested loops.
    // int maxsum=INT32_MIN;
    // for (int start = 0; start < arr.size(); start++){
    //     for (int end = start; end < arr.size(); end++){
    //         int cursum=0;
    //         for(int i=start; i<=end; i++){
    //             cursum=cursum + arr[i];
    //         }
    //         maxsum=max(cursum,maxsum);
    //     }
    // }

    //Method 2 to get sum of max subarray
    //O(n^2) code, however, reuses the sum of previous elements in the subarray by adding the next element to cursum, which saves time by removing the need for the innermost loop.
    // int maxsum=INT32_MIN;
    // for (int start = 0; start < arr.size(); start++){
    //     int cursum=0;
    //     for (int end = start; end < arr.size(); end++){
    //         cursum=cursum + arr[end];
    //         maxsum=max(cursum,maxsum);
    //     }
    // }

    //Method 3 to get sum of max subarray
    //kadane alogrithm works in O(n) complexity
    int maxsum=INT32_MIN,cursum=0;;
    for (int i = 0; i < arr.size(); i++){
        cursum=cursum + arr[i];
        maxsum=max(cursum,maxsum);
        if(cursum<0){
            cursum=0;
        }
    }

    cout<<maxsum;

    return 0;
}