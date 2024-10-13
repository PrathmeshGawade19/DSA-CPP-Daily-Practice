//Book Allocation Problem or Split Array Largest Sum

#include<iostream>
using namespace std;

bool isPossible(int arr[], int arrsize, int nostudent, int mid);

int main(){
    int arr[]={1,2,3,4,5}; //array holding number of pages of each book
    int n=sizeof(arr)/sizeof(arr[0]); //number of books / array size
    int m=2; //number of students

    int s=0,e=0,ans;
    for(int i=0; i<n; i++){
        e=e+arr[i];
    }

    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossible(arr,n,m,mid)==true){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }

    cout<<"answer is :"<<ans<<endl;

    return 0;
}

bool isPossible(int arr[], int arrsize, int nostudent, int mid){  
    int pagesum=0;
    int studentcount=1;
    for(int i=0; i<arrsize; i++){
        if(pagesum+arr[i]<=mid){
            pagesum=pagesum+arr[i];
        }
        else{
            studentcount++;
            if(arr[i]>mid || studentcount>nostudent){
                return false;
            }
            pagesum=arr[i];
        }
    }
    return true;
}
