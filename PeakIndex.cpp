//Peak Index in a Mountain array
#include<iostream>
using namespace std;
int main(){
    int arr[]={0,10,5,2};
    int arrsize=sizeof(arr)/sizeof(arr[0]);

    int s=0,e=arrsize-1;
    int mid=s+(e-s)/2;
    // cout<<mid;
    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
        cout<<"hello";
    }

    cout<<"peak index is : "<<s;

    return 0;
}