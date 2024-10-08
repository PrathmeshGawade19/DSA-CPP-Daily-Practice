//Count of elements in array
#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    int arr[]={1, 2, 2, 0, 0, 5, 100};
    int arrsize=sizeof(arr)/sizeof(arr[0]);

    //logic1 without sorting
    // int visited[arrsize];

    // for(int i=0; i<arrsize; i++){
    //     int count=0;

    //     if(visited[i]!=arr[i]){
    //         for(int j=0; j<arrsize; j++){
    //             if(arr[i]==arr[j]){
    //                 visited[j]=arr[i];
    //                 count++;
    //             }
    //         }
    //         cout<<"count of "<<arr[i]<<" is : "<<count<<endl;
    //     }        
    // }

    //logic2 with sorting
    // sort(arr,arr+arrsize);
    // for(int i=0; i<arrsize; i++){
    //     int count=1;
    //     while(i<arrsize-1 && arr[i]==arr[i+1]){
    //         i++;
    //         count++;
    //     }
    //     cout<<arr[i]<<":"<<count<<endl;
    // }

    //logic3 using binary search
    //refer - First and Last Position of an element in sorted array
    //count of occurrence = (last index - first index) + 1

    return 0;
}