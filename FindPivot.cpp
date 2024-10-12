//Program to find pivot in rotated array
#include<iostream>
using namespace std;
int main(){
    int arr[]={3,8,10,17,1}; //rotated array
    int arrsize=sizeof(arr)/sizeof(arr[0]);

    int s=0,e=arrsize-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    cout<<"pivot element is :"<<arr[mid]<<" at index position : "<<mid;


    return 0;
}