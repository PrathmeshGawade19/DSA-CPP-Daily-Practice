//First and Last Position of an element in sorted array
#include<iostream>
#include<algorithm>
using namespace std;

int BinarySearchFirstOccurrence(int arr[], int arrsize, int key) {
    int s = 0, e = arrsize - 1;
    int mid = s + (e - s) / 2;
    int result = -1;
    
    while (s <= e) {
        if (arr[mid] == key) {
            result = mid;
            e = mid - 1; 
        } 
        else if (arr[mid] < key) {
            s = mid + 1;
        } 
        else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return result;
}

int BinarySearchLastOccurrence(int arr[], int arrsize, int key) {
    int s = 0, e = arrsize - 1;
    int mid = s + (e - s) / 2;
    int result = -1; 
    
    while (s <= e) {
        if (arr[mid] == key) {
            result = mid; 
            s = mid + 1; 
        } 
        else if (arr[mid] < key) {
            s = mid + 1;
        } 
        else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return result;
}

int main() {
    int arr[] = {5, 7, 7, 8, 8, 10};
    int arrsize = sizeof(arr) / sizeof(arr[0]);
    
    sort(arr, arr + arrsize);
    int key = 8;

    int firstOccur = BinarySearchFirstOccurrence(arr, arrsize, key);
    int lastOccur = BinarySearchLastOccurrence(arr, arrsize, key);

    cout << "First occurrence of " << key << ": " << firstOccur << endl;
    cout << "Last occurrence of " << key << ": " << lastOccur << endl;

    return 0;
}

//In vectors
// #include<iostream>
// #include<vector>
// using namespace std;

// class Solution {
// public:
//     // Function to find the first occurrence of the target
//     int findFirst(vector<int>& nums, int target) {
//         int s = 0, e = nums.size() - 1;
//         int mid, result = -1;
        
//         while (s <= e) {
//             mid = s + (e - s) / 2;
//             if (nums[mid] == target) {
//                 result = mid;  // Record the index
//                 e = mid - 1;   // Move left to find the first occurrence
//             }
//             else if (nums[mid] < target) {
//                 s = mid + 1;
//             }
//             else {
//                 e = mid - 1;
//             }
//         }
//         return result;
//     }

//     // Function to find the last occurrence of the target
//     int findLast(vector<int>& nums, int target) {
//         int s = 0, e = nums.size() - 1;
//         int mid, result = -1;
        
//         while (s <= e) {
//             mid = s + (e - s) / 2;
//             if (nums[mid] == target) {
//                 result = mid;  // Record the index
//                 s = mid + 1;   // Move right to find the last occurrence
//             }
//             else if (nums[mid] < target) {
//                 s = mid + 1;
//             }
//             else {
//                 e = mid - 1;
//             }
//         }
//         return result;
//     }

//     // Main function to find the range of the target
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int> result(2, -1);  // Initialize the result as [-1, -1]

//         // Get the first and last occurrence of the target
//         result[0] = findFirst(nums, target);
//         result[1] = findLast(nums, target);

//         return result;
//     }
// };
