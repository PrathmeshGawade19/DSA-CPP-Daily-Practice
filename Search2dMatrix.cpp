#include<iostream>
#include<vector>
using namespace std;
class Solution {
    // private:
    //     bool bsinrow(vector<vector<int>>& arr,int target,int r,int c){
    //         int s=0,e=c-1;
    //         while(s<=e){
    //             int mid=s+(e-s)/2;
    //             if(arr[r][mid]==target){
    //                 return true;
    //             }
    //             else if(arr[r][mid]>target){
    //                 e=mid-1;
    //             }
    //             else{
    //                 s=mid+1;
    //             }
    //         }
    //         return false;
    //     }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //method 1
        // int r = matrix.size();
        // int c = matrix[0].size();

        // int s=0,e=r-1;
        // while(s<=e){
        //     int mid=s+(e-s)/2;
        //     if(target>=matrix[mid][0] && target<=matrix[mid][c-1]){
        //         return bsinrow(matrix,target,mid,c);
        //     }
        //     else if(target>=matrix[mid][c-1]){
        //         s=mid+1;
        //     }
        //     else{
        //         e=mid-1;
        //     }
        // }

        // return false;

        //method 2
        int rows = matrix.size();
        if (rows == 0)
            return false; // to handle empty matrix base case
        int cols = matrix[0].size();

        int left = 0;
        int right = rows * cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid / cols][mid % cols];

            if (mid_val == target) {
                return true;
            } else if (mid_val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> arr={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=30;

    cout<<sol.searchMatrix(arr,target);

    return 0;
}