//Intersection of Arrays
//Type 1 Problem
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;

int main() {
    int arr1[] = {1,2,2,1};
    int arr2[] = {2,2};

    int arr1size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2size = sizeof(arr2) / sizeof(arr2[0]);

    // logic1
    // int maxIntersectionSize = min(arr1size, arr2size);
    // int* ans = new int[maxIntersectionSize];
    // int k = 0;

    // for (int i = 0; i < arr1size; i++) {
    //     for (int j = 0; j < arr2size; j++) {
    //         if (arr1[i] == arr2[j]) {
    //             ans[k++] = arr1[i]; 
    //             arr2[j]=-1;
    //             break; 
    //         }
    //     }
    // }

    // for (int i = 0; i < k; i++) {
    //     cout << ans[i] << endl;
    // }

    // delete[] ans; 

    //logic2
    sort(arr1,arr1+arr1size);
    sort(arr2,arr2+arr2size);

    int i=0,j=0;
    while(i<arr1size && j<arr2size){
        if(arr1[i]==arr2[j]){
            cout<<arr2[j]<<endl;
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }

    //Type 2 Problem
    
    // logic for - Given two integer arrays nums1 and nums2, return an array of their intersection.Each element in the result must be unique and you may return the result in any order.
    // Input: nums1 = [1,2,2,1], nums2 = [2,2] --> Output: [2]

    //uisng set
    // sort(arr1, arr1 + arr1size);
    // sort(arr2, arr2 + arr2size);

    // set<int> intersection; // To store unique intersecting elements
    // int i = 0, j = 0;

    // while (i < arr1size && j < arr2size) {
    //     if (arr1[i] == arr2[j]) {
    //         intersection.insert(arr1[i]); // Insert into the set
    //         i++;
    //         j++;
    //     }
    //     else if (arr1[i] < arr2[j]) {
    //         i++;
    //     }
    //     else {
    //         j++;
    //     }
    // }

    // // Print the unique intersecting elements
    // for (const int& i : intersection) {
    //     cout << i << " ";
    // }

    return 0;
}
