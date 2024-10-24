#include<iostream>
using namespace std;

void printarray(int arr[],int arrsize);

int main(){
    int arr[]={0};
    int n=sizeof(arr)/sizeof(arr[0]);

    //approach 1
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]==0 && arr[j]!=0){
                swap(arr[i],arr[j]);
                break;
            }
        }
    }

    //approach 2
    // int i,j;

    //     for(i=0,j=0; j<n; i++,j++){
    //         while(j<n && nums[j]==0){
    //             j++;
    //         }

    //         if(j>=n){
    //             break;
    //         }

    //         nums[i]=nums[j];
    //     }

    //     while(i<n){
    //         nums[i++]=0;
    //     }

    printarray(arr,n);

    return 0;
}

void printarray(int arr[],int arrsize){
    for(int i=0; i<arrsize; i++){
        cout<<arr[i]<<"\t";
    }
}