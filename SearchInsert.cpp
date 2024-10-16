//Search Insert Problem
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={1,3,5,6};
    int arrsize=sizeof(arr)/sizeof(arr[0]);

    int search=7;

    sort(arr,arr+arrsize);

    int s=0,e=arrsize-1;
    int mid=s+(e-s)/2;
    while(s<=e){   
        if(arr[mid]==search){
            cout<<"element "<<search<<" found at index : "<<mid<<endl;
            break;
        }
        else if(arr[mid]<search){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }

        for(int i=0; i<arrsize; i++){
        if(search<arr[i]){
            cout<<"will put "<<search<<" at index : "<<i;
            break;
        } 
        }

    cout<<"will put "<<search<<" at index : "<<arrsize;

    return 0;
}