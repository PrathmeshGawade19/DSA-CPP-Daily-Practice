//Aggressive Cow or Magnetic force between two balls
#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int arr[],int arrsize,int k,int mid);
int main(){
    int arr[]={1,2,3,4,7}; //elements represent stall position number
    int arrsize=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    sort(arr,arr+arrsize);

    int s=1;
    int e=-1;
    for(int i=0; i<arrsize; i++){
        if(e<arr[i]){
            e=arr[i];
        }
    }

    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossible(arr,arrsize,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }

    cout << "Maximum minimum distance: " << ans << endl;

    return 0;
}

bool isPossible(int arr[],int arrsize,int k,int mid){
    int cowCount=1;
    int lastPos=arr[0];
    for(int i=1; i<arrsize; i++){
        if(arr[i]-lastPos>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastPos=arr[i];   
        }
    }
    return false;
}