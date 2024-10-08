//Find duplicate elements in an array
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[]={4,3,2,7,8,2,3,1};
    int arrsize=sizeof(arr)/sizeof(arr[0]);

    //logic1 - TLE

    // sort(arr,arr+arrsize);
    // int visited[arrsize];

    // int flag=0;
    // for(int i=0; i<arrsize-1; i++){
    //     int count=0;

    //     if(visited[i]!=arr[i]){
    //         for(int j=0; j<arrsize; j++){
    //             if(arr[i]==arr[j]){
    //                 visited[j]=arr[i];
    //                 count++;
    //             }
    //         }
    //         cout<<"count of "<<arr[i]<<" is : "<<count<<endl;
    //         if(count>1){
    //             cout<<"count is 2 so "<<arr[i]<<" is duplicate element :) "<<endl;
    //             flag=1;
    //         } 
    //     }           
    // }
    // if(flag!=1){
    //     cout<<"no duplicate element present in array";
    // }

    // logic2
    // int ans=0;
    // for(int i=0; i<arrsize; i++){
    //     ans=ans^arr[i];
    // }

    // for(int i=0; i<arrsize; i++){
    //     ans=ans^i;
    // }
    // cout<<"duplicate is :"<<ans;
    // if(ans<1){
    //    cout<<"No duplicate element"; 
    // }

    //logic3
    sort(arr, arr + arrsize);

    bool duplicateFound = false;

    for(int i = 0; i < arrsize - 1; i++) {
        if(arr[i] == arr[i + 1]) {
            cout << "Duplicate element: " << arr[i] << endl;
            duplicateFound = true;
        }
    }

    if (!duplicateFound) {
        cout << "No duplicate elements found." << endl;
    }
}