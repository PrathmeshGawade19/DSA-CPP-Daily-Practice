//Relative Array Sort
// Example 1:

// Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
// Output: [2,2,2,1,4,3,3,9,6,7,19]
// Example 2:

// Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
// Output: [22,28,8,6,17,44]

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>outputarr;
        for(int i=0; i<arr2.size(); i++){
            for(int j=0; j<arr1.size(); j++){
                if(arr2[i]==arr1[j]){
                    outputarr.push_back(arr1[j]);
                    arr1[j]=-1;
                }
            }
        }

        sort(arr1.begin(),arr1.end());
        for(int j=0; j<arr1.size(); j++){
            if(arr1[j]!=-1){
                   outputarr.push_back(arr1[j]); 
            }
        }

        return outputarr;
    }
};

int main(){
    vector<int> arr1={2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2={2,1,4,3,9,6};
    Solution sol1;
    vector<int> outputarr=sol1.relativeSortArray(arr1,arr2);

    for(int i:outputarr){
        cout<<i<<"\t";
    }

    return 0;
}