// Program to Count Pairs Whose Sum is Less than Target
#include<iostream>
using namespace std;
int main(){
    int arr[]={-6,2,5,-2,-7,-1,3};
    int target=-2;
    int arrsize=sizeof(arr)/sizeof(arr[0]);

    int count=0;
    for(int i=0; i<arrsize-1; i++){
        for(int j=i+1; j<arrsize; j++){
            if(arr[i] + arr[j] < target){
                cout<<"index pair ("<<i<<","<<j<<") satisfy the conditon"<<endl;
                count++;
            }
        }
    }

    cout<<"total count is :"<<count<<endl;

    return 0;
}


//vector implementation
// class Solution {
// public:
//     int countPairs(vector<int>& arr, int target) {
//     int count=0;
//     for(int i=0; i<arr.size()-1; i++){
//         for(int j=i+1; j<arr.size(); j++){
//             if(arr[i] + arr[j] < target){
//                 count++;
//             }
//         }
//     }

//     return count;
        
//     }
// };