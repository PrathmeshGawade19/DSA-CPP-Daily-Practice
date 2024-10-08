//Binary Search 
//Time complexity - O(log n) linear
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={3,5,9,13,27};
    int search=2;
    int arrsize=sizeof(arr)/sizeof(arr[0]);

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

    if (s > e) {
        cout << "Element " << search << " not found." << endl;
    }

    return 0;
}