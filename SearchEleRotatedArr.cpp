//program to search element in rotated array
#include<iostream>
using namespace std;

int BinarySearch(int arr[],int size,int key,int s,int e);

int main(){
    int arr[]={2,5,6,0,0,1,2}; //rotated array
    int arrsize=sizeof(arr)/sizeof(arr[0]);
    int key=3;

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
    
    int pivot=mid;
    bool keyindex;
    cout<<"pivot element is "<<arr[mid]<<" at index position "<<pivot<<endl;

    if(key>=arr[pivot] && key<=arr[arrsize-1]){
        keyindex=BinarySearch(arr,arrsize,key,pivot,arrsize-1);
    }
    else{
        keyindex=BinarySearch(arr,arrsize,key,0,pivot-1);
    }

    cout<<"element found at index position : "<<keyindex<<endl;

    return 0;
}

int BinarySearch(int arr[],int size,int key,int s,int e){
    int mid=s+(e-s)/2;
    while(s<=e){   
        if(arr[mid]==key){
            return true;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }

    return false;
}